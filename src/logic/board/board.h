#pragma once

#include "../figures/figures.h"
#include <QList>
#include <QPair>
#include <qpair.h>

/**
 * @brief Board
 * данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 * @param map матрица, которая хранит фигуры и их расположение на поле.
 */
class Board {
public:
  /**
   * @brief Board
   * коструктор по умолчанию, генерирует поле с фигурами
   * (стартовая расстановка и набор фигур).
   */
  Board();
  /**
   * @brief get_possible_steps_from
   * константный метод, возвращающий список ходов, которые может совершить
   * фигура, находящаяся на поле в ячейке с координатами coords.
   * @param coords
   * координаты фигуры для которой необходимо получить возможные ходы.
   * @return
   * список возможных ходов для фигуры с координатами
   * coords.
   */
  QList<QPair<int, int>> getPossibleStepsFrom(QPair<int, int> coords) const;
  /**
   * @brief get_figure_from
   * константный метод, возвращающий фигуру, которая находится в
   * ячейке поля с координатами coords.
   * @param coords
   * координаты ячейки поля, содержимое которой нужно узнать.
   * @return
   * наследник класса Figure.
   */
  Figure getFigure(QPair<int, int> coords) const;
  /**
   * @private
   * @brief get_situation
   * константный метод, возвращающий текущую ситуацию на поле.
   * @warning
   * пока нигде не планируется изпользоваться.
   * @return
   * значение int, которое может принимать значения от -100 до 100,
   * где -100 означает победу черных, а 100 означает победу белых.
   */
  int getSituation() const;

  void move(QPair<int, int> from, QPair<int, int> to);

private:
  QVector<QVector<Figure>> board;
};
