#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class LiderboardWindow;
}

class LiderboardWindow : public QWidget {
  Q_OBJECT

public:
  explicit LiderboardWindow(QWidget *parent = nullptr);
  ~LiderboardWindow();

signals:
  void change_window(int on_window);

private slots:
  void buttonBackLiderboard_released();

private:
  Ui::LiderboardWindow *ui;
};
