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
  /*// Проверка генератора
  QCOMPARE(King().getX(), 0);
  QCOMPARE(King().getY(), 0);
  QCOMPARE(King(2, 3).getX(), 2);
  QCOMPARE(King(2, 3).getY(), 3);
  // Нет хода
  QCOMPARE(King().move(QPair<int, int>(0, 0)), 1);
  // Невозможные ходы
  QCOMPARE(King().move(QPair<int, int>(0, 2)), 2);
  QCOMPARE(King().move(QPair<int, int>(1, 2)), 2);
  QCOMPARE(King().move(QPair<int, int>(2, 2)), 2);
  QCOMPARE(King().move(QPair<int, int>(-2, 2)), 2);
  QCOMPARE(King().move(QPair<int, int>(2, -2)), 2);

  // Выход за границы поля
  for (int i = 0; i < 8; i++) {
    QCOMPARE(King(0, i).move(QPair<int, int>(-1, 0)), 3);
    QCOMPARE(King(7, i).move(QPair<int, int>(1, 0)), 3);
    QCOMPARE(King(i, 0).move(QPair<int, int>(0, -1)), 3);
    QCOMPARE(King(i, 7).move(QPair<int, int>(0, 1)), 3);
  }

  // Ходы через своих
  // QCOMPARE(King().move(QPair<int, int>(0, 0)), 4);

  // Успешные ходы
  QCOMPARE(King(4, 4).move(QPair<int, int>(-1, -1)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(-1, 0)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(0, -1)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(-1, 1)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(1, -1)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(0, 1)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(1, 0)), 0);
  QCOMPARE(King(4, 4).move(QPair<int, int>(1, 1)), 0);*/
}

void tests::test_queen() {}

void tests::test_bishop() {}

void tests::test_rook() {}

void tests::test_kinght() {}

void tests::test_pawn() {}

QTEST_APPLESS_MAIN(tests)

#include "tst_figure.moc"
