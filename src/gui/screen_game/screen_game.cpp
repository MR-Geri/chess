#include "screen_game.h"
#include "ui_screen_game.h"
#include <iostream>

ScreenGame::ScreenGame(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenGame) {
  ui->setupUi(this);

  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setAlignment(Qt::AlignCenter);

  ui->graphicsView->setMinimumHeight(500);
  ui->graphicsView->setMinimumWidth(500);

  indent = 15;
  first_advantage_white = 0.5;
  second_advantage_white = 0.5;
  size_cell_board = 0;

  timer = new QTimeLine(500);
  scene = new GuiScene();
  animation_black = new QGraphicsItemAnimation();
  animation_black->setTimeLine(timer);

  timer->setFrameRange(0, 100);

  ui->graphicsView->setScene(this->scene);

  data = QVector<QVector<Figures>>(8, QVector<Figures>(8, Figures::NONE));

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(buttonNewGameReleased()));
  connect(ui->buttonBackGame, SIGNAL(released()), this,
          SLOT(buttonBackGameReleased()));
  connect(scene, SIGNAL(mousePress(Position)), this,
          SLOT(mousePressScene(Position)));
}

ScreenGame::~ScreenGame() {
  delete ui;
  delete scene;
  delete board;
}

void ScreenGame::buttonNewGameReleased() { emit newGameFromGame(); }

void ScreenGame::buttonBackGameReleased() { emit changeWindow(Windows::MENU); }

void ScreenGame::drawGameField() {
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;

  scene->clear();
  scene->setSceneRect(0, 0, std::min(width_graphicsView, height_graphicsView),
                      std::min(width_graphicsView, height_graphicsView));

  board = new QGraphicsSvgItem(":/images/green_chess_board.svg");
  scene->board = board;
  float width_board = board->boundingRect().size().width();
  float height_board = board->boundingRect().size().height();
  float scale_board =
      (std::min(width_graphicsView, height_graphicsView) - indent * 2) /
      width_board;
  board->setScale(scale_board);
  board->setPos(indent, indent);
  scene->addItem(board);

  size_cell_board =
      (std::min(width_graphicsView, height_graphicsView) - indent * 2) / 8.;

  drawAdvantageBar(height_board, scale_board);

  positions = QVector<QVector<Position>>(8, QVector<Position>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      positions[i][j].x = indent + i * ((width_board * scale_board) / 8);
      positions[i][j].y = indent + j * ((height_board * scale_board) / 8);
    }
  }

  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      if (data[i][j] == NONE)
        continue;
      GuiFigure *figure =
          new GuiFigure(width_graphicsView, height_graphicsView, data[i][j]);
      connect(figure, SIGNAL(moved(Position, Position)), this,
              SLOT(figureMoved(Position, Position)));
      connect(figure, SIGNAL(mousePressed(Position)), this,
              SLOT(pressFigure(Position)));
      figure->setPos(positions[i][j].x, positions[i][j].y);
      scene->addItem(figure);
    }
  }

  highlightAll();
  highlight_moves.clear();
  highlight_attacks.clear();
  timer->start();
}

void ScreenGame::resizeEvent(QResizeEvent *event) { this->drawGameField(); }

void ScreenGame::catchData(QVector<QVector<Figures>> catched_data,
                           double new_advantage_white, bool is_new_game) {
  if (is_new_game)
    second_advantage_white = new_advantage_white;
  this->data = catched_data;
  this->first_advantage_white = second_advantage_white;
  this->second_advantage_white = new_advantage_white;
  this->drawGameField();
}

void ScreenGame::figureMoved(Position from, Position delta) {
  Position from_board;
  Position delta_board;
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;
  float size_cell_board =
      (std::min(width_graphicsView, height_graphicsView) - indent * 2) / 8.;
  float ratio = size_cell_board / 2;
  from_board.x = static_cast<int>((from.x + 1 - indent) / size_cell_board);
  from_board.y = static_cast<int>((from.y + 1 - indent) / size_cell_board);
  delta_board.x = static_cast<int>(
      (delta.x + ((delta.x > 0) ? ratio : -ratio)) / size_cell_board);
  delta_board.y = static_cast<int>(
      (delta.y + ((delta.y > 0) ? ratio : -ratio)) / size_cell_board);
  from_global = {0, 0};
  emit figureMovedBoard(from_board, delta_board);
}

