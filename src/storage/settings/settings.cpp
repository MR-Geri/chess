#include "settings.h"

struct Book {
  std::string name;
  double price;
  Book(std::string _name, double _price) {
    name = _name;
    price = _price;
  }
};

void CreateJson(const QString &path) {
  Book obj1("high school mathematics", 12);
  QJsonObject book1;
  book1.insert("name", obj1.name.c_str());
  book1.insert("price", obj1.price);

  Book obj2("advanced high school mathematics", 14);
  QJsonObject book2;
  book2.insert("name", obj2.name.c_str());
  book2.insert("price", obj2.price);

  QJsonObject content;
  content.insert("book1", book1);
  content.insert("book2", book2);

  QJsonDocument document;
  document.setObject(content);
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

void ReadJson(const QString &path) {
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
      QStringList books;
      books << "book1"
            << "book2";
      for (auto book : books) {
        if (jsonObj.contains(book)) {
          QJsonObject obj = jsonObj.value(book).toObject();
          QStringList keys = obj.keys();
          for (auto key : keys) {
            auto value = obj.take(key);
            if (value.isDouble()) {
              qDebug() << key << " : " << value.toDouble();
            } else if (value.isString()) {
              qDebug() << key << " : " << value.toString();
            }
          }
        }
      }
    }
  }
}

int testJson() {
  QString path = "data/tests.json";
  CreateJson(path);
  ReadJson(path);
  return 0;
}
