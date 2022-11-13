#include "gui_figure.h"

GuiFigure::GuiFigure(QGraphicsItem *parent) : QGraphicsSvgItem(parent) {}

GuiFigure::GuiFigure(float w_gV, float h_gV, Figures figure, QGraphicsItem *parent) : QGraphicsSvgItem(parent) {
  renderer = new QSvgRenderer(QString(":/images/figures/") + QString::number(figure) +  QString(".svg"));
  this->setSharedRenderer(renderer);
  float width_figure = this->boundingRect().size().width();
  float height_figure = this->boundingRect().size().height();
  scale = (std::min(w_gV, h_gV) - 40) / (width_figure * 8);
  this->setScale(scale);
  this->setFlag(QGraphicsItem::ItemIsMovable, true);
  last_delta_move.x = 0;
  last_delta_move.y = 0;
}

GuiFigure::~GuiFigure() {
  delete renderer;
}

void GuiFigure::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    last_delta_move.x = event->pos().x();
    last_delta_move.y = event->pos().y();
    x = this->scenePos().x();
    y = this->scenePos().y();
    QGraphicsItem::mousePressEvent(event);
}

void GuiFigure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    last_delta_move.x -= event->pos().x();
    last_delta_move.y -= event->pos().y();
    this->setPos(x, y);
    emit moved(Position(last_delta_move.x, last_delta_move.y));
    QGraphicsItem::mouseReleaseEvent(event);
}

