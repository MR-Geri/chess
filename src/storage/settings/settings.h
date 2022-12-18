#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

/**
 * @class Settings
 * @brief Хранение в базе настроек приложения.
 */
class Settings {
public:
  Settings();

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
  void changeMusicVolume(int value);
  void changeSoundVolume(int value);
  void changeMusicFlag(bool flag);
  void changeSoundFlag(bool flag);

private:
  QString path = "./data/settings.json";

  int m_music_volume;
  bool m_music_flag;
  int m_sound_volume;
  bool m_sound_flag;

  void save();
  void load();
};
