#include "tst_board.h"
#include <qtestcase.h>
// add necessary includes here

TestsBoard::TestsBoard() {}

TestsBoard::~TestsBoard() {}

void TestsBoard::test_initBoard() {
  Board board;
  // board.setFigureOn(new King(WHITE), {2, 0});
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board.getBoardData()[i][j] != nullptr) {
        QString message = "Not empty i=%1 j=%2";
        QFAIL(message.arg(i).arg(j).toLatin1());
      }
    }
  }
}

void TestsBoard::test_setFigureOn() {
  Board board;
  King *king = new King(WHITE);
  board.setFigureOn(king, {1, 2});
  QCOMPARE(board.getFigure({1, 2}), king);
  QCOMPARE(board.getFigure({0, 0}), nullptr);
}

void TestsBoard::test_clear() {
  Board board;
  board.setFigureOn(new King(WHITE), {1, 1});
  board.clear();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board.getBoardData()[i][j] != nullptr) {
        QString message = "Not empty i=%1 j=%2";
        QFAIL(message.arg(i).arg(j).toLatin1());
      }
    }
  }
}

void TestsBoard::test_getFigure() {
  FigureColor colors[2] = {WHITE, BLACK};
  Board board;
  for (int i_color = 0; i_color < 2; i_color++) {
    King *king = new King(colors[i_color]);
    Knight *knight = new Knight(colors[i_color]);
    Queen *queen = new Queen(colors[i_color]);
    Pawn *pawn = new Pawn(colors[i_color]);
    Rook *rook = new Rook(colors[i_color]);
    Bishop *bishop = new Bishop(colors[i_color]);

    board.setFigureOn(king, {i_color, 0});
    board.setFigureOn(pawn, {i_color, 1});
    board.setFigureOn(queen, {i_color, 2});
    board.setFigureOn(rook, {i_color, 3});
    board.setFigureOn(bishop, {i_color, 4});
    board.setFigureOn(knight, {i_color, 5});

    QCOMPARE(board.getFigure({i_color, 0}), king);
    QCOMPARE(board.getFigure({i_color, 1}), pawn);
    QCOMPARE(board.getFigure({i_color, 2}), queen);
    QCOMPARE(board.getFigure({i_color, 3}), rook);
    QCOMPARE(board.getFigure({i_color, 4}), bishop);
    QCOMPARE(board.getFigure({i_color, 5}), knight);
  }
}

void TestsBoard::test_move() {
  Board board;
  board.setFigureOn(new King(WHITE), {0, 0});
  board.move({0, 0}, {1, 1});
  QCOMPARE(board.getFigure({1, 1})->getTypeFigure(), W_KING);
}

#include "tst_board.moc"
