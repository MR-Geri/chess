#include "tst_figures.h"

TestsFigures::TestsFigures() {}

TestsFigures::~TestsFigures() {}

FigureColor colors[2] = {WHITE, BLACK};

void setOnlyOneFigureOn(Engine &engine, Figure *figure, Position position) {
  engine.current_color = figure->getColor();
  engine.clearBoard();
  engine.setFigureOnBoard(figure, position);
}

void TestsFigures::test_king() {
  Engine engine;

  for (int i_color = 0; i_color < 2; i_color++) {
    FigureColor me = colors[i_color], enemy = colors[1 - i_color];
    // Невозможные ходы
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {3, 1}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {1, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {-2, 2}), GO_OUT);
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, -2}), GO_OUT);

    // Нет хода
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

    // Выход за границы поля
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

    // Выход за границы поля
    for (int i = 0; i < 8; i++) {
      setOnlyOneFigureOn(engine, new King(me), {0, i});
      QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new King(me), {7, i});
      QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new King(me), {i, 0});
      QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
      setOnlyOneFigureOn(engine, new King(me), {i, 7});
      QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
    }

    // Успешные ходы
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i != 0 || j != 0) {
          setOnlyOneFigureOn(engine, new King(me), {4, 4});
          QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
        }
      }
    }

    // Взятие
    setOnlyOneFigureOn(engine, new King(me), {0, 0});
    engine.setFigureOnBoard(new King(enemy), {1, 1});
    QCOMPARE(engine.move({0, 0}, {1, 1}), DONE);
  }
}

void TestsFigures::test_queen() {
  Engine engine;

  for (int i_color = 0; i_color < 2; i_color++) {
    FigureColor me = colors[i_color], enemy = colors[1 - i_color];
    // Невозможные ходы
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {3, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, 1}), IMPOSSIBLE_MOVE);

    // Нет хода
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

    // Выход за границы поля
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

    // Выход за границы поля
    for (int i = 0; i < 8; i++) {
      setOnlyOneFigureOn(engine, new Queen(me), {0, i});
      QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Queen(me), {7, i});
      QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Queen(me), {i, 0});
      QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Queen(me), {i, 7});
      QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
    }

    // Проверка на успешные и не успешные ходы
    for (int i = -4; i <= 3; i++) {
      for (int j = -4; j <= 3; j++) {
        if (i != 0 && j != 0) {
          if ((abs(i) == abs(j)) || i == 0 || j == 0) {
            // Успешно
            setOnlyOneFigureOn(engine, new Queen(me), {4, 4});
            QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
          } else {
            // Не успешно
            setOnlyOneFigureOn(engine, new Queen(me), {4, 4});
            QCOMPARE(engine.move({4, 4}, {i, j}), IMPOSSIBLE_MOVE);
          }
        }
      }
    }

    // Ход через фигуры
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    engine.setFigureOnBoard(new Queen(me), {0, 1});
    QCOMPARE(engine.move({0, 0}, {0, 2}), MOVE_TO_THROUGH_FIGURE);
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    engine.setFigureOnBoard(new Queen(me), {1, 1});
    QCOMPARE(engine.move({0, 0}, {2, 2}), MOVE_TO_THROUGH_FIGURE);

    // Взятие
    setOnlyOneFigureOn(engine, new Queen(me), {0, 0});
    engine.setFigureOnBoard(new Queen(enemy), {1, 1});
    QCOMPARE(engine.move({0, 0}, {1, 1}), DONE);
  }
}

