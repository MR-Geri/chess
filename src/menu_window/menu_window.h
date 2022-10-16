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

public slots:
  void go_to_settings();
  void go_to_chose_game();
  void go_to_liderboard();
  void exit();

signals:
  void change_window(int on_window);

private:
    Ui::MenuWindow *ui;
};
