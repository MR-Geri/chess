#include "../src/logic/board/board.h"
#include "../src/logic/engine/engine.h"
#include "../src/logic/figures/figures.h"
#include <QtTest>
#include <iostream>

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

void setOnlyOneFigureOn(Engine &engine, Figure *figure, Position position) {
  engine.clearBoard();
  engine.setFigureOnBoard(figure, position);
}

void tests::test_king() {
  Engine engine;

  // Невозможные ходы
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {3, 1}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {1, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {2, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {-2, 2}), GO_OUT);
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {2, -2}), GO_OUT);

  // Нет хода
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

  // Выход за границы поля
  setOnlyOneFigureOn(engine, new King(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

  // Выход за границы поля
  for (int i = 0; i < 8; i++) {
    setOnlyOneFigureOn(engine, new King(WHITE), {0, i});
    QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
    setOnlyOneFigureOn(engine, new King(WHITE), {7, i});
    QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
    setOnlyOneFigureOn(engine, new King(WHITE), {i, 0});
    QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
    setOnlyOneFigureOn(engine, new King(WHITE), {i, 7});
    QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
  }

  // Ходы через своих
  // QCOMPARE(King().move(QPair<int, int>(0, 0)), 4);

  // Успешные ходы
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        setOnlyOneFigureOn(engine, new King(WHITE), {4, 4});
        QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
      }
    }
  }
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        setOnlyOneFigureOn(engine, new King(WHITE), {4, 4});
        QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
      }
    }
  }
}

void tests::test_queen() {
  Engine engine;

  // Невозможные ходы
  setOnlyOneFigureOn(engine, new Queen(WHITE), {0, 0});
  setOnlyOneFigureOn(engine, new Queen(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {-2, 2}), GO_OUT);
  setOnlyOneFigureOn(engine, new Queen(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {2, -2}), GO_OUT);

  // Нет хода
  setOnlyOneFigureOn(engine, new Queen(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

  // Выход за границы поля
  setOnlyOneFigureOn(engine, new Queen(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

  // Выход за границы поля
  for (int i = 0; i < 8; i++) {
    setOnlyOneFigureOn(engine, new Queen(WHITE), {0, i});
    QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
    setOnlyOneFigureOn(engine, new Queen(WHITE), {7, i});
    QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
    setOnlyOneFigureOn(engine, new Queen(WHITE), {i, 0});
    QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
    setOnlyOneFigureOn(engine, new Queen(WHITE), {i, 7});
    QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
  }

  // Ходы через своих
  // QCOMPARE(Queen().move(QPair<int, int>(0, 0)), 4);

  // Успешные ходы
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        setOnlyOneFigureOn(engine, new Queen(WHITE), {4, 4});
        QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
      }
    }
  }
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 || j != 0) {
        setOnlyOneFigureOn(engine, new Queen(WHITE), {4, 4});
        QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
      }
    }
  }
}

void tests::test_bishop() {}

void tests::test_rook() {}

void tests::test_kinght() {}

void tests::test_pawn() {}

QTEST_APPLESS_MAIN(tests)

#include "tst_figure.moc"
