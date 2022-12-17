#include "settings.h"

Settings::Settings() {
  load();
  save();
}

void Settings::load() {
  std::cout << "LOAD\n";
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
      // QStringList books;
      m_music_flag = jsonObj.take("music_flag").toBool();
      m_music_volume = jsonObj.take("music_volume").toInt();
      m_sound_flag = jsonObj.take("sound_flag").toBool();
      m_sound_volume = jsonObj.take("sound_volume").toInt();
      // books << "book1"
      //       << "book2";
      // for (auto book : books) {
      //   if (jsonObj.contains(book)) {
      //     QJsonObject obj = jsonObj.value(book).toObject();
      //     QStringList keys = obj.keys();
      //     for (auto key : keys) {
      //       auto value = obj.take(key);
      //       if (value.isDouble()) {
      //         qDebug() << key << " : " << value.toDouble();
      //       } else if (value.isString()) {
      //         qDebug() << key << " : " << value.toString();
      //       }
      //     }
      //   }
      // }
    }
  }
}

void Settings::save() {
  std::cout << "SAVE\n";
  QJsonObject settings;
  settings.insert("music_flag", m_music_flag);
  settings.insert("music_volume", m_music_volume);
  settings.insert("sound_flag", m_sound_flag);
  settings.insert("sound_volume", m_sound_volume);

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
