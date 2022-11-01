#pragma once

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
enum StatusMove { DONE, FAIL, GO_OUT, IMPOSSIBLE_MOVE, MOVE_TO_YOUR_FIGURE };

/**
 * @brief Перечисление, содержащее веса фигур.
 */
enum FiguresPrice { KING = -1, PAWN = 1, KINGHT, BISHOP, ROOK, QUEEN };

enum FigureColor { WHITE, BLACK };
