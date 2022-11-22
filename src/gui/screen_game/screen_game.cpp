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

  indent = 15;

  timer = new QTimeLine(3000);
  figures = new QList<QGraphicsSvgItem*>;
  scene = new QGraphicsScene();

  timer->setFrameRange(0, 100);

  ui->graphicsView->setScene(this->scene);

  data = QVector<QVector<Figures>>(8, QVector<Figures>(8, Figures::NONE));

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

void ScreenGame::buttonNewGameReleased() { emit newGameFromGame(); }

void ScreenGame::buttonBackGameReleased() { emit changeWindow(Windows::MENU); }

void ScreenGame::drawGameField() {
  float width_graphicsView = ui->graphicsView->width() - 10;
  float height_graphicsView = ui->graphicsView->height() - 10;

  qDeleteAll(*figures);
  figures = new QList<QGraphicsSvgItem*>;
  scene->setSceneRect(0, 0, std::min(width_graphicsView, height_graphicsView),
                      std::min(width_graphicsView, height_graphicsView));

  board = new QGraphicsSvgItem(":/images/green_chess_board.svg");
  float width_board = board->boundingRect().size().width();
  float height_board = board->boundingRect().size().height();
  float scale_board =
      (std::min(width_graphicsView, height_graphicsView) - indent * 2) / width_board;
  board->setScale(scale_board);
  board->setPos(indent, indent);
  scene->addItem(board);

  float advantage_white = 0.5; //TODO
  advantage_bar = new GuiAdvantageBar(indent, height_board * scale_board);
  QGraphicsItemAnimation *animation = new QGraphicsItemAnimation();
  advantage_bar->setAdvantageWhite(advantage_white);
  advantage_bar->setPos(indent + height_board * scale_board + 5, indent);
  animation->setItem(advantage_bar);
  animation->setTimeLine(timer);
  for (int i = 0; i < 100; ++i)
          animation->setScaleAt(0.01, 1, 0.5);
  scene->addItem(advantage_bar);

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
      figure->setPos(positions[i][j].x, positions[i][j].y);
      figures->append(figure);
      scene->addItem(figure);
    }
  }

  timer->start();
}

void ScreenGame::resizeEvent(QResizeEvent *event) { this->drawGameField(); }

void ScreenGame::catchData(QVector<QVector<Figures>> catched_data) {
  this->data = catched_data;
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
  emit figureMovedBoard(from_board, delta_board);
}
