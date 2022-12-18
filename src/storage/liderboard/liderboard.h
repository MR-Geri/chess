#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class Liderboard {
public:
 Liderboard Settings();

 void getData();

public slots:
  void deleteAllData();
  void addRecord();

private:
  QString path = "./data/liderboard.json";

  void save();
  void load();
};
