#pragma once

#include <QGraphicsItem>

class Move{};

class Figure : public QGraphicsItem
{
public:
    Figure();

    virtual void move(Move);
    virtual QList<Move> getValidMoves();
    int getPrice() const;
    int getX() const;
    int getY() const;
    int getCol() const;
    int getRow() const;

private:
    int price;
    int x, y;
    int col, row;
};

class Move
{
    Move(int new_col, int new_row);
    int getDeltaX() const;
    int getDeltaY() const;
    int getDeltaCol() const;
    int getDeltaRow() const;
    Figure* getFigureInTargetField() const;
    Figure* getFigureInTargetField() const;

private:
    int delta_x, delta_y; // Изменение координат в QGraphicScene
    int delta_col, delta_row; // Изменение номера столбца и строки поля
    Figure* figure_in_target_field; // Фигура на целевом поле, nullptr если её там нет
    Figure* figure_making_move; // Фигура, котрая совершает ход
};

class King : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};

class Queen : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};

class Bishop : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};

class Rook : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};

class Kinght : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};

class Pawn : public Figure {
    void move(Move);
    QList<Move> getValidMoves();
};
