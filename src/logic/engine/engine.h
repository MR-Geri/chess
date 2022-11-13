#pragma once

#include "../../constants.h"
#include "../board/board.h"
#include "../figures/figures.h"

/**
 * @brief Движок игры. Реализует логику ходов.
 */
class Engine {
public:
  Engine();
  ~Engine();

  /**
   * @brief Проверяет возможность хода и перемещает фигуру.
   * @param from_pos позиция фигуры, которую нужно переместить
   * @param step шаг, на который переместить фигуру
   * @return статус перемещения StatusMove (Enum)
   */
  StatusMove move(Position from_pos, Position step);

  /**
   * @brief Расчет преимущества игрока.
   * @return расчитанное значение.
   */
  int calculateAdvantage();

  /**
   * @brief Базовая расстановка фигур на поле.
   */
  void setStartingArrangement();

  /**
   * @brief Установка фигуры на доску.
   * @param figure указатель на фигуру, которую нужно поставить на поле.
   * @param position позиция на которую нужно поставить фигуру.
   * @return если установка прошла успешно - true, в противном случае - false.
   */
  bool setFigureOnBoard(Figure *figure, Position position);

  /**
   * @brief clearBoard
   */
  void clearBoard();

  std::vector<std::vector<Figure *>> getData();

private:
  Board *game_board;
};
