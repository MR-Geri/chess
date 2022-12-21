#pragma once

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenSettings;
}

/**
 * @brief Окно настроек.
 */
class ScreenSettings : public QWidget {
  Q_OBJECT

public:
  explicit ScreenSettings(QWidget *parent = nullptr);
  ~ScreenSettings();

  /**
   * @brief Устанавливает значения параметров настроек.
   * @param is_music_active флаг активности музыки.
   * @param is_sounds_active флаг активности звуков.
   * @param music_volume громкость музыки.
   * @param sounds_volume громкость звуков.
   */
  void setPlayersData(bool is_music_active, bool is_sounds_active,
                      int music_volume, int sounds_volume);

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   */
  void changeWindow(int on_window);

  /**
   * @brief Издается при изменении галочки включения музыки.
   */
  void changeMusicFlag(bool);

  /**
   * @brief Издается при изменении галочки включения звуков.
   */
  void changeSoundsFlag(bool);

  /**
   * @brief Издается при изменении громкости звука.
   */
  void changeMusicVolume(int);

  /**
   * @brief Издается при изменении громкости звука.
   */
  void changeSoundsVolume(int);

public slots:
  /**
   * @brief Проигрывает звук шага.
   */
  void playSoundStep();

private slots:
  /**
   * @brief Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackSettingsReleased();

  /**
   * @brief Включает музыку.
   */
  void on_checkBox_stateChanged(int arg1);

  /**
   * @brief Включает звуки.
   */
  void on_checkBox_2_stateChanged(int arg1);

  /**
   * @brief Изменяет громкость музыки.
   */
  void on_horizontalSlider_valueChanged(int value);

  /**
   * @brief Изменяет громкость звуков.
   */
  void on_horizontalSlider_2_valueChanged(int value);

private:
  Ui::ScreenSettings *ui;
  QMediaPlayer *music_player;
  QMediaPlaylist *music_playlist;
  QMediaPlayer *sounds_player;
  QMediaPlaylist *sounds_playlist;
  int music_volume;
  int sounds_volume;
};
