#include "figures.h"

int Figure::getPrice() { return b_price; }

std::set<Position> Figure::getPossibleMoves() { return possible_moves; }

std::set<Position> Figure::getPossibleAttacks() { return possible_moves; }

Figure::Figure() { b_price = 0; }

Figure::Figure(int _b_price) : b_price(_b_price) {}

King::King() : Figure(-1) {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert({i, j});
    }
  }
}

Queen::Queen() : Figure(5) {
  for (int i = -7; i <= 7; i++) {
    for (int j = -7; j <= 7; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert({i, j});
    }
  }
}

Bishop::Bishop() : Figure(4) {
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({i, i});
    possible_moves.insert({-i, i});
    possible_moves.insert({i, -i});
    possible_moves.insert({-i, -i});
  }
}

Rook::Rook() : Figure(3) {
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({0, i});
    possible_moves.insert({i, 0});
    possible_moves.insert({0, -i});
    possible_moves.insert({-i, 0});
  }
}

Kinght::Kinght() : Figure(2) {
  possible_moves.insert({1, 2});
  possible_moves.insert({1, -2});
  possible_moves.insert({-1, 2});
  possible_moves.insert({-1, -2});
  possible_moves.insert({2, 1});
  possible_moves.insert({2, -1});
  possible_moves.insert({-2, 1});
  possible_moves.insert({-2, -1});
}

Pawn::Pawn() : Figure(1) { possible_moves.insert({0, 1}); }

Pawn::Pawn(bool flag_move) : Figure(1) {
  if (flag_move) {
    possible_moves.insert({0, 1});
  } else {
    possible_moves.insert({0, 1});
    possible_moves.insert({0, 2});
  }
}

std::set<Position> Pawn::getPossibleAttacks() {
  std::set<Position> out;
  out.insert({1, 1});
  out.insert({-1, 1});
  return out;
}

std::list<Position> Figure::getUnarySteps(Position step) {
  int x_step = step.x() != 0 ? std::min(std::max(step.x(), -1), 1) : 0;
  int y_step = step.y() != 0 ? std::min(std::max(step.y(), -1), 1) : 0;
  std::list<Position> out;
  Position pos(0, 0);
  while (pos != step) {
    out.emplace_back(pos);
    pos.x() += x_step;
    pos.y() += y_step;
  }
  return out;
}

std::list<Position> Kinght::getUnarySteps(Position step) {
  return std::list<Position>({step});
}
