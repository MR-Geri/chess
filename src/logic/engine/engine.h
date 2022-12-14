#pragma once

#include "../../constants.h"
#include "../board/board.h"
#include "../figures/figures.h"

/**
 * @brief Движок игры. Реализует логику ходов.
 */
class Engine {
public:
  Engine();
  ~Engine();

  /**
   * @brief Проверяет возможность хода и перемещает фигуру.
   * @param from_pos позиция фигуры, которую нужно переместить
   * @param step шаг, на который переместить фигуру
   * @return статус перемещения StatusMove (Enum)
   */
  StatusMove move(Position from_pos, Position step);

  /**
   * @brief Расчет преимущества игрока.
   * @return расчитанное значение.
   */
  double calculateAdvantageWhite();

  /**
   * @brief Базовая расстановка фигур на поле.
   */
  void setStartingArrangement();

  /**
   * @brief Установка фигуры на доску.
   * @param figure указатель на фигуру, которую нужно поставить на поле.
   * @param position позиция на которую нужно поставить фигуру.
   * @return если установка прошла успешно - true, в противном случае - false.
   */
  bool setFigureOnBoard(Figure *figure, Position position);

  /**
   * @brief clearBoard очищает поле.
   */
  void clearBoard();

  /**
   * @brief getData возвращает поле.
   */
  std::vector<std::vector<Figure *>> getData();

  /**
   * @brief Количество противников, которые находятся под атакой.
   *
   * @param board поле
   * @param pos позиция фигуры для которой расчитывается заначение
   * @return int - количество противников под атакой
   */
  int enemyUnderAttack(std::vector<std::vector<Figure *>> board, Position pos);

  /**
   * @brief Количество возможных ходов.
   *
   * @param board поле
   * @param pos позиция фигуры для которой расчитывается заначение
   * @return int - количество возможных ходов
   */
  int quantityPossibleMove(std::vector<std::vector<Figure *>> board,
                           Position pos);

  /**
   * @brief Возможные атаки для фигуры.
   *
   * @param position список возможных атак
   */
  std::list<std::pair<Position, Figures>>
  getPosibleAttacksFigureFrom(Position position);

  /**
   * @brief Возможные ходы для фигуры.
   *
   * @param position список возможных ходов
   */
  std::list<std::list<Position>> getPosibleMovesFigureFrom(Position position);

  /**
   * @brief Проверка на конец игры.
   */
  int isEnd();

  FigureColor current_color;

private:
  Board *game_board;
  int is_game_end;
};
