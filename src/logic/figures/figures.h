#pragma once

#include "../../utils.h"
#include <list>
#include <set>

class Figure {
public:
  Figure();
  Figure(int _b_price);

  int getPrice();
  std::list<Position> getUnarySteps(Position step);
  std::set<Position> getPossibleMoves();
  std::set<Position> getPossibleAttacks();

protected:
  int b_price;
  std::set<Position> possible_moves;
};

class King : public Figure {
public:
  King();
  std::list<Position> getUnarySteps(Position step);
};

class Queen : public Figure {
public:
  Queen();
  std::list<Position> getUnarySteps(Position step);
};

class Bishop : public Figure {
public:
  Bishop();
  std::list<Position> getUnarySteps(Position step);
};

class Rook : public Figure {
public:
  Rook();
  std::list<Position> getUnarySteps(Position step);
};

class Kinght : public Figure {
public:
  Kinght();
  std::list<Position> getUnarySteps(Position step);
};

class Pawn : public Figure {
public:
  bool check();
  Pawn();
  Pawn(bool flag_move);
  std::list<Position> getUnarySteps(Position step);
  std::set<Position> getPossibleAttacks();
};
