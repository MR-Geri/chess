#include "settings.h"

Settings::Settings() : QObject() { load(); }

Settings::~Settings() { save(); }

void Settings::load() {
  std::cout << "LOAD settings\n";
  QFile file(path);
  if (file.open(QIODevice::ReadOnly)) {
    QByteArray bytes = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
    if (jsonError.error != QJsonParseError::NoError) {
      std::cout << "fromJson failed: " << jsonError.errorString().toStdString()
                << std::endl;
      return;
    }
    if (document.isObject()) {
      QJsonObject jsonObj = document.object();
      m_music_flag = jsonObj.take("music_flag").toBool();
      std::cout << "music_flag " << m_music_flag << "\n";
      m_music_volume = jsonObj.take("music_volume").toInt();
      std::cout << "music_volume " << m_music_volume << "\n";
      m_sound_flag = jsonObj.take("sound_flag").toBool();
      std::cout << "soind_flag " << m_sound_flag << "\n";
      m_sound_volume = jsonObj.take("sound_volume").toInt();
      std::cout << "sound_volume " << m_sound_volume << "\n";
    }
  }
}

void Settings::save() {
  std::cout << "SAVE settings\n";
  QJsonObject settings;
  settings.insert("music_flag", m_music_flag);
  std::cout << "music_flag " << m_music_flag;
  settings.insert("music_volume", m_music_volume);
  std::cout << "\nmusic_volume " << m_music_volume;
  settings.insert("sound_flag", m_sound_flag);
  std::cout << "\nsoind_flag " << m_sound_flag;
  settings.insert("sound_volume", m_sound_volume);
  std::cout << "\nsound_volume " << m_sound_volume;

  QJsonDocument document;
  document.setObject(settings);
  QByteArray bytes = document.toJson(QJsonDocument::Indented);
  QFile file(path);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
    QTextStream iStream(&file);
    iStream.setCodec("utf-8");
    iStream << bytes;
    file.close();
  } else {
    std::cout << "file open failed: " << path.toStdString() << std::endl;
  }
}

void Settings::changeMusicFlag(bool flag) { m_music_flag = flag; }

void Settings::changeMusicVolume(int volume) { m_music_volume = volume; }

void Settings::changeSoundFlag(bool flag) { m_sound_flag = flag; }

void Settings::changeSoundVolume(int volume) { m_sound_volume = volume; }

int Settings::getMusicVolume() { return m_music_volume; }

bool Settings::getMusicFlag() { return m_music_flag; }

int Settings::getSoundVolume() { return m_sound_volume; }

bool Settings::getSoundFlag() { return m_sound_flag; }
