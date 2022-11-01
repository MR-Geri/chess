#pragma once

#include "../board/board.h"
#include "../figures/figures.h"
#include <QPair>
#include <QVector>

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
  int move(QPair<int, int> from_pos, QPair<int, int> step);

  int transform(QPair<int, int> pos);

private:
  Board game_board;
};
