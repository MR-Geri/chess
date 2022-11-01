#include "engine.h"

Engine::Engine() {}

int Engine::move(std::pair<int, int> from_pos, std::pair<int, int> step) {
  std::pair<int, int> to_pos(from_pos.first + step.first,
                             from_pos.second + step.second);
  if (step.first == 0 && step.second == 0) {
    // Отсутствие хода
    return 1;
  }

  if (to_pos.first < 0 || to_pos.first >= 8 || to_pos.second < 0 ||
      to_pos.second >= 8) {
    // Выход за поле
    return 2;
  }

  std::set<std::pair<int, int>> possible_moves =
      game_board.getFigure(from_pos).getPossibleMoves();
  std::set<std::pair<int, int>> possible_attacks =
      game_board.getFigure(from_pos).getPossibleAttacks();
  Figure to_pos_figure = game_board.getFigure(to_pos);
  if ((possible_moves.find(step) == possible_moves.end() ||
       to_pos_figure.getPrice() != 0) ||
      possible_attacks.find(step) == possible_attacks.end()) {
    // Невозможный ход
    return 3;
  }

  // V Ошибка, если ход на/через собственную фигуру V
  if (0) {
    return 4;
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  game_board.move(from_pos, to_pos);
  return 0;
}
