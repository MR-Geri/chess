#pragma once

#include "../figures/figures.h"
#include <list>
#include <vector>

/**
 * @brief Обрабатывает логику игрового поля.
 * @param board матрица, которая хранит фигуры и их расположение на поле.
 */
class Board {
public:
  /**
   * @brief Коструктор по умолчанию, генерирует поле с фигурами
   * (стартовая расстановка и набор фигур).
   */
  Board();
  /**
   * @brief Возвращает список ходов, которые может совершить
   * фигура, находящаяся на поле в ячейке с координатами coords.
   * @param coords
   * координаты фигуры для которой необходимо получить возможные ходы.
   * @return
   * список возможных ходов для фигуры с координатами.
   */
  std::list<Position> getPossibleStepsFrom(Position coords) const;

  /**
   * @brief Возвращает фигуру, которая находится в
   * ячейке поля с координатами coords.
   * @param coords
   * координаты ячейки поля, содержимое которой нужно узнать.
   * @return наследника класса Figure.
   */
  Figure *getFigure(Position coords) const;

  /**
   * @brief Возвращает текущую ситуацию на поле.
   * @warning
   * на данный момент не планируется изпользоваться.
   * @return
   * значение int, которое может принимать значения от -100 до 100,
   * где -100 означает победу черных, а 100 означает победу белых.
   */
  int getSituation() const;

  /**
   * @brief Перемещает фигуру в board.
   * @param from позиция с которой переместить фигуру.
   * @param to позиция куда переместить фигуру.
   */
  void move(Position from, Position to);

private:
  std::vector<std::vector<Figure *>> board;
};
