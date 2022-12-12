#include "gui_scene.h"
#include "qgraphicssceneevent.h"

void GuiScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QPointF p = event->scenePos();
  emit mousePress(Position(static_cast<int>(p.x()), static_cast<int>(p.y())));
  QGraphicsScene::mousePressEvent(event);
}
