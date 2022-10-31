#pragma once

#include "../board/board.h"
#include "../figures/figures.h"
#include <QPair>
#include <QVector>

class Engine {
public:
  Engine();

  /**
   * @brief move
   * проверяет возможность хода и перемещает фигуру.
   * @param from_pos позиция фигуры, которую переместить
   * @param step шаг, на который переместить фигуру
   * @return статус перемещения. 0 - перемещение выполнено.
   */
  int move(QPair<int, int> from_pos, QPair<int, int> step);

private:
  Board game_board;
};
