#include "figures.h"

King::King(int x, int y) {
  b_price = 0;
  b_x = x;
  b_y = y;
}

King::King() {
  b_price = 0;
  b_x = 0;
  b_y = 0;
}

int King::move(QPair<int, int> step_board) {
  if (step_board.first == 0 && step_board.second == 0) {
    // Отсутствие хода
    return 1;
  }
  if (abs(step_board.first) > 1 || abs(step_board.second) > 1) {
    // Невозможный ход
    return 2;
  }
  if ((b_x + step_board.first) < 0 || (b_x + step_board.first) >= 8 ||
      (b_y + step_board.second) < 0 || (b_y + step_board.second) >= 8) {
    // Выход за поле
    return 3;
  }

  // V Ошибка, если ход на/через собственную фигуру V
  if (0) {
    return 4;
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  b_x += step_board.first;
  b_y += step_board.second;
  return 0;
}

QList<QPair<int, int>> King::getValidMoves() {
  return QList<QPair<int, int>>();
}

int King::getPrice() { return b_price; }

int King::getX() { return b_x; }

int King::getY() { return b_y; }
