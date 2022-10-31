#pragma once

#include "../board/board.h"
#include "../figures/figures.h"
#include <QPair>
#include <QVector>

class Engine {
public:
  Engine();

  int move(QPair<int, int> from_pos, QPair<int, int> step);

private:
  GameBoard board;
};
