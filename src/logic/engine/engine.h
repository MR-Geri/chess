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
  int move(std::pair<int, int> from_pos, std::pair<int, int> step);

  // void

private:
  Board game_board;
};
