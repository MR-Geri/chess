#include "screen_settings.h"
#include "ui_screen_settings.h"

ScreenSettings::ScreenSettings(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenSettings) {
  ui->setupUi(this);

  connect(ui->buttonBackSettings, SIGNAL(released()), this,
          SLOT(buttonBackSettings_released()));
}

ScreenSettings::~ScreenSettings() { delete ui; }

void ScreenSettings::buttonBackSettingsReleased() {
  emit changeWindow(Windows::MENU);
}

void ScreenSettings::startMusic() {}
void ScreenSettings::stopMusic() {}
void ScreenSettings::startSounds() {}
void ScreenSettings::stopSounds() {}
void ScreenSettings::changeMusicVolume() {}
void ScreenSettings::changeSoundsVolume() {}
