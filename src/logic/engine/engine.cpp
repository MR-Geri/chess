#include "engine.h"

Engine::Engine() {}

Engine::~Engine() {}

StatusMove Engine::move(Position from_pos, Position step) {
  Position to_pos(from_pos.x + step.x, from_pos.y + step.y);
  if (step.x == 0 && step.y == 0) {
    // Отсутствие хода
    return FAIL;
  }

  if (to_pos.x < 0 || to_pos.x >= 8 || to_pos.y < 0 || to_pos.y >= 8) {
    // Выход за поле
    return GO_OUT;
  }

  std::set<Position> possible_moves =
      game_board.getFigure(from_pos)->getPossibleMoves();
  std::set<Position> possible_attacks =
      game_board.getFigure(from_pos)->getPossibleAttacks();
  Figure *to_pos_figure = game_board.getFigure(to_pos);

  if (to_pos_figure == nullptr) {
    if (possible_moves.find(step) == possible_moves.end())
      return IMPOSSIBLE_MOVE;
  } else {
    if (possible_attacks.find(step) == possible_attacks.end())
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

void Engine::setStartingArrangement() {
  game_board.clear();
  for (int i = 0; i < 8; i++) {
    Figure *pawn_black = new Pawn(false, BLACK);
    Figure *pawn_white = new Pawn(false, WHITE);
    game_board.setFigureOn(pawn_black, {i, 6});
    game_board.setFigureOn(pawn_white, {i, 1});
  }
  game_board.setFigureOn(new Rook(BLACK), {0, 7});
  game_board.setFigureOn(new Rook(WHITE), {0, 0});
  game_board.setFigureOn(new Rook(BLACK), {7, 7});
  game_board.setFigureOn(new Rook(WHITE), {7, 0});
  game_board.setFigureOn(new Bishop(BLACK), {1, 7});
  game_board.setFigureOn(new Bishop(WHITE), {1, 0});
  game_board.setFigureOn(new Bishop(BLACK), {6, 7});
  game_board.setFigureOn(new Bishop(WHITE), {6, 0});
  game_board.setFigureOn(new Kinght(BLACK), {2, 7});
  game_board.setFigureOn(new Kinght(WHITE), {2, 0});
  game_board.setFigureOn(new Kinght(BLACK), {5, 7});
  game_board.setFigureOn(new Kinght(WHITE), {5, 0});
  game_board.setFigureOn(new Queen(BLACK), {4, 7});
  game_board.setFigureOn(new Queen(WHITE), {3, 0});
  game_board.setFigureOn(new King(BLACK), {3, 7});
  game_board.setFigureOn(new King(WHITE), {4, 0});
}

bool Engine::setFigureOnBoard(Figure *figure, Position position) {
  return game_board.setFigureOn(figure, position);
}

void Engine::clearBoard() { game_board.clear(); }
