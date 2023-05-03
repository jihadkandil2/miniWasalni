#include "UserWindow.h"
#include "ui_UserForm.h"



UserWindow:: UserWindow(QWidget *parent)
	: QWidget(parent), ui(new Ui::UserForm)
{
	ui->setupUi(this);

}

UserWindow::~UserWindow()
{
	delete ui;
}
