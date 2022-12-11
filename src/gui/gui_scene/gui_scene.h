#pragma once

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <src/utils.h>

class GuiScene : public QGraphicsScene
{
  Q_OBJECT
signals:
  void mousePress(Position position);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

