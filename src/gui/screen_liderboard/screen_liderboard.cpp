#include "screen_liderboard.h"
#include "ui_screen_liderboard.h"

ScreenLiderboard::ScreenLiderboard(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenLiderboard) {
  ui->setupUi(this);

  connect(ui->buttonBackLiderboard, SIGNAL(released()), this,
          SLOT(buttonBackLiderboard_released()));
}

ScreenLiderboard::~ScreenLiderboard() { delete ui; }

void ScreenLiderboard::buttonBackLiderboard_released() {
  emit change_window(Windows::MENU);
}

void ScreenLiderboard::add_new_record(QString record) {}
