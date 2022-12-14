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
  FigureColor color = board[from.x][from.y]->getColor();
  int price = board[from.x][from.y]->getPrice();
  Figures type_figure_from = board[from.x][from.y]->getTypeFigure();

  delete board[from.x][from.y];
  board[from.x][from.y] = nullptr;

  if (board[to.x][to.y] == nullptr) {
    if (type_figure_from == W_PAWN && to.y == 0 ||
        type_figure_from == B_PAWN && to.y == 7) {
      board[to.x][to.y] = new Queen(color);
      return;
    }
  } else {
    if (board[to.x][to.y]->getPrice() != -1 && price != -1) {
      price -= round(
          (static_cast<float>(price) - board[to.x][to.y]->getPrice()) / 2.);
      delete board[to.x][to.y];
    }
  }

  switch (price) {
  case KING:
    board[to.x][to.y] = new King(color);
    break;
  case PAWN:
    board[to.x][to.y] = new Pawn(color);
    break;
  case KNIGHT:
    board[to.x][to.y] = new Knight(color);
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

Figures Board::calculateFigureAfterTaking(Position from, Position to) {
  FigureColor color = board[from.x][from.y]->getColor();
  int price = board[from.x][from.y]->getPrice();

  if (board[to.x][to.y]->getPrice() != -1 && price != -1) {
    price -= round((static_cast<float>(price) - board[to.x][to.y]->getPrice()) / 2.);
  }

  switch (price) {
  case KING:
    if (color == FigureColor::WHITE) return W_KING;
    else return B_KING;
    break;
  case PAWN:
    if (color == FigureColor::WHITE) return W_PAWN;
    else return B_PAWN;
    break;
  case KNIGHT:
    if (color == FigureColor::WHITE) return W_KNIGHT;
    else return B_KNIGHT;
    break;
  case ROOK:
    if (color == FigureColor::WHITE) return W_ROOK;
    else return B_ROOK;
    break;
  case BISHOP:
    if (color == FigureColor::WHITE) return W_BISHOP;
    else return B_BISHOP;
    break;
  case QUEEN:
    if (color == FigureColor::WHITE) return W_QUEEN;
    else return B_QUEEN;
    break;
  }
  return W_KING; // Error
}
