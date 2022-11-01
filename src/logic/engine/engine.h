#pragma once

#include "../../constants.h"
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
   * @return статус перемещения StatusMove (Enum)
   */
  StatusMove move(QPair<int, int> from_pos, QPair<int, int> step);

  int transform(QPair<int, int> pos);

private:
  Board game_board;
};
