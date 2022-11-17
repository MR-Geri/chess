#include "../src/logic/board/board.h"
#include "../src/logic/engine/engine.h"
#include "../src/logic/figures/figures.h"
#include <QtTest>
#include <iostream>
#include <qtestcase.h>


class TestsBoard : public QObject {
  Q_OBJECT

public:
  TestsBoard();
  ~TestsBoard();

private slots:
  void test_initBoard();
  void test_setFigureOn();
  void test_clear();
};
