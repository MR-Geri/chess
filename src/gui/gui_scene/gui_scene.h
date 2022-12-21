#pragma once

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPoint>
#include <src/utils.h>

/**
 * @brief Графическая сцена, которая используется для отрисовки поля и фигур.
 */
class GuiScene : public QGraphicsScene {
  Q_OBJECT
signals:
  void mousePress(Position position);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
  QGraphicsItem *board;
};
