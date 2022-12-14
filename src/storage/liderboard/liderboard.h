#pragma once

#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <iostream>
#include <qlist.h>

#include "src/utils.h"

/**
 * @class Liderboard
 * @brief Хранение в базе таблицы лидеров.
 *
 */
class Liderboard : public QObject {
  Q_OBJECT
public:
  Liderboard();
  ~Liderboard();

  /**
   * @brief Получить таблицу лидеров
   */
  QList<Party> getData();

public slots:
  // void deleteAllData();

  /**
   * @brief Добавить запись о партии в таблицу
   */
  void addRecord(Party new_party);

private:
  QString path = QDir::currentPath() + "/liderboard.json";
  QList<Party> m_parties;

  /**
   * @brief Сохранить таблицу лидеров в файл.
   */
  void save();

  /**
   * @brief Загрузить таблицу лидеров из файла.
   */
  void load();
};
