#include "engine.h"
#include <iostream>
#include <list>
#include <vector>

Engine::Engine() {
  game_board = new Board();
  setStartingArrangement();
}

Engine::~Engine() { delete game_board; }

bool checkStepOnPossible(Position step, std::list<std::list<Position>> moves) {
  for (auto line : moves) {
    if (std::find(line.begin(), line.end(), step) != line.end())
      return 1;
  }
  return 0;
}

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
  std::list<std::list<Position>> possible_moves =
      from_pos_figure->getPossibleMoves();
  std::list<std::list<Position>> possible_attacks =
      from_pos_figure->getPossibleAttacks();

  if (to_pos_figure == nullptr) {
    if (checkStepOnPossible(step, from_pos_figure->getPossibleMoves()) == 0) {
      return IMPOSSIBLE_MOVE;
    }
  } else {
    if (from_pos_figure->getColor() == to_pos_figure->getColor()) {
      return IMPOSSIBLE_MOVE;
    }
    if (checkStepOnPossible(step, from_pos_figure->getPossibleAttacks()) == 0) {
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
  this->calculateAdvantageWhite();
  std::cout << this->calculateAdvantageWhite() << "\n";
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
  game_board->setFigureOn(new Bishop(WHITE), {2, 7});
  game_board->setFigureOn(new Bishop(BLACK), {2, 0});
  game_board->setFigureOn(new Bishop(WHITE), {5, 7});
  game_board->setFigureOn(new Bishop(BLACK), {5, 0});
  game_board->setFigureOn(new Knight(WHITE), {1, 7});
  game_board->setFigureOn(new Knight(BLACK), {1, 0});
  game_board->setFigureOn(new Knight(WHITE), {6, 7});
  game_board->setFigureOn(new Knight(BLACK), {6, 0});
  game_board->setFigureOn(new Queen(WHITE), {3, 7});
  game_board->setFigureOn(new Queen(BLACK), {3, 0});
  game_board->setFigureOn(new King(WHITE), {4, 7});
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

int Engine::enemyUnderAttack(std::vector<std::vector<Figure *>> board,
                             Position pos) {
  int figures_under_attack = 0;
  for (auto line : board[pos.x][pos.y]->getPossibleAttacks()) {
    for (auto step : line) {
      Position current_pos = {pos.x + step.x, pos.y + step.y};
      if (current_pos.x >= 0 && current_pos.x <= 7 && current_pos.y >= 0 &&
          current_pos.y <= 7)
        if (board[current_pos.x][current_pos.y] != nullptr) {
          if (board[current_pos.x][current_pos.y]->getColor() !=
              board[pos.x][pos.y]->getColor()) {
            figures_under_attack +=
                board[current_pos.x][current_pos.y]->getPriceAdvantage() / 2;
          }
          break;
        }
    }
  }
  return figures_under_attack;
}

int Engine::quantityPossibleMove(std::vector<std::vector<Figure *>> board,
                                 Position pos) {
  int moves = 0;
  for (auto line : board[pos.x][pos.y]->getPossibleMoves()) {
    for (auto step : line) {
      Position current_pos = {pos.x + step.x, pos.y + step.y};
      if (current_pos.x >= 0 && current_pos.x <= 7 && current_pos.y >= 0 &&
          current_pos.y <= 7) {
        if (board[current_pos.x][current_pos.y] == nullptr) {
          moves++;
        } else {
          break;
        }
      }
    }
  }
  return moves;
}

double Engine::calculateAdvantageWhite() {
  double white = 1, black = 1;
  std::vector<std::vector<Figure *>> board = this->getData();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != nullptr) {
        FigureColor color = board[i][j]->getColor();

        // Стоимость каждой фигуры
        if (color == WHITE) {
          white += board[i][j]->getPriceAdvantage();
          white += enemyUnderAttack(board, {i, j});
          white += quantityPossibleMove(board, {i, j}) * 20;
        } else {
          black += board[i][j]->getPriceAdvantage();
          black += enemyUnderAttack(board, {i, j});
          black += quantityPossibleMove(board, {i, j}) * 20;
        }
      }
    }
  }
  return white / (white + black);
}

std::list<std::pair<Position, Figures>> Engine::getPosibleAttacksFigureFrom(Position position) {
  std::vector<std::vector<Figure *>> board_data = game_board->getBoardData();
  std::list<std::list<Position>> possible_attacks =
      board_data[position.x][position.y]->getPossibleAttacks();
  std::list<std::pair<Position, Figures>> attacks;
  FigureColor color = board_data[position.x][position.y]->getColor();
  for (auto &attack : possible_attacks) {
    for (auto &step : attack) {
      step.x += position.x;
      step.y += position.y;
      if (step.x < 0 || step.x >= 8 || step.y < 0 || step.y >= 8)
        continue;
      if (board_data[step.x][step.y] != nullptr) {
        if (color != board_data[step.x][step.y]->getColor())
          attacks.push_back({step, game_board->calculateFigureAfterTaking(position, step)});
        break;
      }
    }
  }
  if (board_data[position.x][position.y]->getTypeFigure() == W_PAWN &&
      position.y == 1 &&
      board_data[position.x][position.y - 1] == nullptr){
      attacks.push_back({{position.x, position.y - 1}, W_QUEEN});
  }
  if (board_data[position.x][position.y]->getTypeFigure() == B_PAWN &&
      position.y == 6 &&
      board_data[position.x][position.y + 1] == nullptr){
      attacks.push_back({{position.x, position.y + 1}, B_QUEEN});
  }
  return attacks;
}

std::list<std::list<Position>>
Engine::getPosibleMovesFigureFrom(Position position) {
  std::vector<std::vector<Figure *>> board_data = game_board->getBoardData();
  std::list<std::list<Position>> possible_moves =
      board_data[position.x][position.y]->getPossibleMoves();
  std::list<std::list<Position>> moves;
  for (auto &one_move : possible_moves) {
    std::list<Position> move;
    bool flag = true;
    for (auto &step : one_move) {
      step.x += position.x;
      step.y += position.y;
      if (step.x < 0 || step.x >= 8 || step.y < 0 || step.y >= 8)
        continue;
      if (flag && board_data[step.x][step.y] == nullptr) {
        move.push_back({step.x, step.y});
        std::cout << flag << ' ' << step.x << " " << step.y << " this is\n";
      } else
        flag = false;
    }
    if (!move.empty() &&
        !((board_data[position.x][position.y]->getTypeFigure() == W_PAWN &&
        !(move.back().x == 0 && move.back().y == -1) &&
        position.y == 1) ||
        (board_data[position.x][position.y]->getTypeFigure() == B_PAWN) &&
        !(move.back().x == 0 && move.back().y == 1) &&
        position.y == 6)) {
      moves.push_back(move);
    }
  }
  return moves;
}
