#pragma once

#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QString>
#include <QWidget>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <src/constants.h>
#include <src/gui/screen_game/gui_figure.h>
#include <src/gui/screen_game/gui_advantage_bar.h>

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

public slots:
  /**
   * @brief Получает данные для отрисовки из логики.
   */
  void catchData(QVector<QVector<Figures>> catched_data, double new_advantage_white);

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

private:
  void resizeEvent(QResizeEvent *event);
  void drawGameField();

private:
  Ui::ScreenGame *ui;
  QGraphicsScene *scene;
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
};
