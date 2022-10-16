#pragma once

#include <QWidget>

namespace Ui {
class LiderboardWindow;
}

class LiderboardWindow : public QWidget {
  Q_OBJECT

public:
  explicit LiderboardWindow(QWidget *parent = nullptr);
  ~LiderboardWindow();

private:
  Ui::LiderboardWindow *ui;
};
