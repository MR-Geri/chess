#pragma once

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QDir>
#include <iostream>

/**
 * @class Settings
 * @brief Хранение в базе настроек приложения.
 */
class Settings : public QObject {
public:
  Settings();
  ~Settings();

  /**
   * @brief Возвращает значение громкости музыки
   *
   * @return значение в int 0..100
   */
  int getMusicVolume();

  /**
   * @brief Возвращает флаг музыки [On, Off]
   *
   * @return флаг
   */
  bool getMusicFlag();

  /**
   * @brief Возвращает значение громкости звуков
   *
   * @return значение в int 0..100
   */
  int getSoundVolume();

  /**
   * @brief Возвращает флаг звуков [On, Off]
   *
   * @return флаг
   */
  bool getSoundFlag();

public slots:
  /**
   * @brief Сохранение изменений громкости музыки
   *
   * @param value значение громкости в int 0..100
   */
  void changeMusicVolume(int value);

  /**
   * @brief Сохранение изменений флага звуков
   */
  void changeSoundVolume(int value);

  /**
   * @brief Сохранение изменений флага музыки
   */
  void changeMusicFlag(bool flag);

  /**
   * @brief Сохранение изменений громкости звуков
   *
   * @param value значение громкости в int 0..100
   */
  void changeSoundFlag(bool flag);

private:
  QString path = QDir::currentPath() + "/settings.json";

  int m_music_volume;
  bool m_music_flag;
  int m_sound_volume;
  bool m_sound_flag;

  /**
   * @brief Сохранить настройки в файл
   */
  void save();

  /**
   * @brief Загрузить настройки из файла
   */
  void load();
};
