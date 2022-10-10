#pragma once

#include <QGraphicsItem>
#include <QPair>
#include <QList>

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

    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
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
