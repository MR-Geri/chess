#include "liderboard_window.h"
#include "ui_liderboard_window.h"

LiderboardWindow::LiderboardWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::LiderboardWindow) {
  ui->setupUi(this);
}

LiderboardWindow::~LiderboardWindow() { delete ui; }
