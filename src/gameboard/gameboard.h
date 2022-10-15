#pragma once

#include <QGraphicsScene>
#include <QVector>
#include <src/figure/figure.h>

class GameBoard : public QGraphicsScene {
public:
  explicit GameBoard(QObject *parent = nullptr);

private:
  QVector<Figure *> figures;
};
