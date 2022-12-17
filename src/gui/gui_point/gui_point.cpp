#include "gui_point.h"

GuiPoint::GuiPoint(QGraphicsItem *parent) : QGraphicsObject(parent)
{

}

GuiPoint::GuiPoint(float size_cell, QGraphicsItem *parent) : QGraphicsObject(parent) {
  radius = size_cell * 0.15;
  size_rect = size_cell;
  this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

QRectF GuiPoint::boundingRect() const {
  return QRectF(-size_rect * 0.5, -size_rect * 0.5, size_rect, size_rect);
}

void GuiPoint::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
  painter->setPen(Qt::gray);
  painter->setBrush(Qt::green);
  painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
}

void GuiPoint::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  int x = event->scenePos().x();
  int y = event->scenePos().y();
  emit press({static_cast<int>(x + 1), static_cast<int>(y + 1)});
}
