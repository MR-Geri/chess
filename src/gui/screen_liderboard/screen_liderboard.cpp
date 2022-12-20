#include "screen_liderboard.h"
#include "ui_screen_liderboard.h"
#include <iostream>

ScreenLiderboard::ScreenLiderboard(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenLiderboard) {
  ui->setupUi(this);

  QList<QString> headers;
  headers.append("Белые");
  headers.append("Черные");
  headers.append("Победитель");
  QStringList headers_list = QStringList(headers);
  ui->tableLiderboard->setColumnCount(3);
  ui->tableLiderboard->setHorizontalHeaderLabels(headers_list);
  ui->tableLiderboard->horizontalHeader()->setStretchLastSection(true);
  count_parties = 0;

  connect(ui->buttonBackLiderboard, SIGNAL(released()), this,
          SLOT(buttonBackLiderboardReleased()));
}

ScreenLiderboard::~ScreenLiderboard() { delete ui; }

void ScreenLiderboard::buttonBackLiderboardReleased() {
  emit changeWindow(Windows::MENU);
}

void ScreenLiderboard::addNewRecord(Party new_party) {
  std::cout << "Added: " << new_party.players.first.toStdString() << " - " << new_party.players.second.toStdString() << std::endl;
  ui->tableLiderboard->insertRow(count_parties);
  ui->tableLiderboard->setItem(count_parties, 0, new QTableWidgetItem(new_party.players.first));
  ui->tableLiderboard->setItem(count_parties, 1, new QTableWidgetItem(new_party.players.second));
  ui->tableLiderboard->setItem(count_parties, 2, new QTableWidgetItem(new_party.id_player_win == 1 ? "белые" : "черные"));
  ui->tableLiderboard->resizeColumnsToContents();
  count_parties++;
}
