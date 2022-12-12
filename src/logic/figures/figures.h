#pragma once

#include "../../constants.h"
#include "../../utils.h"
#include "math.h"
#include <list>
#include <set>

/**
 * @brief Абстрактный класс фигуры.
 */
class Figure {
public:
  /**
   * @brief Конструктор, используемый в классах наследниках.
   * @param price вес фигуры.
   * @param color цвет фигуры (FigureColor).
   */
  Figure(int price, int advantage_price, FigureColor color = WHITE);

  /**
   * @brief Получение веса фигуры.
   * @return вес фигуры.
   */
  int getPrice();

  /**
   * @brief Получение веса преимущества фигуры.
   * @return вес фигуры.
   */
  int getPriceAdvantage();

  /**
   * @brief Получение элементарных ходов.
   * @param step позиция в которую нужно переместиться.
   * @return список элементарных ходов.
   */
  virtual std::list<Position> getUnarySteps(Position step);

  /**
   * @brief Получение возможных ходов перемещения.
   * @return список ходов.
   */
  virtual std::list<std::list<Position>> getPossibleMoves();

  /**
   * @brief Получение возможных ходов атаки.
   * @return список ходов.
   */
  virtual std::list<std::list<Position>> getPossibleAttacks();

  /**
   * @brief Получение цвета фигуры.
   * @return цвет фигуры.
   */
  FigureColor getColor();

  Figures getTypeFigure() const;

protected:
  int b_price;
  int b_advantage_price;
  std::list<std::list<Position>> possible_moves;
  FigureColor b_color;
  Figures type_figure;
};

/**
 * @brief Король.
 */
class King : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  King(FigureColor color = WHITE);
};

/**
 * @brief Ферзь.
 */
class Queen : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  Queen(FigureColor color = WHITE);
};

/**
 * @brief Слон.
 */
class Bishop : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  Bishop(FigureColor color = WHITE);
};

/**
 * @brief Ладья.
 */
class Rook : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  Rook(FigureColor color = WHITE);
};

/**
 * @brief Конь.
 */
class Knight : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  Knight(FigureColor color = WHITE);

  /**
   * @brief Получение элементарных ходов. Перегруженный для коня метод.
   * @param step позиция в которую нужно переместиться.
   * @return список элементарных ходов.
   */
  std::list<Position> getUnarySteps(Position step) override;
};

/**
 * @brief Пешка.
 */
class Pawn : public Figure {
public:
  /**
   * @brief Конструктор.
   * @param color цвет фигуры.
   */
  Pawn(FigureColor color = WHITE);

  /**
   * @brief Конструктор.
   * @param flag_move флаг, показывающий первый ли это ход пешки.
   * @param color цвет фигуры.
   */
  Pawn(bool flag_move, FigureColor color = WHITE);

  /**
   * @brief Получение возможных ходов атаки. Перегуженный для пешки метод.
   * @return список ходов.
   */
  std::list<std::list<Position>> getPossibleAttacks() override;
};
