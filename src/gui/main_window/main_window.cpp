#include "main_window.h"
#include "ui_main_window.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->stackedWidget->addWidget(&screen_game);
  ui->stackedWidget->addWidget(&screen_menu);
  ui->stackedWidget->addWidget(&screen_settings);
  ui->stackedWidget->addWidget(&screen_liderboard);
  ui->stackedWidget->setCurrentIndex(Windows::MENU);

  sendToGuiBoardData();

  connect(&screen_game, SIGNAL(changeWindow(int)), this,
          SLOT(windowsManager(int)));
  connect(&screen_menu, SIGNAL(changeWindow(int)), this,
          SLOT(windowsManager(int)));
  connect(&screen_settings, SIGNAL(changeWindow(int)), this,
          SLOT(windowsManager(int)));
  connect(&screen_liderboard, SIGNAL(changeWindow(int)), this,
          SLOT(windowsManager(int)));
  connect(&screen_game, SIGNAL(figureMovedBoard(Position, Position)), this,
          SLOT(connectGuiMoveWithEngine(Position, Position)));
  connect(this, SIGNAL(sendDataToGui(QVector<QVector<Figures>>, double, bool)),
          &screen_game, SLOT(catchData(QVector<QVector<Figures>>, double, bool)));
  connect(&screen_game, SIGNAL(newGameFromGame()), this, SLOT(startNewGame()));
  connect(&screen_menu, SIGNAL(newGameFromMenu()), this, SLOT(startNewGame()));
  connect(this, SIGNAL(hilightGuiAttacks(std::list<std::list<Position>>)), &screen_game, SLOT(hilightAttacks(std::list<std::list<Position>>)));
  connect(this, SIGNAL(hilightGuiMoves(std::list<std::list<Position>>)), &screen_game, SLOT(hilightMoves(std::list<std::list<Position>>)));
  connect(&screen_game, SIGNAL(pressGuiFigure(Position)), this, SLOT(guiPressFigure(Position)));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::windowsManager(int window_id) {
  if (window_id == Windows::EXIT)
    this->close();
  ui->stackedWidget->setCurrentIndex(window_id);
}

void MainWindow::connectGuiMoveWithEngine(Position from_board,
                                          Position delta_board) {
  engine.move(from_board, delta_board);
  sendToGuiBoardData();
}

void MainWindow::sendToGuiBoardData(bool is_new_game) {
  double advantage_white = engine.calculateAdvantageWhite();
  std::vector<std::vector<Figure *>> data = engine.getData();
  QVector<QVector<Figures>> data_for_gui(data.size(),
                                         QVector<Figures>(data.size()));
  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      if (data[i][j] == nullptr)
        data_for_gui[i][j] = NONE;
      else
        data_for_gui[i][j] = data[i][j]->getTypeFigure();
    }
  }
  emit sendDataToGui(data_for_gui, advantage_white, is_new_game);
}

void MainWindow::startNewGame() {
  engine.clearBoard();
  engine.setStartingArrangement();
  sendToGuiBoardData(true);
}

void MainWindow::guiPressFigure(Position position) {
  std::list<std::list<Position>> attacks = engine.getPosibleAttacksFigureFrom(position);
  std::list<std::list<Position>> moves = engine.getPosibleMovesFigureFrom(position);
  emit hilightGuiAttacks(attacks);
  emit hilightGuiMoves(moves);
}
