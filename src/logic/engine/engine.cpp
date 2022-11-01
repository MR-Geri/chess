#include "engine.h"

Engine::Engine() {}

StatusMove Engine::move(Position from_pos, Position step) {
  Position to_pos(from_pos.x() + step.x(), from_pos.y() + step.y());
  if (step.x() == 0 && step.y() == 0) {
    // Отсутствие хода
    return FAIL;
  }

  if (to_pos.x() < 0 || to_pos.x() >= 8 || to_pos.y() < 0 || to_pos.y() >= 8) {
    // Выход за поле
    return GO_OUT;
  }

  std::set<Position> possible_moves =
      game_board.getFigure(from_pos)->getPossibleMoves();
  std::set<Position> possible_attacks =
      game_board.getFigure(from_pos)->getPossibleAttacks();
  Figure *to_pos_figure = game_board.getFigure(to_pos);
  if ((possible_moves.find(step) == possible_moves.end() ||
       to_pos_figure->getPrice() != 0) ||
      possible_attacks.find(step) == possible_attacks.end()) {
    // Невозможный ход
    return IMPOSSIBLE_MOVE;
  }

  // V Ошибка, если ход на/через собственную фигуру V
  if (0) {
    return MOVE_TO_YOUR_FIGURE;
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  game_board.move(from_pos, to_pos);
  return DONE;
}
