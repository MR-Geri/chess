#include "gui_scene.h"
#include "qgraphicssceneevent.h"

void GuiScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QPointF p = event->scenePos();
  QGraphicsItem *item = itemAt(event->scenePos(), QTransform());
  if (item == board)
    emit mousePress(Position(static_cast<int>(p.x()), static_cast<int>(p.y())));
  QGraphicsScene::mousePressEvent(event);
}
