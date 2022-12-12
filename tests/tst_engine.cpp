#include "tst_engine.h"

TestsEngine::TestsEngine() {}

TestsEngine::~TestsEngine() {}

void TestsEngine::test_setStartingArrangement() {
  Engine engine;
  engine.setStartingArrangement();

  QCOMPARE(engine.getData()[0][7]->getTypeFigure(), W_ROOK);
  QCOMPARE(engine.getData()[0][0]->getTypeFigure(), B_ROOK);
  QCOMPARE(engine.getData()[7][7]->getTypeFigure(), W_ROOK);
  QCOMPARE(engine.getData()[7][0]->getTypeFigure(), B_ROOK);

  QCOMPARE(engine.getData()[2][7]->getTypeFigure(), W_BISHOP);
  QCOMPARE(engine.getData()[2][0]->getTypeFigure(), B_BISHOP);
  QCOMPARE(engine.getData()[5][7]->getTypeFigure(), W_BISHOP);
  QCOMPARE(engine.getData()[5][0]->getTypeFigure(), B_BISHOP);

  QCOMPARE(engine.getData()[1][7]->getTypeFigure(), W_KNIGHT);
  QCOMPARE(engine.getData()[1][0]->getTypeFigure(), B_KNIGHT);
  QCOMPARE(engine.getData()[6][7]->getTypeFigure(), W_KNIGHT);
  QCOMPARE(engine.getData()[6][0]->getTypeFigure(), B_KNIGHT);

  QCOMPARE(engine.getData()[3][7]->getTypeFigure(), W_QUEEN);
  QCOMPARE(engine.getData()[3][0]->getTypeFigure(), B_QUEEN);

  QCOMPARE(engine.getData()[4][7]->getTypeFigure(), W_KING);
  QCOMPARE(engine.getData()[4][0]->getTypeFigure(), B_KING);

  for (int i = 0; i < 8; i++) {
    QCOMPARE(engine.getData()[i][1]->getTypeFigure(), B_PAWN);
    QCOMPARE(engine.getData()[i][6]->getTypeFigure(), W_PAWN);
  }
}

void TestsEngine::test_enemyUnderAttack() {
  Engine engine;
  engine.setStartingArrangement();
  for (int i = 0; i <= 7; i++) {
    QCOMPARE(engine.enemyUnderAttack(engine.getData(), {i, 0}), 0);
    QCOMPARE(engine.enemyUnderAttack(engine.getData(), {i, 1}), 0);
    QCOMPARE(engine.enemyUnderAttack(engine.getData(), {i, 6}), 0);
    QCOMPARE(engine.enemyUnderAttack(engine.getData(), {i, 7}), 0);
  }
}

void TestsEngine::test_quantityPossibleMove() {
  Engine engine;
  engine.setStartingArrangement();
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {0, 0}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {1, 0}), 2);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {2, 0}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {3, 0}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {4, 0}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {5, 0}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {6, 0}), 2);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {7, 0}), 0);
  for (int i = 0; i <= 7; i++)
    QCOMPARE(engine.quantityPossibleMove(engine.getData(), {i, 1}), 2);

  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {0, 7}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {1, 7}), 2);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {2, 7}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {3, 7}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {4, 7}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {5, 7}), 0);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {6, 7}), 2);
  QCOMPARE(engine.quantityPossibleMove(engine.getData(), {7, 7}), 0);
  for (int i = 0; i <= 7; i++)
    QCOMPARE(engine.quantityPossibleMove(engine.getData(), {i, 6}), 2);
}

void TestsEngine::test_calculateAdvantageWhite() {
  Engine engine;
  engine.setStartingArrangement();
  QCOMPARE(engine.calculateAdvantageWhite(), 0.5);
  engine.move({1, 7}, {1, -2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.502186748305);
  engine.move({1, 0}, {1, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.5);
  engine.move({2, 2}, {1, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.490349560369);
  engine.move({1, 1}, {0, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.491983753741);
  engine.move({5, 1}, {0, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.493037703513);
  engine.move({1, 1}, {0, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.493037703513);
  engine.move({0, 6}, {0, -2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.49418358714);
  engine.move({2, 6}, {0, -2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.49418358714);
  engine.move({5, 6}, {0, -2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.494158878505);
  engine.move({3, 4}, {-1, 2});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.48786407767);
  engine.move({2, 6}, {1, 1});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.454284401562);
  engine.move({3, 7}, {1, -1});
  QCOMPARE(engine.calculateAdvantageWhite(), 0.445438861333);
}

void TestsEngine::test_setFigureOnBoard() {
  Engine engine;
  engine.clearBoard();
  King *king = new King(WHITE);
  engine.setFigureOnBoard(king, {1, 2});
  QCOMPARE(engine.getData()[1][2], king);
  QCOMPARE(engine.getData()[0][0], nullptr);
}

void TestsEngine::test_clearBoard() {
  Engine engine;
  engine.clearBoard();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (engine.getData()[i][j] != nullptr) {
        QString message = "Not empty i=%1 j=%2";
        QFAIL(message.arg(i).arg(j).toLatin1());
      }
    }
  }
}

void TestsEngine::test_getData() {
  FigureColor colors[2] = {WHITE, BLACK};
  Engine engine;
  engine.clearBoard();
  for (int i_color = 0; i_color < 2; i_color++) {
    King *king = new King(colors[i_color]);
    Knight *knight = new Knight(colors[i_color]);
    Queen *queen = new Queen(colors[i_color]);
    Pawn *pawn = new Pawn(colors[i_color]);
    Rook *rook = new Rook(colors[i_color]);
    Bishop *bishop = new Bishop(colors[i_color]);

    engine.setFigureOnBoard(king, {i_color, 0});
    engine.setFigureOnBoard(pawn, {i_color, 1});
    engine.setFigureOnBoard(queen, {i_color, 2});
    engine.setFigureOnBoard(rook, {i_color, 3});
    engine.setFigureOnBoard(bishop, {i_color, 4});
    engine.setFigureOnBoard(knight, {i_color, 5});

    QCOMPARE(engine.getData()[i_color][0], king);
    QCOMPARE(engine.getData()[i_color][1], pawn);
    QCOMPARE(engine.getData()[i_color][2], queen);
    QCOMPARE(engine.getData()[i_color][3], rook);
    QCOMPARE(engine.getData()[i_color][4], bishop);
    QCOMPARE(engine.getData()[i_color][5], knight);
  }
}

#include "tst_engine.moc"
