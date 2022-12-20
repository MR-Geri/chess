#pragma once

#include <QWidget>
#include <src/constants.h>
#include <src/utils.h>

namespace Ui {
class ScreenLiderboard;
}

/**
 * @brief Окно табллицы лидеров.
 */
class ScreenLiderboard : public QWidget {
  Q_OBJECT

public:
  explicit ScreenLiderboard(QWidget *parent = nullptr);
  ~ScreenLiderboard();

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void changeWindow(int on_window);

public slots:
  /**
   * @brief Добавляет новую запись в таблицу.
   * @param record
   * запись, которую нужно добавить.
   */
  void addNewRecord(Party new_party);

private slots:
  /**
   * @brief Отправляет сигнал о смене окна на окно меню.
   */
  void buttonBackLiderboardReleased();

private:
  Ui::ScreenLiderboard *ui;
  int count_parties;
};
