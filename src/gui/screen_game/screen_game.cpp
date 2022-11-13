#include "screen_game.h"
#include "ui_screen_game.h"

ScreenGame::ScreenGame(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenGame) {
  ui->setupUi(this);

  ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->graphicsView->setAlignment(Qt::AlignCenter);

  ui->graphicsView->setMinimumHeight(500);
  ui->graphicsView->setMinimumWidth(500);

  data = {
      {B_ROOK, B_KINGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KINGHT, B_ROOK},
      {B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN},
      {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
      {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
      {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
      {NONE, NONE, NONE, NONE, NONE, NONE, NONE, NONE},
      {W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN},
      {W_ROOK, W_KINGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KINGHT,
       W_ROOK}};

  connect(ui->buttonNewGame, SIGNAL(released()), this,
          SLOT(buttonNewGameReleased()));
  connect(ui->buttonBackGame, SIGNAL(released()), this,
          SLOT(buttonBackGameReleased()));
}

ScreenGame::~ScreenGame() {
  delete ui;
  delete scene;
  delete board;
}

void ScreenGame::buttonNewGameReleased() {}

void ScreenGame::buttonBackGameReleased() { emit changeWindow(Windows::MENU); }

void ScreenGame::drawGameField() {
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;

  delete this->scene;
  this->scene = new QGraphicsScene();
  scene->setSceneRect(0, 0, std::min(width_graphicsView, height_graphicsView),
                      std::min(width_graphicsView, height_graphicsView));
  ui->graphicsView->setScene(this->scene);

  board = new QGraphicsSvgItem(":/images/green_chess_board.svg");
  float width_board = board->boundingRect().size().width();
  float height_board = board->boundingRect().size().height();
  float scale_board =
      (std::min(width_graphicsView, height_graphicsView) - 40) / width_board;
  board->setScale(scale_board);
  board->setPos(20, 20);
  scene->addItem(board);

  positions = QVector<QVector<Position>>(8, QVector<Position>(8));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      positions[i][j].y = 20 + i * ((width_board * scale_board) / 8);
      positions[i][j].x = 20 + j * ((height_board * scale_board) / 8);
    }
  }

  for (int i = 0; i < data.size(); i++) {
    for (int j = 0; j < data[i].size(); j++) {
      if (data[i][j] == NONE)
        continue;
      GuiFigure *figure =
          new GuiFigure(width_graphicsView, height_graphicsView, data[i][j]);
      figure->setPos(positions[i][j].x, positions[i][j].y);
      scene->addItem(figure);
    }
  }
}

void ScreenGame::resizeEvent(QResizeEvent *event) { this->drawGameField(); }

void ScreenGame::catchData(QVector<QVector<Figures>> catched_data) {
  this->data = catched_data;
  this->drawGameField();
}
