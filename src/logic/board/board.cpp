#include "board.h"
#include "math.h"

Board::Board() {
  // Pawn(false)
}

Figure Board::getFigure(QPair<int, int> coords) const {
  return board[coords.first][coords.second]; // TODO
}

void Board::move(QPair<int, int> from, QPair<int, int> to) {
  int to_price = board[to.first][to.second].getPrice(),
      price = board[from.first][from.second].getPrice();

  if (to_price != 0 && price != -1) {
    int price = price - round(float(price - to_price) / 2);
  }

  switch (price) {
  case -1:
    board[to.first][to.second] = King();
    break;
  case 1:
    board[to.first][to.second] = Pawn();
    break;
  case 2:
    board[to.first][to.second] = Kinght();
    break;
  case 3:
    board[to.first][to.second] = Rook();
    break;
  case 4:
    board[to.first][to.second] = Bishop();
    break;
  case 5:
    board[to.first][to.second] = Queen();
    break;
  }

  board[from.first][from.second] = Figure();
}
