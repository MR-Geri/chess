#pragma once

#include "../figures/figures.h"
#include <list>
#include <vector>

/**
 * @brief Обрабатывает логику игрового поля.
 * @param board матрица, которая хранит указатели на фигуры и расположение фигур
 * на поле.
 */
class Board {
public:
  Board();
  ~Board();

  /**
   * @brief Возвращает фигуру, которая находится в
   * ячейке поля с координатами coords.
   * @param coords
   * координаты ячейки поля, содержимое которой нужно узнать.
   * @return наследника класса Figure.
   */
  Figure *getFigure(Position coords) const;

  /**
   * @brief Перемещает фигуру в board.
   * @param from позиция с которой переместить фигуру.
   * @param to позиция куда переместить фигуру.
   */
  void move(Position from, Position to);

  Figures calculateFigureAfterTaking(Position from, Position to);

  /**
   * @brief Устанавливает фигуру на доску.
   * @param figure ссылка на фигуру, которую нужно разместить на поле.
   * @param position позиция, на котрую нужно разместить фигуру.
   * @return если установка прошла успешно - true, в противном случае - false.
   */
  bool setFigureOn(Figure *figure, Position position);

  /**
   * @brief clear Очищает доску.
   */
  void clear();

  /**
   * @brief getBoo Возвращает доску.
   */
  std::vector<std::vector<Figure *>> getBoardData() const;

private:
  std::vector<std::vector<Figure *>> board;
};
