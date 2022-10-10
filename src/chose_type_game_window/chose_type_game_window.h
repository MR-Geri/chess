#pragma once

#include <QWidget>

namespace Ui {
class ChoseTypeGameWindow;
}

class ChoseTypeGameWindow : public QWidget {
    Q_OBJECT

public:
    explicit ChoseTypeGameWindow(QWidget *parent = nullptr);
    ~ChoseTypeGameWindow();

private:
    Ui::ChoseTypeGameWindow *ui;
};
