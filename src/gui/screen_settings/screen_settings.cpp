#include "screen_settings.h"
#include "ui_screen_settings.h"

ScreenSettings::ScreenSettings(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenSettings) {
  ui->setupUi(this);

  connect(ui->buttonBackSettings, SIGNAL(released()), this,
          SLOT(buttonBackSettings_released()));
}

ScreenSettings::~ScreenSettings() { delete ui; }

void ScreenSettings::buttonBackSettings_released() {
  emit change_window(Windows::MENU);
}

void ScreenSettings::start_music() {}
void ScreenSettings::stop_music() {}
void ScreenSettings::start_sounds() {}
void ScreenSettings::stop_sounds() {}
void ScreenSettings::change_music_volume() {}
void ScreenSettings::change_sounds_volume() {}
