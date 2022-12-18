#pragma once

#include <QGraphicsSceneEvent>
#include <QGraphicsSvgItem>
#include <QString>
#include <QSvgRenderer>
#include <src/utils.h>

class GuiWin : public QGraphicsSvgItem {
  Q_OBJECT
public:
  GuiWin(QGraphicsItem *parent = nullptr);
  GuiWin(float size_rect, QString color, QGraphicsItem *parent = nullptr);
  ~GuiWin();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
  void press(Position);

private:
  float size;
  QSvgRenderer *renderer;
};
