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
enum FiguresPrice { KING = -1, PAWN = 1, KINGHT, BISHOP, ROOK, QUEEN };

/**
 * @brief Перечисление, содержащее цвета фигур.
 */
enum FigureColor { WHITE, BLACK };

enum Figures { NONE = 0,
               W_KING, W_PAWN, W_KINGHT, W_BISHOP, W_ROOK, W_QUEEN,
               B_KING, B_PAWN, B_KINGHT, B_BISHOP, B_ROOK, B_QUEEN};
