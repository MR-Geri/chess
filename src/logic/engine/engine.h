#pragma once

#include "../board/board.h"
#include "../figures/figures.h"

class Engine {
public:
  Engine();

  /**
   * @brief Проверяет возможность хода и перемещает фигуру.
   * @param from_pos позиция фигуры, которую нужно переместить
   * @param step шаг, на который переместить фигуру
   * @return статус перемещения:
   * \n 0 - перемещение выполнено
   * \n 1 - отсутствие перемещения
   * \n 2 - выход за игровое поле
   * \n 3 - фигура не может совершить такой ход
   * \n 4 - ход совершается на/через собственную фигуру
   */
  int move(std::pair<int, int> from_pos, std::pair<int, int> step);

  // void

private:
  Board game_board;
};
