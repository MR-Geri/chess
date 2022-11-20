#include "figures.h"
#include <iostream>

Figure::Figure(int price, int advantage_price, FigureColor color)
    : b_price(price), b_advantage_price(advantage_price), b_color(color) {}

int Figure::getPrice() { return b_price; }

int Figure::getPriceAdvantage() { return b_advantage_price; }

FigureColor Figure::getColor() { return b_color; }

std::list<std::list<Position>> Figure::getPossibleMoves() {
  return possible_moves;
}

std::list<std::list<Position>> Figure::getPossibleAttacks() {
  return possible_moves;
}

King::King(FigureColor color) : Figure(KING, 0, color) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      std::list<Position> line;
      if (i != 0 || j != 0)
        line.push_back({i, j});
      possible_moves.push_back(line);
    }
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_KING;
  } else {
    type_figure = Figures::B_KING;
  }
}

Queen::Queen(FigureColor color) : Figure(QUEEN, ADVANTAGE_QUEEN, color) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        std::list<Position> line;
        for (int k = 1; k <= 7; k++)
          line.push_back({i * k, j * k});
        possible_moves.push_back(line);
      }
    }
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_QUEEN;
  } else {
    type_figure = Figures::B_QUEEN;
  }
}

Bishop::Bishop(FigureColor color) : Figure(BISHOP, ADVANTAGE_BISHOP, color) {
  std::list<Position> line1, line2, line3, line4;
  for (int i = 1; i <= 7; i++) {
    line1.push_back({i, i});
    line2.push_back({-i, i});
    line3.push_back({i, -i});
    line4.push_back({-i, -i});
  }
  possible_moves.push_back(line1);
  possible_moves.push_back(line2);
  possible_moves.push_back(line3);
  possible_moves.push_back(line4);
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_BISHOP;
  } else {
    type_figure = Figures::B_BISHOP;
  }
}

Rook::Rook(FigureColor color) : Figure(ROOK, ADVANTAGE_ROOK, color) {
  std::list<Position> line1, line2, line3, line4;
  for (int i = 1; i <= 7; i++) {
    line1.push_back({0, i});
    line2.push_back({i, 0});
    line3.push_back({0, -i});
    line4.push_back({-i, 0});
  }
  possible_moves.push_back(line1);
  possible_moves.push_back(line2);
  possible_moves.push_back(line3);
  possible_moves.push_back(line4);
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_ROOK;
  } else {
    type_figure = Figures::B_ROOK;
  }
}

Knight::Knight(FigureColor color) : Figure(KNIGHT, ADVANTAGE_KNIGHT, color) {
  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      if (abs(i) + abs(j) == 3) {
        std::list<Position> line;
        line.push_back({i, j});
        possible_moves.push_back(line);
      }
    }
  }
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_KNIGHT;
  } else {
    type_figure = Figures::B_KNIGHT;
  }
}

Pawn::Pawn(FigureColor color) : Figure(PAWN, ADVANTAGE_PAWN, color) {
  int color_mod = (color == WHITE) ? -1 : 1;
  std::list<Position> line;
  line.push_back({0, 1 * color_mod});
  possible_moves.push_back(line);
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_PAWN;
  } else {
    type_figure = Figures::B_PAWN;
  }
}

Pawn::Pawn(bool flag_move, FigureColor color)
    : Figure(PAWN, ADVANTAGE_PAWN, color) {
  int color_mod = (color == WHITE) ? -1 : 1;
  std::list<Position> line;
  if (flag_move) {
    line.push_back({0, 1 * color_mod});
  } else {
    line.push_back({0, 1 * color_mod});
    line.push_back({0, 2 * color_mod});
  }
  possible_moves.push_back(line);
  if (color == FigureColor::WHITE) {
    type_figure = Figures::W_PAWN;
  } else {
    type_figure = Figures::B_PAWN;
  }
}

std::list<std::list<Position>> Pawn::getPossibleAttacks() {
  std::list<Position> line1, line2;
  std::list<std::list<Position>> out;
  int color_mod = (b_color == WHITE) ? -1 : 1;
  line1.push_back({1, 1 * color_mod});
  line2.push_back({-1, 1 * color_mod});
  out.push_back(line1);
  out.push_back(line2);
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

std::list<Position> Knight::getUnarySteps(Position step) {
  return std::list<Position>({});
}

Figures Figure::getTypeFigure() const { return type_figure; }
