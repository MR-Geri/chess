#pragma once

#include <QWidget>

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

private:
    Ui::MenuWindow *ui;
};
