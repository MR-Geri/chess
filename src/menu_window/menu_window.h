#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget {
  Q_OBJECT

public:
  explicit MenuWindow(QWidget *parent = nullptr);
  ~MenuWindow();

signals:
  void change_window(int on_window);

private slots:
  void go_to_settings();
  void go_to_game_field();
  void go_to_liderboard();
  void exit();

private:
  Ui::MenuWindow *ui;
};
