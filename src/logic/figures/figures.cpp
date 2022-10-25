#include "figures.h"

King::King() {
  price = 0;
  col = 0;
  row = 0;
}

int King::move(QPair<int, int> step_board) {
  if (abs(step_board.first) > 1 || abs(step_board.second) > 1) {
    // Может быть добавлена обработка ошибки
    // Невозможный ход
    return 1;
  }
  if ((col + step_board.first) < 0 || (col + step_board.second) >= 8 ||
      (row + step_board.first) < 0 || (row + step_board.second) >= 8) {
    // Может быть добавлена обработка ошибки
    // Выход за поле
    return 2;
  }
  col += step_board.first;
  row += step_board.second;
  return 0;
}

QList<QPair<int, int>> King::getValidMoves() {
  return QList<QPair<int, int>>();
}
