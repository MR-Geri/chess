#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenSettings;
}

/*!
 * \brief The SettingsWindow class
 * класс наследник стандартного класса QT - QWidget.
 * Класс - окно настроек.
 */
class ScreenSettings : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief SettingsWindow
   * конструктор.
   * \param parent
   */
  explicit ScreenSettings(QWidget *parent = nullptr);
  ~ScreenSettings();

signals:
  /*!
   * \brief change_window
   * сигнал, который показывает менеджеру окон на какое окно
   * нужно перейти.
   * \param on_window
   * окно на которое нужно переместиться.
   */
  void change_window(int on_window);

private slots:
  /*!
   * \brief buttonBackSettings_released
   * слот для обработки нажатия кнопки.
   * Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackSettings_released();
  /*!
   * \brief start_music
   * слот включающий музыку.
   */
  void start_music();
  /*!
   * \brief stop_music
   * слот выключающий музыку.
   */
  void stop_music();
  /*!
   * \brief start_sounds
   * слот включающий звуки.
   */
  void start_sounds();
  /*!
   * \brief stop_sounds
   * слот выключающий звуки.
   */
  void stop_sounds();
  /*!
   * \brief change_music_volume
   * слот, изменяющий громкость музыки.
   */
  void change_music_volume();
  /*!
   * \brief change_sounds_volume
   * слот, изменяющий громкость звуков.
   */
  void change_sounds_volume();

private:
  Ui::ScreenSettings *ui;
};
