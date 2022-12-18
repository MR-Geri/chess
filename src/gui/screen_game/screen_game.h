#pragma once

#include <QGraphicsColorizeEffect>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QString>
#include <QTimeLine>
#include <QWidget>
#include <src/constants.h>
#include <src/gui/gui_point/gui_point.h>
#include <src/gui/gui_scene/gui_scene.h>
#include <src/gui/screen_game/gui_advantage_bar.h>
#include <src/gui/screen_game/gui_figure.h>
#include <src/gui/gui_point/gui_point.h>
#include <src/gui/gui_win/gui_win.h>

namespace Ui {
class ScreenGame;
}

/**
 * @brief Окно игры.
 * @param *game_scene
 * указатель на объект сцены игры (поле).
 */
class ScreenGame : public QWidget {
  Q_OBJECT

public:
  explicit ScreenGame(QWidget *parent = nullptr);
  ~ScreenGame();

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void changeWindow(int on_window);

  /**
   * @brief Показывает откуда и куда была перемещена фигура
   * в координатах поля. (Строка, столбец)
   */
  void figureMovedBoard(Position from_board, Position delta_board);

  void newGameFromGame();

  void pressGuiFigure(Position position);

public slots:
  /**
   * @brief Получает данные для отрисовки из логики.
   */
  void catchData(QVector<QVector<Figures>> catched_data,
                 double new_advantage_white, bool is_new_game = false);

  void highlightAttacks(std::list<std::pair<Position, Figures>> attacks);

  void highlightMoves(std::list<std::list<Position>> moves);

private slots:
  /**
   * @brief Отправляет сигнал перехода на окно меню.
   */
  void buttonBackGameReleased();

  /**
   * @brief Отправляет сигнал перехода на окно игры (перезапускает игру).
   */
  void buttonNewGameReleased();

  void figureMoved(Position from, Position delta);

  void pressFigure(Position position);

  void mousePressScene(Position to);

  void mousePressStep(Position to);

private:
  void resizeEvent(QResizeEvent *event);
  void drawGameField();
  void drawAdvantageBar(float height_board, float scale_board);
  Position calculatePositionOnScene(Position position);
  Position calculatePositionOnBoard(Position position);
  void highlightAll();

private:
  Ui::ScreenGame *ui;
  GuiScene *scene;
  QGraphicsSvgItem *board;
  GuiAdvantageBar *advantage_bar_black;
  GuiAdvantageBar *advantage_bar_white;
  QTimeLine *timer;
  QGraphicsItemAnimation *animation_black;
  QGraphicsItemAnimation *animation_white;
  QVector<QVector<Position>> positions;
  QVector<QVector<Figures>> data;
  int indent;
  double first_advantage_white;
  double second_advantage_white;
  float size_cell_board;
  std::list<std::list<Position>> highlight_moves;
  std::list<std::pair<Position, Figures>> highlight_attacks;
  Position from_global;
};
