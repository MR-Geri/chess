#include "figure.h"

King::King() {
  price = 0;
  col = 0;
  row = 0;
  figure_size = 30;
  x = col * figure_size;
  y = row * figure_size;
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
  x += step_board.first * this->figure_size;
  y += step_board.second * this->figure_size;
  return 0;
}

QRectF King::boundingRect() const {
  qreal penWidth = 1;
  return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth,
                20 + penWidth);
}

void King::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
  painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}

QList<QPair<int, int>> King::getValidMoves() {
  return QList<QPair<int, int>>();
}
