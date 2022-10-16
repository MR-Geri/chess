#pragma once

#include <QWidget>
#include <src/constants.h>

namespace Ui {
class ChoseTypeGameWindow;
}

class ChoseTypeGameWindow : public QWidget {
    Q_OBJECT

public:
    explicit ChoseTypeGameWindow(QWidget *parent = nullptr);
    ~ChoseTypeGameWindow();

  signals:
    void change_window(int on_window);

  private slots:
    void buttonDualGame_2_released();
    void buttonJuniorGame_2_released();
    void buttonMiddleGame_2_released();
    void buttonSeniorGame_2_released();

  private:
    Ui::ChoseTypeGameWindow *ui;
};
