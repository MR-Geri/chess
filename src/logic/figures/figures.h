#pragma once

#include <QList>
#include <QPair>

class Figure {
public:
  virtual int move(QPair<int, int>) = 0;
  virtual QList<QPair<int, int>> getValidMoves() = 0;
  int getPrice() const;
  int getX() const;
  int getY() const;

protected:
  int b_price;
  int b_x, b_y;
};

class King : public Figure {
public:
  King();
  King(int x, int y);

  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
  int getPrice();
  int getX();
  int getY();
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
