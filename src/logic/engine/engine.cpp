#include "engine.h"

Engine::Engine() {
  game_board = new Board();
  setStartingArrangement();
}

Engine::~Engine() { delete game_board; }

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

  Figure *from_pos_figure = game_board->getFigure(from_pos);
  Figure *to_pos_figure = game_board->getFigure(to_pos);
  if (from_pos_figure == nullptr)
    return FAIL;
  std::set<Position> possible_moves = from_pos_figure->getPossibleMoves();
  std::set<Position> possible_attacks = from_pos_figure->getPossibleAttacks();

  if (to_pos_figure == nullptr) {
    if (possible_moves.find(step) == possible_moves.end()) {
      return IMPOSSIBLE_MOVE;
    }
  } else {
    if (from_pos_figure->getColor() == to_pos_figure->getColor()) {
      return IMPOSSIBLE_MOVE;
    }
    if (possible_attacks.find(step) == possible_attacks.end()) {
      return IMPOSSIBLE_MOVE;
    }
  }

  // V Ошибка, если ход на/через фигуру V
  for (auto i_step : game_board->getFigure(from_pos)->getUnarySteps(step)) {
    Position check(from_pos.x + i_step.x, from_pos.y + i_step.y);
    if (game_board->getFigure(check) != nullptr) {
      return MOVE_TO_THROUGH_FIGURE;
    }
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  game_board->move(from_pos, to_pos);
  return DONE;
}

void Engine::setStartingArrangement() {
  game_board->clear();
  for (int i = 0; i < 8; i++) {
    Figure *pawn_white = new Pawn(false, WHITE);
    Figure *pawn_black = new Pawn(false, BLACK);
    game_board->setFigureOn(pawn_white, {i, 6});
    game_board->setFigureOn(pawn_black, {i, 1});
  }
  game_board->setFigureOn(new Rook(WHITE), {0, 7});
  game_board->setFigureOn(new Rook(BLACK), {0, 0});
  game_board->setFigureOn(new Rook(WHITE), {7, 7});
  game_board->setFigureOn(new Rook(BLACK), {7, 0});
  game_board->setFigureOn(new Bishop(WHITE), {1, 7});
  game_board->setFigureOn(new Bishop(BLACK), {1, 0});
  game_board->setFigureOn(new Bishop(WHITE), {6, 7});
  game_board->setFigureOn(new Bishop(BLACK), {6, 0});
  game_board->setFigureOn(new Knight(WHITE), {2, 7});
  game_board->setFigureOn(new Knight(BLACK), {2, 0});
  game_board->setFigureOn(new Knight(WHITE), {5, 7});
  game_board->setFigureOn(new Knight(BLACK), {5, 0});
  game_board->setFigureOn(new Queen(WHITE), {4, 7});
  game_board->setFigureOn(new Queen(BLACK), {3, 0});
  game_board->setFigureOn(new King(WHITE), {3, 7});
  game_board->setFigureOn(new King(BLACK), {4, 0});
}

bool Engine::setFigureOnBoard(Figure *figure, Position position) {
  return game_board->setFigureOn(figure, position);
}

void Engine::clearBoard() { game_board->clear(); }

std::vector<std::vector<Figure *>> Engine::getData() {
  std::vector<std::vector<Figure *>> data = this->game_board->getBoardData();
  return data;
}
