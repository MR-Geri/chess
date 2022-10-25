#include "../src/logic/figures/figures.h"
#include <QtTest>

// add necessary includes here

class tests : public QObject {
  Q_OBJECT

public:
  tests();
  ~tests();

private slots:
  void test_king();
  void test_queen();
  void test_bishop();
  void test_rook();
  void test_kinght();
  void test_pawn();
};

tests::tests() {}

tests::~tests() {}

void tests::test_king() {
  QCOMPARE(King().move(QPair<int, int>(0, 0)), 0);
  QCOMPARE(King().move(QPair<int, int>(1, 1)), 0);
  QCOMPARE(King().move(QPair<int, int>(2, 2)), 1);
}

void tests::test_queen() {}

void tests::test_bishop() {}

void tests::test_rook() {}

void tests::test_kinght() {}

void tests::test_pawn() {}

QTEST_APPLESS_MAIN(tests)

#include "tst_figure.moc"
