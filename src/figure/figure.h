#pragma once

#include <QGraphicsItem>
#include <QPair>

class Figure : public QGraphicsItem
{
public:
    virtual void move(QPair<int, int>);
    virtual QList<QPair<int, int>> getValidMoves();
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
    int move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Queen : public Figure {
public:
    void move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Bishop : public Figure {
public:
    void move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Rook : public Figure {
public:
    void move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Kinght : public Figure {
public:
    void move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};

class Pawn : public Figure {
public:
    void move(QPair<int, int>);
    QList<QPair<int, int>> getValidMoves();
};
