#include "figures.h"
#include <QPair>

int Figure::getPrice() { return b_price; }

QSet<QPair<int, int>> Figure::getPossibleMoves() { return possible_moves; }

Figure::Figure() { b_price = 0; }

King::King() : Figure() {
  b_price = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert({i, j});
    }
  }
}

Queen::Queen() : Figure() {
  b_price = 0;
  for (int i = -7; i <= 7; i++) {
    for (int j = -7; j <= 7; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert({i, j});
    }
  }
}

Bishop::Bishop() : Figure() {
  b_price = 0;
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({i, i});
    possible_moves.insert({-i, i});
    possible_moves.insert({i, -i});
    possible_moves.insert({-i, -i});
  }
}

Rook::Rook() : Figure() {
  b_price = 0;
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({0, i});
    possible_moves.insert({i, 0});
    possible_moves.insert({0, -i});
    possible_moves.insert({-i, 0});
  }
}

Kinght::Kinght() : Figure() {
  b_price = 0;
  possible_moves.insert({1, 2});
  possible_moves.insert({1, -2});
  possible_moves.insert({-1, 2});
  possible_moves.insert({-1, -2});
  possible_moves.insert({2, 1});
  possible_moves.insert({2, -1});
  possible_moves.insert({-2, 1});
  possible_moves.insert({-2, -1});
}

Pawn::Pawn() : Figure() {
  b_price = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert({i, j});
    }
  }
}

QList<QPair<int, int>> Figure::getUnarySteps(QPair<int, int> step) {
  int x_step = step.first != 0 ? std::min(std::max(step.first, -1), 1) : 0;
  int y_step = step.second != 0 ? std::min(std::max(step.second, -1), 1) : 0;
  QList<QPair<int, int>> out;
  QPair<int, int> pos(0, 0);
  while (pos != step) {
    out.append(pos);
    pos.first += x_step;
    pos.second += y_step;
  }
  return out;
}

QList<QPair<int, int>> Kinght::getUnarySteps(QPair<int, int> step) {
  return QList<QPair<int, int>>({step});
}
