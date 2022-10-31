#pragma once

#include <QList>
#include <QPair>
#include <QSet>
#include <qpair.h>

class Figure {
public:
  Figure();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
  int getPrice();
  QSet<QPair<int, int>> getPossibleMoves();

protected:
  int b_price;
  QSet<QPair<int, int>> possible_moves;
};

class King : public Figure {
public:
  King();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};

class Queen : public Figure {
public:
  Queen();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};

class Bishop : public Figure {
public:
  Bishop();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};

class Rook : public Figure {
public:
  Rook();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};

class Kinght : public Figure {
public:
  Kinght();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};

class Pawn : public Figure {
public:
  Pawn();
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step);
};
