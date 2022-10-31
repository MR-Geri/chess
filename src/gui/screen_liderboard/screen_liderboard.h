#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenLiderboard;
}

/*!
 * @brief The ScreenLiderboard
 * наследник стандартного класса QT - QWidget.
 * Класс - окно табллицы лидеров.
 */
class ScreenLiderboard : public QWidget {
  Q_OBJECT

public:
  /*!
   * @brief ScreenLiderboard
   * конструктор
   * @param parent
   */
  explicit ScreenLiderboard(QWidget *parent = nullptr);
  ~ScreenLiderboard();

signals:
  /*!
   * @brief change_window
   * сигнал, который показывает менеджеру окон на какое окно
   * нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void change_window(int on_window);

public slots:
  /*!
   * @brief add_new_record
   * слот, добавляющий новую запись в таблицу.
   * @param record
   * запись, которую нужно добавить.
   */
  void add_new_record(QString record);

private slots:
  /*!
   * @brief buttonBackLiderboard_released
   * слот для обработки нажатия кнопки.
   * Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackLiderboard_released();

private:
  Ui::ScreenLiderboard *ui;
};
