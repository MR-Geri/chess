#include "../src/logic/board/board.h"
#include "../src/logic/engine/engine.h"
#include "../src/logic/figures/figures.h"
#include <QtTest>
#include <iostream>
#include <qtestcase.h>

// add necessary includes here

class TestsEngine : public QObject {
  Q_OBJECT

public:
  TestsEngine();
  ~TestsEngine();

private slots:
  void test_setStartingArrangement();
  void test_enemyUnderAttack();
  void test_quantityPossibleMove();
  void test_calculateAdvantageWhite();
};
