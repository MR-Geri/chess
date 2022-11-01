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

  int &x() { return first; }
  const int &x() const { return first; }

  int &y() { return second; }
  const int &y() const { return second; }
};
