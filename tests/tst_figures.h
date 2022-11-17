#include "../src/logic/board/board.h"
#include "../src/logic/engine/engine.h"
#include "../src/logic/figures/figures.h"
#include <QtTest>
#include <iostream>
#include <qtestcase.h>

// add necessary includes here

class TestsFigures : public QObject {
  Q_OBJECT

public:
  TestsFigures();
  ~TestsFigures();

private slots:
  void test_king();
  void test_queen();
  void test_bishop();
  void test_rook();
  void test_knight();
  void test_pawn();
};