void TestsFigures::test_bishop() {
  Engine engine;

  for (int i_color = 0; i_color < 2; i_color++) {
    FigureColor me = colors[i_color], enemy = colors[1 - i_color];
    // Невозможные ходы
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {1, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 2}), IMPOSSIBLE_MOVE);

    // Нет хода
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

    // Выход за границы поля
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

    // Выход за границы поля
    for (int i = 0; i < 8; i++) {
      setOnlyOneFigureOn(engine, new Bishop(me), {0, i});
      QCOMPARE(engine.move({0, i}, {-1, 1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Bishop(me), {7, i});
      QCOMPARE(engine.move({7, i}, {1, 1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Bishop(me), {i, 0});
      QCOMPARE(engine.move({i, 0}, {1, -1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Bishop(me), {i, 7});
      QCOMPARE(engine.move({i, 7}, {1, 1}), GO_OUT);
    }

    // Успешные ходы
    for (int i = -3; i <= 3; i++) {
      for (int j = -3; j <= 3; j++) {
        if (i != 0 && j != 0) {
          if (abs(i) == abs(j)) {
            setOnlyOneFigureOn(engine, new Bishop(me), {4, 4});
            QCOMPARE(engine.move({4, 4}, {i, j}), DONE);
          } else {
            // Не успешно
            setOnlyOneFigureOn(engine, new Bishop(me), {4, 4});
            QCOMPARE(engine.move({4, 4}, {i, j}), IMPOSSIBLE_MOVE);
          }
        }
      }
    }

    // Ход через фигуры
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    engine.setFigureOnBoard(new Bishop(me), {1, 1});
    QCOMPARE(engine.move({0, 0}, {2, 2}), MOVE_TO_THROUGH_FIGURE);

    // Взятие
    setOnlyOneFigureOn(engine, new Bishop(me), {0, 0});
    engine.setFigureOnBoard(new Bishop(enemy), {1, 1});
    QCOMPARE(engine.move({0, 0}, {1, 1}), DONE);
  }
}

void TestsFigures::test_rook() {
  Engine engine;

  for (int i_color = 0; i_color < 2; i_color++) {
    FigureColor me = colors[i_color], enemy = colors[1 - i_color];
    // Невозможные ходы
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, 1}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, 3}), IMPOSSIBLE_MOVE);

    // Нет хода
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

    // Выход за границы поля
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

    // Выход за границы поля
    for (int i = 0; i < 8; i++) {
      setOnlyOneFigureOn(engine, new Rook(me), {0, i});
      QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Rook(me), {7, i});
      QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Rook(me), {i, 0});
      QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Rook(me), {i, 7});
      QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
    }

    // Успешные ходы
    for (int i = -4; i <= 3; i++) {
      if (i != 0) {
        setOnlyOneFigureOn(engine, new Rook(me), {4, 4});
        QCOMPARE(engine.move({4, 4}, {0, i}), DONE);
        setOnlyOneFigureOn(engine, new Rook(me), {4, 4});
        QCOMPARE(engine.move({4, 4}, {i, 0}), DONE);
      }
    }

    // Ход через фигуры
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    engine.setFigureOnBoard(new Rook(me), {0, 1});
    QCOMPARE(engine.move({0, 0}, {0, 2}), MOVE_TO_THROUGH_FIGURE);

    // Взятие
    setOnlyOneFigureOn(engine, new Rook(me), {0, 0});
    engine.setFigureOnBoard(new Rook(enemy), {0, 1});
    QCOMPARE(engine.move({0, 0}, {0, 1}), DONE);
  }
}

void TestsFigures::test_knight() {
  Engine engine;

  for (int i_color = 0; i_color < 2; i_color++) {
    FigureColor me = colors[i_color], enemy = colors[1 - i_color];
    // Невозможные ходы
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {2, 2}), IMPOSSIBLE_MOVE);
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {1, 1}), IMPOSSIBLE_MOVE);

    // Нет хода
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

    // Выход за границы поля
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

    // Выход за границы поля
    for (int i = 0; i < 8; i++) {
      setOnlyOneFigureOn(engine, new Knight(me), {0, i});
      QCOMPARE(engine.move({0, i}, {-1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Knight(me), {7, i});
      QCOMPARE(engine.move({7, i}, {1, 0}), GO_OUT);
      setOnlyOneFigureOn(engine, new Knight(me), {i, 0});
      QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
      setOnlyOneFigureOn(engine, new Knight(me), {i, 7});
      QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
    }

    // Успешные ходы
    setOnlyOneFigureOn(engine, new Knight(me), {4, 4});
    QCOMPARE(engine.move({4, 4}, {2, 1}), DONE);
    setOnlyOneFigureOn(engine, new Knight(me), {4, 4});
    QCOMPARE(engine.move({4, 4}, {1, 2}), DONE);
    setOnlyOneFigureOn(engine, new Knight(me), {4, 4});
    QCOMPARE(engine.move({4, 4}, {-2, -1}), DONE);
    setOnlyOneFigureOn(engine, new Knight(me), {4, 4});
    QCOMPARE(engine.move({4, 4}, {-1, -2}), DONE);

    // Ход через фигуры
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    engine.setFigureOnBoard(new Knight(me), {0, 1});
    QCOMPARE(engine.move({0, 0}, {2, 1}), DONE);

    // Взятие
    setOnlyOneFigureOn(engine, new Knight(me), {0, 0});
    engine.setFigureOnBoard(new Knight(enemy), {2, 1});
    QCOMPARE(engine.move({0, 0}, {2, 1}), DONE);
  }
}

