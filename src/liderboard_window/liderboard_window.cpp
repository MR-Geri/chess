#include "liderboard_window.h"
#include "ui_liderboard_window.h"

LiderboardWindow::LiderboardWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::LiderboardWindow) {
  ui->setupUi(this);

  connect(ui->buttonBackLiderboard, SIGNAL(released()), this,
          SLOT(buttonBackLiderboard_released()));
}

LiderboardWindow::~LiderboardWindow() { delete ui; }

void LiderboardWindow::buttonBackLiderboard_released() {
  emit change_window(Windows::MENU);
}
