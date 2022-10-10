#pragma once

#include <QWidget>

namespace Ui {
class GameFieldWindow;
}

class GameFieldWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameFieldWindow(QWidget *parent = nullptr);
    ~GameFieldWindow();

private:
    Ui::GameFieldWindow *ui;
};
