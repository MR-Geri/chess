#include "figures.h"

int Figure::getPrice() { return b_price; }

std::set<std::pair<int, int>> Figure::getPossibleMoves() {
  return possible_moves;
}

std::set<std::pair<int, int>> Figure::getPossibleAttacks() {
  return possible_moves;
}

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

std::set<std::pair<int, int>> Pawn::getPossibleAttacks() {
  std::set<std::pair<int, int>> out;
  out.insert({1, 1});
  out.insert({-1, 1});
  return out;
}

std::list<std::pair<int, int>> Figure::getUnarySteps(std::pair<int, int> step) {
  int x_step = step.first != 0 ? std::min(std::max(step.first, -1), 1) : 0;
  int y_step = step.second != 0 ? std::min(std::max(step.second, -1), 1) : 0;
  std::list<std::pair<int, int>> out;
  std::pair<int, int> pos(0, 0);
  while (pos != step) {
    out.emplace_back(pos);
    pos.first += x_step;
    pos.second += y_step;
  }
  return out;
}

std::list<std::pair<int, int>> Kinght::getUnarySteps(std::pair<int, int> step) {
  return std::list<std::pair<int, int>>({step});
}
