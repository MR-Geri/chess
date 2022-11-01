#include "board.h"
#include "math.h"

Board::Board() {
  // Pawn(false)
  // Генерация поля
  // TODO
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = nullptr;
    }
  }
}

Figure *Board::getFigure(Position coords) const {
  return board[coords.x()][coords.y()]; // TODO
}

void Board::move(Position from, Position to) {
  int to_price = board[to.x()][to.y()]->getPrice(),
      price = board[from.x()][from.y()]->getPrice();

  if (to_price != 0 && price != -1) {
    int price = price - round(float(price - to_price) / 2);
  }

  if (board[to.x()][to.y()] != nullptr)
    delete board[to.x()][to.y()];

  switch (price) {
  case -1:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    break;
  case 1:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    board[to.x()][to.y()] = static_cast<Pawn *>(board[to.x()][to.y()]);
    break;
  case 2:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    board[to.x()][to.y()] = static_cast<Kinght *>(board[to.x()][to.y()]);
    break;
  case 3:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    board[to.x()][to.y()] = static_cast<Rook *>(board[to.x()][to.y()]);
    break;
  case 4:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    board[to.x()][to.y()] = static_cast<Bishop *>(board[to.x()][to.y()]);
    break;
  case 5:
    board[to.x()][to.y()] = board[from.x()][from.y()];
    board[to.x()][to.y()] = static_cast<Queen *>(board[to.x()][to.y()]);
    break;
  }

  board[from.x()][from.y()] = nullptr;
}
