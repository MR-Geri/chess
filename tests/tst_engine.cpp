#include "tst_engine.h"

TestsEngine::TestsEngine() {}

TestsEngine::~TestsEngine() {}

void TestsEngine::test_setStartingArrangement() {
  Engine engine = Engine();
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
  Engine engine = Engine();
  engine.setStartingArrangement();
  for (int i = 0; i <= 7; i++) {
    QCOMPARE(enemyUnderAttack(engine.getData(), {i, 0}), 0);
    QCOMPARE(enemyUnderAttack(engine.getData(), {i, 1}), 0);
    QCOMPARE(enemyUnderAttack(engine.getData(), {i, 6}), 0);
    QCOMPARE(enemyUnderAttack(engine.getData(), {i, 7}), 0);
  }
}

void TestsEngine::test_quantityPossibleMove() {
  Engine engine = Engine();
  engine.setStartingArrangement();
  QCOMPARE(quantityPossibleMove(engine.getData(), {0, 0}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {1, 0}), 2);
  QCOMPARE(quantityPossibleMove(engine.getData(), {2, 0}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {3, 0}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {4, 0}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {5, 0}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {6, 0}), 2);
  QCOMPARE(quantityPossibleMove(engine.getData(), {7, 0}), 0);
  for (int i = 0; i <= 7; i++)
    QCOMPARE(quantityPossibleMove(engine.getData(), {i, 1}), 2);

  QCOMPARE(quantityPossibleMove(engine.getData(), {0, 7}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {1, 7}), 2);
  QCOMPARE(quantityPossibleMove(engine.getData(), {2, 7}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {3, 7}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {4, 7}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {5, 7}), 0);
  QCOMPARE(quantityPossibleMove(engine.getData(), {6, 7}), 2);
  QCOMPARE(quantityPossibleMove(engine.getData(), {7, 7}), 0);
  for (int i = 0; i <= 7; i++)
    QCOMPARE(quantityPossibleMove(engine.getData(), {i, 6}), 2);
}

void TestsEngine::test_calculateAdvantageWhite() {
  Engine engine = Engine();
  engine.setStartingArrangement();
  QCOMPARE(engine.calculateAdvantageWhite(), 0.5);
}

#include "tst_engine.moc"
