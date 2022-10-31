#include "board.h"

GameBoard::GameBoard() {}

void GameBoard::move(QPair<int, int> from, QPair<int, int> to) {
  board[to.first][to.second] = board[from.first][from.second];
  board[from.first].erase(board[from.first].begin() + from.second);
}
