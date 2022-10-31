#pragma once

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

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   */
  void changeWindow(int on_window);

private slots:
  /**
   * @brief Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackSettingsReleased();
  /**
   * @brief Включает музыку.
   */
  void startMusic();
  /**
   * @brief Выключает музыку.
   */
  void stopMusic();
  /**
   * @brief Включает звуки.
   */
  void startSounds();
  /**
   * @brief Выключает звуки.
   */
  void stopSounds();
  /**
   * @brief Изменяет громкость музыки.
   */
  void changeMusicVolume();
  /**
   * @brief Изменяет громкость звуков.
   */
  void changeSoundsVolume();

private:
  Ui::ScreenSettings *ui;
};
