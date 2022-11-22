#include "tst_board.h"
// add necessary includes here

TestsBoard::TestsBoard() {}

TestsBoard::~TestsBoard() {}

void TestsBoard::test_initBoard() {
  Board board = Board();
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
  Board board = Board();
  King *king = new King(WHITE);
  board.setFigureOn(king, {1, 2});
  QCOMPARE(board.getFigure({1, 2}), king);
  QCOMPARE(board.getFigure({0, 0}), nullptr);
}

void TestsBoard::test_clear() {
  Board board = Board();
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

#include "tst_board.moc"
