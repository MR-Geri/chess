#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenMenu;
}

/**
 * @brief The ScreeMenu
 * наследник стандартного класса QT - QWidget.
 * Класс - окно меню.
 */
class ScreenMenu : public QWidget {
  Q_OBJECT

public:
  /**
   * @brief ScreeMenu
   * конструктор.
   * @param parent
   */
  explicit ScreenMenu(QWidget *parent = nullptr);
  ~ScreenMenu();

signals:
  /**
   * @brief change_window
   * сигнал, который показывает менеджеру окон на какое окно
   * нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void change_window(int on_window);

private slots:
  /**
   * @brief go_to_settings
   * отправляет сигнал о смене окна на окно настроек.
   */
  void go_to_settings();
  /**
   * @brief go_to_game_field
   * отправляет сигнал о смене окна на окно игрового поля.
   */
  void go_to_game_field();
  /**
   * @brief go_to_liderboard
   * отправляет сигнал о смене окна на окно таблицы лидеров.
   */
  void go_to_liderboard();
  /**
   * @brief exit
   * отправляет сигнал выходе из приложения.
   */
  void exit();

private:
  Ui::ScreenMenu *ui;
};
