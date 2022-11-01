#pragma once

#include <list>
#include <set>

class Figure {
public:
  Figure();
  Figure(int _b_price);

  int getPrice();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
  std::set<std::pair<int, int>> getPossibleMoves();
  std::set<std::pair<int, int>> getPossibleAttacks();

protected:
  int b_price;
  std::set<std::pair<int, int>> possible_moves;
};

class King : public Figure {
public:
  King();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
};

class Queen : public Figure {
public:
  Queen();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
};

class Bishop : public Figure {
public:
  Bishop();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
};

class Rook : public Figure {
public:
  Rook();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
};

class Kinght : public Figure {
public:
  Kinght();
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
};

class Pawn : public Figure {
public:
  Pawn();
  Pawn(bool flag_move);
  std::list<std::pair<int, int>> getUnarySteps(std::pair<int, int> step);
  std::set<std::pair<int, int>> getPossibleAttacks();
};
