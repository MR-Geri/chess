#pragma once

#include <QList>
#include <QPair>
#include <QSet>
#include <qpair.h>

class Figure {
public:
  virtual QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) = 0;
  int getPrice();
  QSet<QPair<int, int>> getPossibleMoves();

protected:
  int b_price;
  QSet<QPair<int, int>> possible_moves;
};

class King : public Figure {
public:
  King();

  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};

class Queen : public Figure {
public:
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};

class Bishop : public Figure {
public:
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};

class Rook : public Figure {
public:
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};

class Kinght : public Figure {
public:
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};

class Pawn : public Figure {
public:
  QList<QPair<int, int>> getUnarySteps(QPair<int, int> step) override;
};
