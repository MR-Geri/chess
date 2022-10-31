#include "board.h"

Board::Board() {}

Figure Board::getFigure(QPair<int, int> coords) const {
  return board[coords.first][coords.second]; // TODO
}

void Board::move(QPair<int, int> from, QPair<int, int> to) {
  board[to.first][to.second] = board[from.first][from.second];
  board[from.first].erase(board[from.first].begin() + from.second);
}
