#include "settings_window.h"
#include "ui_settings_window.h"

SettingsWindow::SettingsWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::SettingsWindow) {
  ui->setupUi(this);

  connect(ui->buttonBackSettings, SIGNAL(released()), this,
          SLOT(buttonBackSettings_released()));
}

SettingsWindow::~SettingsWindow() { delete ui; }

void SettingsWindow::buttonBackSettings_released() {
  emit change_window(Windows::MENU);
}

void SettingsWindow::start_music() {}
void SettingsWindow::stop_music() {}
void SettingsWindow::start_sounds() {}
void SettingsWindow::stop_sounds() {}
void SettingsWindow::change_music_volume() {}
void SettingsWindow::change_sounds_volume() {}
