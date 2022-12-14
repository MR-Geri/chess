#pragma once

#include <QString>
#include <utility>

/**
 * @brief Позиция на поле (координаты).
 */
class Position : public std::pair<int, int> {
public:
  typedef std::pair<int, int> Base;
  Position() : Base() {}
  Position(const Position &pos) : Base(pos) {}
  Position(int x, int y) : Base(x, y) {}

  Position &operator=(const Position &r) {
    this->x = r.x;
    this->y = r.y;
    return *this;
  }

  int &x = this->first;
  int &y = this->second;
};

/**
 * @brief Хранение игроков и победителя в партии.
 */
struct Party {
  std::pair<QString, QString> players;
  int id_player_win;
};
