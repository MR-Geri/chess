#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ScreenMenu;
}

/**
 * @brief Наследник стандартного класса QT - QWidget.
 * Класс - окно меню.
 */
class ScreenMenu : public QWidget {
  Q_OBJECT

public:
  explicit ScreenMenu(QWidget *parent = nullptr);
  ~ScreenMenu();

signals:
  /**
   * @brief Показывает менеджеру окон на какое окно нужно перейти.
   * @param on_window
   * окно на которое нужно переместиться.
   */
  void changeWindow(int on_window);

private slots:
  /**
   * @brief Отправляет сигнал о смене окна на окно настроек.
   */
  void goToSettings();
  /**
   * @brief Отправляет сигнал о смене окна на окно игрового поля.
   */
  void goToGameField();
  /**
   * @brief Отправляет сигнал о смене окна на окно таблицы лидеров.
   */
  void goToLiderboard();
  /**
   * @brief Отправляет сигнал выходе из приложения.
   */
  void exit();

private:
  Ui::ScreenMenu *ui;
};
