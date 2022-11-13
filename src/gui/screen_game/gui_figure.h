#pragma once

#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QGraphicsSceneMouseEvent>
#include <src/constants.h>
#include <src/utils.h>

class GuiFigure : public QGraphicsSvgItem {
  Q_OBJECT
public:
  GuiFigure(QGraphicsItem *parent = nullptr);
  GuiFigure(float w_gV, float h_gV, Figures figure, QGraphicsItem *parent = nullptr);
  ~GuiFigure();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
  void moved(Position delta_position);

private:
  float scale;
  QSvgRenderer *renderer;
  Position last_delta_move;
  float x;
  float y;
};
