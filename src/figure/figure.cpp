#include "figure.h"

King::King() {
    price = 0;
    x = 0; y = 0;
    figure_size = 30;
    col = x * figure_size;
    row = y * figure_size;
}

int King::move(QPair<int, int> cords_board) {
    if (abs(col - cords_board.first) > 1 || abs(row - cords_board.second) > 1) {
        // Может быть добавлена обработка ошибки
        // Невозможный ход
        return 1;
    }
    if ((col + cords_board.first) < 0 || (col + cords_board.second) >= 8 ||
        (row + cords_board.first) < 0 || (row + cords_board.second) >= 8) {
        // Может быть добавлена обработка ошибки
        // Выход за поле
        return 2;
    }
    col += cords_board.first;
    row += cords_board.second;
    x += cords_board.first * this->figure_size;
    y += cords_board.second * this->figure_size;
    return 0;
}

QList<QPair<int, int>> King::getValidMoves() {

}
