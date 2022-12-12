#pragma once

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPoint>
#include <src/utils.h>

class GuiScene : public QGraphicsScene {
  Q_OBJECT
signals:
  void mousePress(Position position);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
