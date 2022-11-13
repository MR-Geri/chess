#include "figures.h"
#include <iostream>

int Figure::getPrice() { return b_price; }

FigureColor Figure::getColor() { return b_color; }

std::set<Position> Figure::getPossibleMoves() { return possible_moves; }

std::set<Position> Figure::getPossibleAttacks() { return possible_moves; }

Figure::Figure(int price, FigureColor color) : b_price(price), b_color(color) {}

King::King(FigureColor color) : Figure(KING, color) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0)
        possible_moves.insert({i, j});
    }
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_KING;
  } else {
    type_figure = Figures::B_KING;
  }
}

Queen::Queen(FigureColor color) : Figure(QUEEN, color) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0)
        for (int k = 1; k <= 7; k++)
          possible_moves.insert({i * k, j * k});
    }
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_QUEEN;
  } else {
    type_figure = Figures::B_QUEEN;
  }
}

Bishop::Bishop(FigureColor color) : Figure(BISHOP, color) {
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({i, i});
    possible_moves.insert({-i, i});
    possible_moves.insert({i, -i});
    possible_moves.insert({-i, -i});
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_BISHOP;
  } else {
    type_figure = Figures::B_BISHOP;
  }
}

Rook::Rook(FigureColor color) : Figure(ROOK, color) {
  for (int i = 1; i <= 7; i++) {
    possible_moves.insert({0, i});
    possible_moves.insert({i, 0});
    possible_moves.insert({0, -i});
    possible_moves.insert({-i, 0});
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_ROOK;
  } else {
    type_figure = Figures::B_ROOK;
  }
}

Kinght::Kinght(FigureColor color) : Figure(KINGHT, color) {
  possible_moves.insert({1, 2});
  possible_moves.insert({1, -2});
  possible_moves.insert({-1, 2});
  possible_moves.insert({-1, -2});
  possible_moves.insert({2, 1});
  possible_moves.insert({2, -1});
  possible_moves.insert({-2, 1});
  possible_moves.insert({-2, -1});
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_KINGHT;
  } else {
    type_figure = Figures::B_KINGHT;
  }
}

Pawn::Pawn(FigureColor color) : Figure(PAWN, color) {
  int color_mod = (color == WHITE) ? -1 : 1;
  possible_moves.insert({1 * color_mod, 0});
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_PAWN;
  } else {
    type_figure = Figures::B_PAWN;
  }
}

Pawn::Pawn(bool flag_move, FigureColor color) : Figure(PAWN, color) {
  int color_mod = (color == WHITE) ? -1 : 1;
  if (flag_move) {
    possible_moves.insert({1 * color_mod, 0});
  } else {
    possible_moves.insert({1 * color_mod, 0});
    possible_moves.insert({2 * color_mod, 0});
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_PAWN;
  } else {
    type_figure = Figures::B_PAWN;
  }
}

std::set<Position> Pawn::getPossibleAttacks() {
  int color_mod = (b_color == WHITE) ? -1 : 1;
  std::set<Position> out;
  out.insert({1 * color_mod, 1});
  out.insert({1 * color_mod, -1});
  return out;
}

std::list<Position> Figure::getUnarySteps(Position step) {
  int x_step = step.x != 0 ? std::min(std::max(step.x, -1), 1) : 0;
  int y_step = step.y != 0 ? std::min(std::max(step.y, -1), 1) : 0;
  std::list<Position> out;
  Position pos(0, 0);
  while (pos != step) {
    pos.x += x_step;
    pos.y += y_step;
    if (pos != step)
      out.emplace_back(pos);
  }
  return out;
}

std::list<Position> Kinght::getUnarySteps(Position step) {
  return std::list<Position>({});
}

Figures Figure::getTypeFigure() const {
  return type_figure;
}
