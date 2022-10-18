#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class MenuWindow;
}

/*!
 * \brief The MenuWindow class
 * Класс наследник стандартного класса QT - QWidget.
 * Класс - окно меню.
 */
class MenuWindow : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief MenuWindow
   * Конструктор.
   * \param parent
   */
  explicit MenuWindow(QWidget *parent = nullptr);
  ~MenuWindow();

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
   * \brief go_to_settings
   * Отправляет сигнал о смене окна на окно настроек.
   */
  void go_to_settings();
  /*!
   * \brief go_to_game_field
   * Отправляет сигнал о смене окна на окно игрового поля.
   */
  void go_to_game_field();
  /*!
   * \brief go_to_liderboard
   * Отправляет сигнал о смене окна на окно таблицы лидеров.
   */
  void go_to_liderboard();
  /*!
   * \brief exit
   * Отправляет сигнал выходе из приложения.
   */
  void exit();

private:
  Ui::MenuWindow *ui;
};
