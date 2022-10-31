#include "screen_liderboard.h"
#include "ui_screen_liderboard.h"

ScreenLiderboard::ScreenLiderboard(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenLiderboard) {
  ui->setupUi(this);

  connect(ui->buttonBackLiderboard, SIGNAL(released()), this,
          SLOT(buttonBackLiderboard_released()));
}

ScreenLiderboard::~ScreenLiderboard() { delete ui; }

void ScreenLiderboard::buttonBackLiderboardReleased() {
  emit changeWindow(Windows::MENU);
}

void ScreenLiderboard::addNewRecord(QString record) {}
