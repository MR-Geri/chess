#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget {
  Q_OBJECT

public:
  explicit SettingsWindow(QWidget *parent = nullptr);
  ~SettingsWindow();

signals:
  void change_window(int on_window);

private slots:
  void buttonBackSettings_released();

private:
  Ui::SettingsWindow *ui;
};
