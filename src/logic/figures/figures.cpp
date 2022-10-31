#include "figures.h"
#include <QPair>

Figure::Figure() { b_price = 0; }

int Figure::getPrice() { return b_price; }

QSet<QPair<int, int>> Figure::getPossibleMoves() { return possible_moves; }

King::King() {
  b_price = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (i != 0 && j != 0)
        possible_moves.insert(QPair(i, j));
    }
  }
}

QList<QPair<int, int>> Figure::getUnarySteps(QPair<int, int> step) {
  int x_step = step.first != 0 ? std::min(std::max(step.first, -1), 1) : 0;
  int y_step = step.second != 0 ? std::min(std::max(step.second, -1), 1) : 0;
  QList<QPair<int, int>> out;
  QPair<int, int> pos(0, 0);
  while (pos != step) {
    out.append(pos);
    pos.first += x_step;
    pos.second += y_step;
  }
  return out;
}

QList<QPair<int, int>> Kinght::getUnarySteps(QPair<int, int> step) {
  return QList<QPair<int, int>>({step});
}