void ScreenGame::drawAdvantageBar(float height_board, float scale_board) {
  advantage_bar_black =
      new GuiAdvantageBar(indent, height_board * scale_board, Qt::black);
  advantage_bar_white =
      new GuiAdvantageBar(indent, height_board * scale_board, Qt::white);
  advantage_bar_black->setAdvantageWhite(1 - first_advantage_white);
  advantage_bar_black->setPos(indent + height_board * scale_board + 5, indent);
  advantage_bar_white->setPos(indent + height_board * scale_board + 5, indent);
  animation_black->setItem(advantage_bar_black);
  for (int i = 0; i < 5; ++i)
    animation_black->setScaleAt(
        0.1, 1, (1 - second_advantage_white) / (1 - first_advantage_white));
  scene->addItem(advantage_bar_white);
  scene->addItem(advantage_bar_black);
  first_advantage_white = second_advantage_white;
}

void ScreenGame::highlightAttacks(
    std::list<std::pair<Position, Figures>> attacks) {
  highlight_attacks = std::move(attacks);
}

void ScreenGame::highlightMoves(std::list<std::list<Position>> moves) {
  highlight_moves = std::move(moves);
}

Position ScreenGame::calculatePositionOnScene(Position position) {
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;
  float width_board = board->boundingRect().size().width();
  float scale_board =
      (std::min(width_graphicsView, height_graphicsView) - indent * 2) /
      width_board;
  int x =
      static_cast<int>(indent + position.x * ((width_board * scale_board) / 8));
  int y =
      static_cast<int>(indent + position.y * ((width_board * scale_board) / 8));
  x += size_cell_board / 2.;
  y += size_cell_board / 2.;
  return {x, y};
}

Position ScreenGame::calculatePositionOnBoard(Position position) {
  Position position_on_board;
  Position delta_board;
  position_on_board.x =
      static_cast<int>((position.x + 1 - indent) / size_cell_board);
  position_on_board.y =
      static_cast<int>((position.y + 1 - indent) / size_cell_board);
  return position_on_board;
}

void ScreenGame::pressFigure(Position position) {
  Position board_from_position = calculatePositionOnBoard(from_global);
  Position board_position = calculatePositionOnBoard(position);
  std::cout << board_from_position.x << " " << from_global.y << " " << board_from_position.x << " " << board_position.y << "\n";
  if (from_global.x != 0 && from_global.y != 0 &&
      board_from_position.x == board_position.x && board_from_position.y == board_position.y) {
    this->highlight_attacks.clear();
    this->highlight_moves.clear();
    this->from_global = {0, 0};
  } else {
    from_global = position;
    emit pressGuiFigure(board_position);
  }
  drawGameField();
}

void ScreenGame::highlightAll() {
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;
  for (auto attack : highlight_attacks) {
    Position pos = calculatePositionOnScene(attack.first);
    float x = pos.x;
    float y = pos.y;
    GuiFigure *figure =
        new GuiFigure(width_graphicsView, height_graphicsView, attack.second);
    connect(figure, SIGNAL(press(Position)), this, SLOT(mousePressStep(Position)));
    figure->setPos(x - size_cell_board / 2, y - size_cell_board / 2);
    QGraphicsColorizeEffect *colorize_effect = new QGraphicsColorizeEffect();
    colorize_effect->setColor(QColor(255, 140, 0));
    figure->setGraphicsEffect(colorize_effect);
    scene->addItem(figure);
    for (auto item : scene->collidingItems(figure)) {
      if (item != board)
        item->hide();
    }
  }
  for (auto move : highlight_moves) {
    for (auto step : move) {
      Position pos = calculatePositionOnScene(step);
      int x = pos.x;
      int y = pos.y;
      GuiPoint *figure = new GuiPoint(size_cell_board);
      figure->setPos(x, y);
      connect(figure, SIGNAL(press(Position)), this, SLOT(mousePressStep(Position)));
      scene->addItem(figure);
    }
  }
}

void ScreenGame::mousePressScene(Position to) {
  from_global = {0, 0};
  drawGameField();
  std::cout << "Press scene\n";
}

void ScreenGame::mousePressStep(Position to) {
  std::cout << "step\n";
  Position delta = calculatePositionOnBoard(to);
  Position from_board = calculatePositionOnBoard(from_global);
  emit figureMovedBoard(from_board,
                        {delta.x - from_board.x, delta.y - from_board.y});
  std::cout << from_board.x << " " << from_board.y << " " << delta.x << " " << delta.y << '\n';
  from_global = {0, 0};
}
