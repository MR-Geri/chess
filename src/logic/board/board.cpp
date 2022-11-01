#include "board.h"
#include "math.h"

Board::Board() {
  // Pawn(false)
  // Генерация поля
  // TODO
  board =
      std::vector<std::vector<Figure *>>(8, std::vector<Figure *>(8, nullptr));
}

Board::~Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != nullptr) {
        delete board[i][j];
      }
    }
  }
}

Figure *Board::getFigure(Position coords) const {
  return board[coords.x][coords.y]; // TODO
}

void Board::move(Position from, Position to) {
  int to_price =
          board[to.x][to.y] == nullptr ? 0 : board[to.x][to.y]->getPrice(),
      price = board[from.x][from.y] == nullptr
                  ? 0
                  : board[from.x][from.y]->getPrice();

  if (to_price != 0 && price != -1) {
    int price = price - round(float(price - to_price) / 2);
  }

  if (board[to.x][to.y] != nullptr)
    delete board[to.x][to.y];

  delete board[from.x][from.y];
  board[from.x][from.y] = nullptr;

  switch (price) {
  case KING:
    board[to.x][to.y] = new King();
    break;
  case PAWN:
    board[to.x][to.y] = new Pawn();
    break;
  case KINGHT:
    board[to.x][to.y] = new Kinght();
    break;
  case ROOK:
    board[to.x][to.y] = new Rook();
    break;
  case BISHOP:
    board[to.x][to.y] = new Bishop();
    break;
  case QUEEN:
    board[to.x][to.y] = new Queen();
    break;
  }
}

bool Board::setFigureOn(Figure *figure, Position position) {
  if (board[position.x][position.y] != nullptr) {
    delete figure;
    return false;
  }
  board[position.x][position.y] = figure;
  return true;
}

void Board::clear() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != nullptr) {
        delete board[i][j];
        board[i][j] = nullptr;
      }
    }
  }
}
