#pragma once

#include <QGraphicsItem>
#include <QPair>
#include <QList>
#include <QPainter>

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
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Bishop : public Figure {
public:
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Rook : public Figure {
public:
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Kinght : public Figure {
public:
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Pawn : public Figure {
public:
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};
