#include "board.h"
#include "math.h"

Board::Board() {
  board =
      std::vector<std::vector<Figure *>>(8, std::vector<Figure *>(8, nullptr));
}

Board::~Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != nullptr) {
        delete board[i][j];
        board[i][j] = nullptr;
      }
    }
  }
}

Figure *Board::getFigure(Position coords) const {
  return board[coords.x][coords.y]; // TODO
}

void Board::move(Position from, Position to) {
  int price = board[from.x][from.y]->getPrice();

  if (board[to.x][to.y] != nullptr && board[to.x][to.y]->getPrice() != -1) {
    price -=
        round((static_cast<float>(price) - board[to.x][to.y]->getPrice()) / 2.);
  }

  if (board[to.x][to.y] != nullptr) {
    delete board[to.x][to.y];
    board[to.x][to.y] = nullptr;
  }

  FigureColor color = board[from.x][from.y]->getColor();
  delete board[from.x][from.y];
  board[from.x][from.y] = nullptr;

  switch (price) {
  case KING:
    board[to.x][to.y] = new King(color);
    break;
  case PAWN:
    board[to.x][to.y] = new Pawn(color);
    break;
  case KINGHT:
    board[to.x][to.y] = new Kinght(color);
    break;
  case ROOK:
    board[to.x][to.y] = new Rook(color);
    break;
  case BISHOP:
    board[to.x][to.y] = new Bishop(color);
    break;
  case QUEEN:
    board[to.x][to.y] = new Queen(color);
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

std::vector<std::vector<Figure *>> Board::getBoardData() const { return board; }
