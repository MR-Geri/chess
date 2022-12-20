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

  QList<Party> parties = storage_liderboard.getData();
  for (auto party : parties) screen_liderboard.addNewRecord(party);

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
          &screen_game,
          SLOT(catchData(QVector<QVector<Figures>>, double, bool)));
  connect(&screen_game, SIGNAL(newGameFromGame()), this, SLOT(startNewGame()));
  connect(&screen_menu, SIGNAL(newGameFromMenu()), this, SLOT(startNewGame()));
  connect(this,
          SIGNAL(highlightGuiAttacksForMousePress(
              std::list<std::pair<Position, Figures>>)),
          &screen_game,
          SLOT(highlightAttacksWhisRedrawing(
              std::list<std::pair<Position, Figures>>)));
  connect(this,
          SIGNAL(highlightGuiAttacks(std::list<std::pair<Position, Figures>>)),
          &screen_game,
          SLOT(highlightAttacks(std::list<std::pair<Position, Figures>>)));
  connect(this, SIGNAL(highlightGuiMoves(std::list<std::list<Position>>)),
          &screen_game, SLOT(highlightMoves(std::list<std::list<Position>>)));
  connect(&screen_game, SIGNAL(pressGuiFigure(Position)), this,
          SLOT(guiPressFigure(Position)));
  connect(&screen_game, SIGNAL(mousePressGuiFigure(Position)), this,
          SLOT(guiMousePressFigure(Position)));
  connect(this, SIGNAL(endParty(Party)), &screen_liderboard, SLOT(addNewRecord(Party)));
  connect(this, SIGNAL(endParty(Party)), &storage_liderboard, SLOT(addRecord(Party)));
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
  bool isEnd = engine.isEnd() != 0 ? true : false;
  if (isEnd) {
    endGame(engine.isEnd() == 1 ? false : true);
    return;
  }
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
  engine.setStartingArrangement();
  engine.current_color = WHITE;
  sendToGuiBoardData(true);
}

void MainWindow::guiPressFigure(Position position) {
  std::list<std::pair<Position, Figures>> attacks =
      engine.getPosibleAttacksFigureFrom(position);
  std::list<std::list<Position>> moves =
      engine.getPosibleMovesFigureFrom(position);
  emit highlightGuiAttacks(attacks);
  emit highlightGuiMoves(moves);
}

void MainWindow::guiMousePressFigure(Position position) {
  std::list<std::pair<Position, Figures>> attacks =
      engine.getPosibleAttacksFigureFrom(position);
  emit highlightGuiAttacksForMousePress(attacks);
}

void MainWindow::endGame(bool is_white_win) {
  QString first_player_name;
  QString second_player_name;
  QString message =
      QString(is_white_win ? "White" : "Black") + QString(" WIN!!!");
  bool ok;
  QString text = QInputDialog::getText(
      this, message,
      tr("Введите никнеймы через дефис, слева белый, справа чёрный игроки: "),
      QLineEdit::Normal, tr(""), &ok);
  if (ok && !text.isEmpty() && text.indexOf('-') != -1) {
    first_player_name = text.section('-', 0, 0).trimmed();
    second_player_name = text.section('-', 1, 1).trimmed();
    Party party;
    party.players.first = first_player_name;
    party.players.second = second_player_name;
    party.id_player_win = is_white_win ? 1 : 2;
    emit endParty(party);
  }
  if (!first_player_name.isEmpty() && !second_player_name.isEmpty()) {
    std::cout << first_player_name.toStdString() << " "
              << second_player_name.toStdString();
  }
  windowsManager(Windows::MENU);
}
