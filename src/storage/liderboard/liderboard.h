#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>
#include <qlist.h>

#include "src/utils.h"

class Liderboard {
public:
  Liderboard();

  QList<Party> getData();

public slots:
  void deleteAllData();
  void addRecord();

private:
  QString path = "./data/liderboard.json";
  QList<Party> m_parties;

  void save();
  void load();
};
