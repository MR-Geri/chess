#pragma once
#include <QVector>

/**
 * @brief Перечисление, содержащее окна приложения.
 */
enum Windows { GAME_FIELD, MENU, SETTINGS, LIDERBOARD, EXIT };

/**
 * @brief Перечисление, содержащее значение, возвращаемое функцией move.
 * \n DONE - перемещение выполнено
 * \n FAIL - отсутствие перемещения
 * \n GO_OUT - выход за игровое поле
 * \n IMPOSSIBLE_MOVE - фигура не может совершить такой ход
 * \n MOVE_TO_YOUR_FIGURE - ход совершается на/через собственную фигуру
 */
enum StatusMove { DONE, FAIL, GO_OUT, IMPOSSIBLE_MOVE, MOVE_TO_THROUGH_FIGURE };

/**
 * @brief Перечисление, содержащее веса фигур.
 */
enum FiguresPrice { KING = -1, PAWN = 1, KNIGHT, BISHOP, ROOK, QUEEN };

/**
 * @brief Перечисление, содержащее цвета фигур.
 */
enum FigureColor { WHITE, BLACK };

/**
 * @brief Перечисление, всех фигур с их цветами.
 */
enum Figures {
  NONE = 0,
  W_KING,
  W_PAWN,
  W_KNIGHT,
  W_BISHOP,
  W_ROOK,
  W_QUEEN,
  B_KING,
  B_PAWN,
  B_KNIGHT,
  B_BISHOP,
  B_ROOK,
  B_QUEEN,
  W_WIN,
  B_WIN
};

/**
 * @brief Стоимость всех фигур для анализатора победителя.
 */
enum AdvantagePrices {
  ADVANTAGE_PAWN = 100,
  ADVANTAGE_KNIGHT = 305,
  ADVANTAGE_BISHOP = 333,
  ADVANTAGE_ROOK = 563,
  ADVANTAGE_QUEEN = 950
};

/**
 * @brief Лучшие позиции для всех фигур на поле.
 */

namespace TablePositionRatioYX {
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_KING = {
    {-3, -4, -4, -5, -5, -4, -4, -3}, {-3, -4, -4, -5, -5, -4, -4, -3},
    {-3, -4, -4, -5, -5, -4, -4, -3}, {-3, -4, -4, -5, -5, -4, -4, -3},
    {-2, -3, -3, -4, -4, -3, -3, -2}, {-1, -2, -2, -2, -2, -2, -2, -1},
    {2, 2, 0, 0, 0, 0, 0, 2, 2},      {2, 3, 1, 0, 0, 1, 3, 2},
};
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_PAWN = {
    {0, 0, 0, 0, 0, 0, 0, 0},       {5, 5, 5, 5, 5, 5, 5, 5},
    {1, 1, 2, 3, 3, 2, 1, 1},       {0.5, 0.5, 1, 2.5, 2.5, 1, 0.5, 0.5},
    {0, 0, 0, 2, 2, 0, 0, 0},       {0.5, -0.5, -1, 0, 0, -1, -0.5, -0.5},
    {0.5, 1, 1, -2, -2, 1, 1, 0.5}, {0, 0, 0, 0, 0, 0, 0, 0},
};
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_KNIGHT = {
    {-5, -4, -3, -3, -3, -3, -4, -5}, {-4, -2, 0, 0, 0, 0, -2, -4},
    {-3, 0, 1, 1.5, 1.5, 1, 0, -3},   {-3, 0.5, 1.5, 2, 2, 1.5, 0.5, -3},
    {-3, 0, 1.5, 2, 2, 1.5, 0, -3},   {-3, 0.5, 1, 1.5, 1.5, 1, 0.5, -3},
    {-4, -2, 0, 0.5, 0.5, 0, -2, -4}, {-5, -4, -3, -3, -3, -3, -4, -5},
};
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_BISHOP = {
    {-2, -1, -1, -1, -1, -1, -1, -2}, {-1, 0, 0, 0, 0, 0, 0, -1},
    {-1, 0, 0.5, 1, 1, 0.5, 0, -1},   {-1, 0.5, 0.5, 1, 1, 0.5, 0.5, -1},
    {-1, 0, 1, 1, 1, 1, 0, -1},       {-1, 1, 1, 1, 1, 1, 1, -1},
    {-1, 0.5, 0, 0, 0, 0, 0.5, -1},   {-2, -1, -1, -1, -1, -1, -1, -2},
};
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_ROOK = {
    {0, 0, 0, 0, 0, 0, 0, 0},       {0.5, 1, 1, 1, 1, 1, 1, 0.5},
    {-0.5, 0, 0, 0, 0, 0, 0, -0.5}, {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
    {-0.5, 0, 0, 0, 0, 0, 0, -0.5}, {-0.5, 0, 0, 0, 0, 0, 0, -0.5},
    {-0.5, 0, 0, 0, 0, 0, 0, -0.5}, {0, 0, 0, 0.5, 0.5, 0, 0, 0},
};
static std::vector<std::vector<float>> WHITE_POSITION_RATIO_QUEEN = {
    {-2, -1, -1, -0.5, -0.5, -1, -1, -2},
    {-1, 0, 0, 0, 0, 0, 0, -1},
    {-1, 0, 0.5, 0.5, 0.5, 0.5, 0, -1},
    {-0.5, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
    {0, 0, 0.5, 0.5, 0.5, 0.5, 0, -0.5},
    {-1, 0.5, 0.5, 0.5, 0.5, 0.5, 0, -1},
    {-1, 0, 0.5, 0, 0, 0, 0, -1},
    {-2, -1, -1, -0.5, -0.5, -1, -1, -2},
};
} // namespace TablePositionRatioYX
