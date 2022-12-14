#pragma once

#include <QDir>
#include <QGraphicsColorizeEffect>
#include <QGraphicsEllipseItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QInputDialog>
#include <QString>
#include <QTimeLine>
#include <QWidget>
#include <src/constants.h>
#include <src/gui/gui_point/gui_point.h>
#include <src/gui/gui_scene/gui_scene.h>
#include <src/gui/gui_win/gui_win.h>
#include <src/gui/screen_game/gui_advantage_bar.h>
#include <src/gui/screen_game/gui_figure.h>

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

  /**
   * @brief Новая игра.
   */
  void newGameFromGame();

  /**
   * @brief Нажатие на фигуру.
   *
   * @param position позиция фигуры
   */
  void pressGuiFigure(Position position);

  /**
   * @brief Нажатие на фигуру.
   *
   * @param position позиция фигуры
   */
  void mousePressGuiFigure(Position position);

public slots:
  /**
   * @brief Получает данные для отрисовки из логики.
   */
  void catchData(QVector<QVector<Figures>> catched_data,
                 double new_advantage_white, bool is_new_game = false);

  /**
   * @brief Отображение атаки.
   */
  void highlightAttacks(std::list<std::pair<Position, Figures>> attacks);

  void highlightAttacksWhisRedrawing(
      std::list<std::pair<Position, Figures>> attacks);

  /**
   * @brief Отображение ходов.
   */
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

  /**
   * @brief Отправляет сигнал перемещения фигуры.
   */
  void figureMoved(Position from, Position delta);

  /**
   * @brief Отправляет сигнал о нажатии на фигуру.
   */
  void pressFigure(Position position);

  /**
   * @brief Отправляет сигнал о нажатии на сцену.
   */
  void mousePressScene(Position to);

  /**
   * @brief Отправляет сигнал о нажатии на ход.
   */
  void mousePressStep(Position to);

  /**
   * @brief Отправляет сигнал о нажатии на фигуру.
   */
  void mousePressFigure(Position position);

private:
  /**
   * @brief Событие изменения размера.
   */
  void resizeEvent(QResizeEvent *event);

  /**
   * @brief Отрисовка .
   */
  void drawGameField();

  /**
   * @brief Отрисовка шкалы преимущества.
   * @param высота доски.
   * @param коэффициент масштабирования доски.
   */
  void drawAdvantageBar(float height_board, float scale_board);

  /**
   * @brief Рассчет позиции фигуры на графической сцене по координатам на доске.
   * @param позиция фигуры на доске.
   * @return
   */
  Position calculatePositionOnScene(Position position);

  /**
   * @brief Рассчет позиции фигуры на доске по координатам на графической сцене.
   * @param позиция фигуры на графической сцене.
   * @return
   */
  Position calculatePositionOnBoard(Position position);

  /**
   * @brief Отрисовка всех подсказок ходов.
   */
  void highlightAll();

  /**
   * @brief Отрисовка возможных ходов - атак.
   */
  void highlightAttacksScene();

  /**
   * @brief Отрисовка возможных ходов - перемещений.
   */
  void highlightMovesScene();

private:
  Ui::ScreenGame *ui;
  GuiScene *scene;
  QGraphicsSvgItem *board;
  GuiAdvantageBar *advantage_bar_black;
  GuiAdvantageBar *advantage_bar_white;
  QTimeLine *timer;
  QGraphicsItemAnimation *animation_black;
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
