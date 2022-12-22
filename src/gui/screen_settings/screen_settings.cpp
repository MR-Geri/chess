#include "screen_settings.h"
#include "ui_screen_settings.h"
#include <iostream>

ScreenSettings::ScreenSettings(QWidget *parent)
    : QWidget(parent), ui(new Ui::ScreenSettings) {
  ui->setupUi(this);

  music_volume = ui->horizontalSlider->value();
  sounds_volume = ui->horizontalSlider_2->value();
  music_player = new QMediaPlayer(this);
  music_player = new QMediaPlayer(this);
  music_playlist = new QMediaPlaylist(music_player);
  music_playlist->addMedia(QUrl("qrc:/sounds/music.mp3"));
  music_player->setPlaylist(music_playlist);
  music_player->setVolume(music_volume);
  music_playlist->setPlaybackMode(QMediaPlaylist::Loop);
  sounds_player = new QMediaPlayer(this);
  sounds_player = new QMediaPlayer(this);
  sounds_playlist = new QMediaPlaylist(sounds_player);
  sounds_player->setPlaylist(sounds_playlist);
  sounds_player->setVolume(sounds_volume);
  sounds_player->play();

  connect(ui->buttonBackSettings, SIGNAL(released()), this,
          SLOT(buttonBackSettingsReleased()));
}

ScreenSettings::~ScreenSettings() {
  delete ui;
  delete music_playlist;
  delete sounds_playlist;
  delete music_player;
  delete sounds_player;
}

void ScreenSettings::buttonBackSettingsReleased() {
  emit changeWindow(Windows::MENU);
}

void ScreenSettings::on_checkBox_stateChanged(int arg1) {
  std::cout << arg1 << std::endl;
  if (arg1 == 0) {
    music_player->stop();
    emit changeMusicFlag(false);
  } else {
    music_player->play();
    emit changeMusicFlag(true);
  }
}

void ScreenSettings::on_horizontalSlider_valueChanged(int value) {
  music_volume = value;
  music_player->setVolume(music_volume);
  emit changeMusicVolume(music_volume);
  std::cout << music_volume << std::endl;
}

void ScreenSettings::on_checkBox_2_stateChanged(int arg1) {
  std::cout << arg1 << std::endl;
  if (arg1 == 0) {
    sounds_player->stop();
    emit changeSoundsFlag(false);
  } else {
    sounds_playlist->clear();
    sounds_player->play();
    emit changeSoundsFlag(true);
  }
}

void ScreenSettings::on_horizontalSlider_2_valueChanged(int value) {
  sounds_volume = value;
  sounds_player->setVolume(sounds_volume);
  emit changeSoundsVolume(sounds_volume);
  std::cout << sounds_volume << std::endl;
}

void ScreenSettings::playSoundStep() {
  sounds_playlist->addMedia(QUrl("qrc:/sounds/step.mp3"));
  std::cout << "STEP!" << std::endl;
}

void ScreenSettings::setPlayersData(bool is_music_active, bool is_sounds_active,
                                    int music_volume, int sounds_volume) {
  this->music_volume = music_volume;
  this->sounds_volume = sounds_volume;
  ui->checkBox->setCheckState(is_music_active ? Qt::Checked : Qt::Unchecked);
  ui->checkBox_2->setCheckState(is_sounds_active ? Qt::Checked : Qt::Unchecked);
  ui->horizontalSlider->setValue(music_volume);
  ui->horizontalSlider_2->setValue(sounds_volume);
  if (is_music_active) music_player->play();
  if (is_sounds_active) sounds_player->play();
}
