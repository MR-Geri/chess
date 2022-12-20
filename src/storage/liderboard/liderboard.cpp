#include "liderboard.h"
#include <utility>

Liderboard::Liderboard() : QObject() {
  load();
  save();
}

void Liderboard::load() {
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
      QJsonArray jsonArr = document.array();
      m_parties.clear();

      for (int i = 0; i < jsonArr.count(); ++i) {
        QJsonObject jsonObj = jsonArr.at(i).toObject();
        Party party;
        party.id_player_win = jsonObj.take("idPlayerWin").toInt();
        QString one(jsonObj.take("players").toArray()[0].toString());
        QString two(jsonObj.take("players").toArray()[1].toString());
        party.players = std::make_pair(one, two);
        m_parties.push_back(party);
      }
    }
  }
}

void Liderboard::save() {
  std::cout << "SAVE\n";
  QJsonArray parties;
  for (auto party : this->m_parties) {
    QJsonObject jsonParty;
    QJsonArray players;
    players.append(party.players.first);
    players.append(party.players.second);
    jsonParty["idPlayerWin"] = party.id_player_win;
    jsonParty["players"] = players;
    parties.append(jsonParty);
  }
  QJsonDocument document(parties);
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

void Liderboard::addRecord(Party new_party) { m_parties.append(new_party); }

QList<Party> Liderboard::getData() { return m_parties; }
