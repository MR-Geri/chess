#include "gui_win.h"

GuiWin::GuiWin(QGraphicsItem *parent) : QGraphicsSvgItem(parent) {}

GuiWin::GuiWin(float size_rect, QString color, QGraphicsItem *parent)
    : QGraphicsSvgItem(parent) {
  size = size_rect;
  is_white = color == "white" ? true : false;
  renderer = new QSvgRenderer(QString(":/images/winner_" + color + ".svg"));
  this->setSharedRenderer(renderer);
  float width_figure = this->boundingRect().size().width();
  float scale = size_rect / width_figure;
  this->setScale(scale);
}

void GuiWin::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  int x = event->scenePos().x();
  int y = event->scenePos().y();
  emit press({static_cast<int>(x + 1), static_cast<int>(y + 1)});
}

GuiWin::~GuiWin() { delete renderer; }
