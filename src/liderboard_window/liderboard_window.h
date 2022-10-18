#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class LiderboardWindow;
}

/*!
 * \brief The LiderboardWindow class
 * Класс наследник стандартного класса QT - QWidget.
 * Класс - окно табллицы лидеров.
 */
class LiderboardWindow : public QWidget {
  Q_OBJECT

public:
  /*!
   * \brief LiderboardWindow
   * Конструктор
   * \param parent
   */
  explicit LiderboardWindow(QWidget *parent = nullptr);
  ~LiderboardWindow();

signals:
  /*!
   * \brief change_window
   * Сигнал, который показываем менеджеру окон на какое окно
   * нужно перейти.
   * \param on_window
   * Окно на которое нужно переместиться.
   */
  void change_window(int on_window);

public slots:
  /*!
   * \brief add_new_record
   * Слот, добавляющИй новую запись в таблицу.
   * \param record
   * Запись, которую нужно добавить.
   */
  void add_new_record(QString record);

private slots:
  /*!
   * \brief buttonBackLiderboard_released
   * Слот для обработки нажатия кнопки.
   * Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackLiderboard_released();

private:
  Ui::LiderboardWindow *ui;
};
