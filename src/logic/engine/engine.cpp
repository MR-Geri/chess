#include "engine.h"

Engine::Engine() {}

int Engine::move(QPair<int, int> from_pos, QPair<int, int> step) {
  if (step.first == 0 && step.second == 0) {
    // Отсутствие хода
    return 1;
  }
  if (abs(step.first) > 1 || abs(step.second) > 1) {
    // Невозможный ход
    return 2;
  }
  if ((from_cords.first + step.first) < 0 ||
      (from_cords.first + step.first) >= 8 ||
      (from_cords.second + step.second) < 0 ||
      (from_cords.second + step.second) >= 8) {
    // Выход за поле
    return 3;
  }

  // V Ошибка, если ход на/через собственную фигуру V
  if (0) {
    return 4;
  }
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  map[from_cords.first + step.first][from_cords.second + step.second] =
      map[from_cords.first][from_cords.second];
  map[from_cords.first][from_cords.second] = 0;
  return 0;
}
