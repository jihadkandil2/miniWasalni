#include "Wasalni.h"
#include "UserWindow.h"


Wasalni::Wasalni(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.ExitButton, &QPushButton::clicked, this, &Wasalni::onExitButtonClicked);
    connect(ui.UserButton, SIGNAL(clicked()), this, SLOT(openUserWindow()));
}
void Wasalni::onExitButtonClicked()
{
    qApp->exit();
}
void Wasalni::openUserWindow()
{
    UserWindow* newWindow = new UserWindow();
    newWindow->show();
}
Wasalni::~Wasalni()
{}
