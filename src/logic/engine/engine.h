#pragma once

#include "../../constants.h"
#include "../board/board.h"
#include "../figures/figures.h"

class Engine {
public:
  Engine();

  /**
   * @brief Проверяет возможность хода и перемещает фигуру.
   * @param from_pos позиция фигуры, которую нужно переместить
   * @param step шаг, на который переместить фигуру
   * @return статус перемещения StatusMove (Enum)
   */
  StatusMove move(Position from_pos, Position step);

  // void

private:
  Board game_board;
};
