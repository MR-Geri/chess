#pragma once

#include "../figures/figures.h"
#include <QList>
#include <QPair>

/*!
 * \brief GameBoard
 * данный класс используется для отрисовки игрового поля.
 * Он является сценой для QGraphicsWidget.
 * \param map матрица, которая хранит фигуры и их расположение на поле.
 */
class GameBoard {
public:
  /*!
   * \brief GameBoard
   * коструктор по умолчанию, генерирует поле с фигурами
   * (стартовая расстановка и набор фигур).
   */
  GameBoard();
  /*!
   * \brief get_figure_from
   * константный метод, возвращающий тип фигуры, которая находится в
   * ячейке поля с координатами coords.
   * \param coords
   * координаты ячейки поля, содержимое которой нужно узнать.
   * \return
   * значение int, которое может принимать целочисленные значения
   * от -5 до 5 включительно.
   */
  int get_figure_from(QPair<int, int> coords) const;
  /*!
   * \brief get_possible_steps_from
   * константный метод, возвращающий список ходов, которые может совершить
   * фигура, находящаяся на поле в ячейке с координатами coords.
   * \param coords
   * координаты фигуры для которой необходимо получить возможные ходы.
   * \return
   * список возможных ходов для фигуры с координатами
   * coords.
   */
  QList<QPair<int, int>> get_possible_steps_from(QPair<int, int> coords) const;
  /*!
   * \private
   * \brief get_situation
   * константный метод, возвращающий текущую ситуацию на поле.
   * \warning
   * пока нигде не планируется изпользоваться.
   * \return
   * значение int, которое может принимать значения от -100 до 100,
   * где -100 означает победу черных, а 100 означает победу белых.
   */
  int get_situation() const;

private:
  QVector<QVector<Figure>> board;
};
