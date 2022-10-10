#pragma once

#include <QGraphicsItem>
#include <QList>
#include <QPainter>
#include <QPair>

class Figure : public QGraphicsItem {
public:
  virtual int move(QPair<int, int>) = 0;
  virtual QList<QPair<int, int>> getValidMoves() = 0;
  int getPrice() const;
  int getX() const;
  int getY() const;
  int getCol() const;
  int getRow() const;

protected:
  int price;
  int x, y;
  int figure_size;
  int col, row;
};

class King : public Figure {
public:
  King();
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Queen : public Figure {
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Bishop : public Figure {
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Rook : public Figure {
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Kinght : public Figure {
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};

class Pawn : public Figure {
public:
  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;
  int move(QPair<int, int>) override;
  QList<QPair<int, int>> getValidMoves() override;
};
