#include "./tst_board.h"
#include "./tst_engine.h"
#include "./tst_figures.h"
#include <QtTest>
#include <iostream>
#include <qtestcase.h>

// add necessary includes here

int main(int argc, char **argv) {
  int status = 0;

  TestsBoard test1;
  TestsFigures test2;
  TestsEngine test3;
  status |= QTest::qExec(&test1, argc, argv);
  status |= QTest::qExec(&test2, argc, argv);
  status |= QTest::qExec(&test3, argc, argv);

  if (status == 0) {
    std::cout << "\x1B[32mTESTS OK\033[0m" << std::endl;
  } else {
    std::cout << "\x1B[31mTESTS FAIL\033[0m" << std::endl;
  }
  return status;
}