void TestsFigures::test_pawn() {
  Engine engine;

  // -------------------------------------------------------------------------
  // -----------------------------WHITE---------------------------------------
  // -------------------------------------------------------------------------

  // Невозможные ходы
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {1, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  engine.setFigureOnBoard(new Pawn(WHITE), {0, 1});
  QCOMPARE(engine.move({0, 0}, {0, 1}), IMPOSSIBLE_MOVE);
  //*****************************************************
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  engine.setFigureOnBoard(new Pawn(WHITE), {0, 1});
  QCOMPARE(engine.move({0, 0}, {0, 2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  engine.setFigureOnBoard(new Pawn(WHITE), {0, 1});
  QCOMPARE(engine.move({0, 0}, {0, 1}), IMPOSSIBLE_MOVE);

  // Нет хода
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 0}), FAIL);

  // Выход за границы поля
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {0, 0});
  QCOMPARE(engine.move({0, 0}, {9, 1}), GO_OUT);

  // Выход за границы поля
  for (int i = 0; i < 8; i++) {
    setOnlyOneFigureOn(engine, new Pawn(WHITE), {i, 7});
    QCOMPARE(engine.move({i, 7}, {0, 1}), GO_OUT);
  }

  // Успешные ходы
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {4, 4});
  QCOMPARE(engine.move({4, 4}, {0, -1}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, WHITE), {4, 4});
  QCOMPARE(engine.move({4, 4}, {0, -2}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, WHITE), {6, 6});
  QCOMPARE(engine.move({6, 6}, {0, -2}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, WHITE), {5, 5});
  QCOMPARE(engine.move({5, 5}, {0, -2}), DONE);

  // Ход через фигуры
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {5, 3});
  engine.setFigureOnBoard(new Pawn(false, WHITE), {5, 4});
  QCOMPARE(engine.move({5, 4}, {0, -2}), MOVE_TO_THROUGH_FIGURE);

  // Взятие
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {4, 4});
  engine.setFigureOnBoard(new Pawn(BLACK), {3, 3});
  QCOMPARE(engine.move({4, 4}, {-1, -1}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(WHITE), {4, 4});
  engine.setFigureOnBoard(new Pawn(BLACK), {5, 3});
  QCOMPARE(engine.move({4, 4}, {1, -1}), DONE);

  // -------------------------------------------------------------------------
  // -----------------------------BLACK---------------------------------------
  // -------------------------------------------------------------------------

  // Невозможные ходы
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  QCOMPARE(engine.move({0, 7}, {1, -2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  QCOMPARE(engine.move({0, 7}, {0, -2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  engine.setFigureOnBoard(new Pawn(BLACK), {0, 6});
  QCOMPARE(engine.move({0, 7}, {0, -1}), IMPOSSIBLE_MOVE);
  //*****************************************************
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  engine.setFigureOnBoard(new Pawn(BLACK), {0, 1});
  QCOMPARE(engine.move({0, 7}, {0, -2}), IMPOSSIBLE_MOVE);
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  engine.setFigureOnBoard(new Pawn(BLACK), {0, 6});
  QCOMPARE(engine.move({0, 7}, {0, -1}), IMPOSSIBLE_MOVE);

  // Нет хода
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  QCOMPARE(engine.move({0, 7}, {0, 0}), FAIL);

  // Выход за границы поля
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {0, 7});
  QCOMPARE(engine.move({0, 7}, {9, -1}), GO_OUT);

  // Выход за границы поля
  for (int i = 0; i < 8; i++) {
    setOnlyOneFigureOn(engine, new Pawn(BLACK), {i, 0});
    QCOMPARE(engine.move({i, 0}, {0, -1}), GO_OUT);
  }

  // Успешные ходы
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {4, 4});
  QCOMPARE(engine.move({4, 4}, {0, 1}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, BLACK), {4, 4});
  QCOMPARE(engine.move({4, 4}, {0, 2}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, BLACK), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 2}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(false, BLACK), {0, 0});
  QCOMPARE(engine.move({0, 0}, {0, 2}), DONE);

  // Ход через фигуры
  setOnlyOneFigureOn(engine, new Pawn(false, BLACK), {0, 0});
  engine.setFigureOnBoard(new Pawn(BLACK), {0, 1});
  QCOMPARE(engine.move({0, 0}, {0, 2}), MOVE_TO_THROUGH_FIGURE);

  // Взятие
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {4, 4});
  engine.setFigureOnBoard(new Pawn(WHITE), {3, 5});
  QCOMPARE(engine.move({4, 4}, {-1, 1}), DONE);
  setOnlyOneFigureOn(engine, new Pawn(BLACK), {4, 4});
  engine.setFigureOnBoard(new Pawn(WHITE), {5, 5});
  QCOMPARE(engine.move({4, 4}, {1, 1}), DONE);
}

void TestsFigures::test_transform_figures() {
  Engine engine;
  // -------------------------------------------------------------------------
  // ------------------------------KING---------------------------------------
  // -------------------------------------------------------------------------
  King *king = new King(WHITE);
  setOnlyOneFigureOn(engine, king, {5, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KING);

  king = new King(WHITE);
  setOnlyOneFigureOn(engine, king, {5, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KING);

  king = new King(WHITE);
  setOnlyOneFigureOn(engine, king, {5, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KING);

  king = new King(WHITE);
  setOnlyOneFigureOn(engine, king, {5, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KING);

  king = new King(WHITE);
  setOnlyOneFigureOn(engine, king, {5, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KING);

  // -------------------------------------------------------------------------
  // ------------------------------PAWN---------------------------------------
  // -------------------------------------------------------------------------
  Pawn *pawn = new Pawn(WHITE);
  setOnlyOneFigureOn(engine, pawn, {5, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_PAWN);

  pawn = new Pawn(WHITE);
  setOnlyOneFigureOn(engine, pawn, {5, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KNIGHT);

  pawn = new Pawn(WHITE);
  setOnlyOneFigureOn(engine, pawn, {5, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KNIGHT);

  pawn = new Pawn(WHITE);
  setOnlyOneFigureOn(engine, pawn, {5, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_BISHOP);

  pawn = new Pawn(WHITE);
  setOnlyOneFigureOn(engine, pawn, {5, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_BISHOP);

  // -------------------------------------------------------------------------
  // -----------------------------KNIGHT--------------------------------------
  // -------------------------------------------------------------------------
  Knight *knight = new Knight(WHITE);
  setOnlyOneFigureOn(engine, knight, {6, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {4, 4});
  engine.move({6, 5}, {-2, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_PAWN);

  knight = new Knight(WHITE);
  setOnlyOneFigureOn(engine, knight, {6, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {4, 4});
  engine.move({6, 5}, {-2, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KNIGHT);

  knight = new Knight(WHITE);
  setOnlyOneFigureOn(engine, knight, {6, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {4, 4});
  engine.move({6, 5}, {-2, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_BISHOP);

  knight = new Knight(WHITE);
  setOnlyOneFigureOn(engine, knight, {6, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {4, 4});
  engine.move({6, 5}, {-2, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_BISHOP);

  knight = new Knight(WHITE);
  setOnlyOneFigureOn(engine, knight, {6, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {4, 4});
  engine.move({6, 5}, {-2, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_ROOK);

  // -------------------------------------------------------------------------
  // -----------------------------BISHOP--------------------------------------
  // -------------------------------------------------------------------------
  Bishop *bishop = new Bishop(WHITE);
  setOnlyOneFigureOn(engine, bishop, {5, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KNIGHT);

  bishop = new Bishop(WHITE);
  setOnlyOneFigureOn(engine, bishop, {5, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_KNIGHT);

  bishop = new Bishop(WHITE);
  setOnlyOneFigureOn(engine, bishop, {5, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_BISHOP);

  bishop = new Bishop(WHITE);
  setOnlyOneFigureOn(engine, bishop, {5, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_ROOK);

  bishop = new Bishop(WHITE);
  setOnlyOneFigureOn(engine, bishop, {5, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {4, 4});
  engine.move({5, 5}, {-1, -1});
  QCOMPARE(engine.getData()[4][4]->getTypeFigure(), W_ROOK);

  // -------------------------------------------------------------------------
  // ------------------------------ROOK---------------------------------------
  // -------------------------------------------------------------------------
  Rook *rook = new Rook(WHITE);
  setOnlyOneFigureOn(engine, rook, {5, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_KNIGHT);

  rook = new Rook(WHITE);
  setOnlyOneFigureOn(engine, rook, {5, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_BISHOP);

  rook = new Rook(WHITE);
  setOnlyOneFigureOn(engine, rook, {5, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_BISHOP);

  rook = new Rook(WHITE);
  setOnlyOneFigureOn(engine, rook, {5, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_ROOK);

  rook = new Rook(WHITE);
  setOnlyOneFigureOn(engine, rook, {5, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_QUEEN);

  // -------------------------------------------------------------------------
  // ------------------------------QUEEN--------------------------------------
  // -------------------------------------------------------------------------
  Queen *queen = new Queen(WHITE);
  setOnlyOneFigureOn(engine, queen, {5, 5});
  engine.setFigureOnBoard(new Pawn(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_BISHOP);

  queen = new Queen(WHITE);
  setOnlyOneFigureOn(engine, queen, {5, 5});
  engine.setFigureOnBoard(new Knight(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_BISHOP);

  queen = new Queen(WHITE);
  setOnlyOneFigureOn(engine, queen, {5, 5});
  engine.setFigureOnBoard(new Bishop(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_ROOK);

  queen = new Queen(WHITE);
  setOnlyOneFigureOn(engine, queen, {5, 5});
  engine.setFigureOnBoard(new Rook(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_ROOK);

  queen = new Queen(WHITE);
  setOnlyOneFigureOn(engine, queen, {5, 5});
  engine.setFigureOnBoard(new Queen(BLACK), {5, 4});
  engine.move({5, 5}, {0, -1});
  QCOMPARE(engine.getData()[5][4]->getTypeFigure(), W_QUEEN);
}

#include "tst_figures.moc"
