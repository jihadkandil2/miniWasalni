#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Wasalni.h"

class Wasalni : public QMainWindow
{
    Q_OBJECT

public:
    Wasalni(QWidget *parent = nullptr);
    ~Wasalni();
    void onExitButtonClicked();

private:
    Ui::WasalniClass ui;

private slots:
    void openUserWindow();
};
