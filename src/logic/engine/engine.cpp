#include "engine.h"
#include <QPair>
#include <QSet>

Engine::Engine() {}

int Engine::move(QPair<int, int> from_pos, QPair<int, int> step) {
  if (step.first == 0 && step.second == 0) {
    // Отсутствие хода
    return 1;
  }
  if ((from_pos.first + step.first) < 0 || (from_pos.first + step.first) >= 8 ||
      (from_pos.second + step.second) < 0 ||
      (from_pos.second + step.second) >= 8) {
    // Выход за поле
    return 2;
  }
  QSet<QPair<int, int>> possible_moves =
      game_board.getFigure(from_pos).getPossibleMoves();
  if (possible_moves.find(step) == possible_moves.end()) {
    // Невозможный ход
    return 3;
  }
  // V Ошибка, если ход на/через собственную фигуру V
  if (0) {
    return 4;
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  game_board.move(from_pos, QPair(from_pos.first + step.first,
                                  from_pos.second + step.second));
  return 0;
}
