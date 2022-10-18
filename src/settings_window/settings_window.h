#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class SettingsWindow;
}

/*!
 * \brief The SettingsWindow class
 * Класс наследник стандартного класса QT - QWidget.
 * Класс - окно настроек.
 */
class SettingsWindow : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief SettingsWindow
   * Конструктор.
   * \param parent
   */
  explicit SettingsWindow(QWidget *parent = nullptr);
  ~SettingsWindow();

signals:
  /*!
   * \brief change_window
   * Сигнал, который показываем менеджеру окон на какое окно
   * нужно перейти.
   * \param on_window
   * Окно на которое нужно переместиться.
   */
  void change_window(int on_window);

private slots:
  /*!
   * \brief buttonBackSettings_released
   * Слот для обработки нажатия кнопки.
   * Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackSettings_released();
  /*!
   * \brief start_music
   * Слот включающий музыку.
   */
  void start_music();
  /*!
   * \brief stop_music
   * Слот выключающий музыку.
   */
  void stop_music();
  /*!
   * \brief start_sounds
   * Слот включающий звуки.
   */
  void start_sounds();
  /*!
   * \brief stop_sounds
   * Слот выключающий звуки.
   */
  void stop_sounds();
  /*!
   * \brief change_music_volume
   * Слот, изменяющий громкость музыки.
   */
  void change_music_volume();
  /*!
   * \brief change_sounds_volume
   * Слот, изменяющий громкость звуков.
   */
  void change_sounds_volume();

private:
  Ui::SettingsWindow *ui;
};
