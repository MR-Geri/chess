#pragma once

#include "../../constants.h"
#include "../../utils.h"
#include <list>
#include <set>

class Figure {
public:
  Figure(FigureColor color = WHITE);
  Figure(int price, FigureColor color = WHITE);

  int getPrice();
  std::list<Position> getUnarySteps(Position step);
  std::set<Position> getPossibleMoves();
  std::set<Position> getPossibleAttacks();

protected:
  int b_price;
  std::set<Position> possible_moves;
  FigureColor b_color;
};

class King : public Figure {
public:
  King(FigureColor color = WHITE);
};

class Queen : public Figure {
public:
  Queen(FigureColor color = WHITE);
};

class Bishop : public Figure {
public:
  Bishop(FigureColor color = WHITE);
};

class Rook : public Figure {
public:
  Rook(FigureColor color = WHITE);
};

class Kinght : public Figure {
public:
  Kinght(FigureColor color = WHITE);
  std::list<Position> getUnarySteps(Position step);
};

class Pawn : public Figure {
public:
  Pawn(FigureColor color = WHITE);
  Pawn(bool flag_move, FigureColor color = WHITE);
  std::set<Position> getPossibleAttacks();
};
