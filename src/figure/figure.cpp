#include "figure.h"

King::King() {
    price = 0;
    x = 1; y = 1;
    figure_size = 30;
    col = x * figure_size;
    row = y * figure_size;
}

int King::move(QPair<int, int> cords_board) {
    int a = 0;
    if (abs(col - cords_board.first) > 1 || abs(row - cords_board.second) > 1) {
        // Может быть добавлена обработка ошибки
        // Невозможный ход
        return a;
    }
    if ((col + cords_board.first) < 0 || (col + cords_board.second) >= 8 ||
        (row + cords_board.first) < 0 || (row + cords_board.second) >= 8) {
        // Может быть добавлена обработка ошибки
        // Выход за поле
        return a;
    }
    col += cords_board.first;
    row += cords_board.second;
    x += cords_board.first * this->figure_size;
    y += cords_board.second * this->figure_size;
    return a;
}

QRectF King::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void King::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) {
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}

QList<QPair<int, int>> King::getValidMoves() {
    return QList<QPair<int, int>>();
}
