#pragma once

#include <QGraphicsSceneEvent>
#include <QGraphicsSvgItem>
#include <QString>
#include <QSvgRenderer>
#include <src/utils.h>

/**
 * @brief Класс фигуры победного хода.
 */
class GuiWin : public QGraphicsSvgItem {
  Q_OBJECT
public:
  GuiWin(QGraphicsItem *parent = nullptr);
  GuiWin(float size_rect, QString color, QGraphicsItem *parent = nullptr);
  ~GuiWin();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:

  /**
   * @brief Издается при нажатии на фигуру. Приводит к завершению партии.
   */
  void press(Position);

private:
  float size;
  QSvgRenderer *renderer;
  bool is_white;
};
