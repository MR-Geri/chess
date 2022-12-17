#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

class Settings {
public:
  Settings();

  int getMusicVolume();
  bool getMusicFlag();
  int getSoundVolume();
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
