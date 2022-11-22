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

#include "tst_engine.moc"
