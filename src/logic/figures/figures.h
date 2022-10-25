#pragma once

#include <QList>
#include <QPair>

class Figure {
public:
  virtual int move(QPair<int, int>) = 0;
  virtual QList<QPair<int, int>> getValidMoves() = 0;
  int getPrice() const;
  int getCol() const;
  int getRow() const;

protected:
  int price;
  int col, row;
};

class King : public Figure {
public:
  King();
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Queen : public Figure {
public:
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Bishop : public Figure {
public:
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Rook : public Figure {
public:
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Kinght : public Figure {
public:
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Pawn : public Figure {
public:
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};
