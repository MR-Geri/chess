#include "settings_window.h"
#include "ui_settings_window.h"

SettingsWindow::SettingsWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::SettingsWindow) {
  ui->setupUi(this);
}

SettingsWindow::~SettingsWindow() { delete ui; }
