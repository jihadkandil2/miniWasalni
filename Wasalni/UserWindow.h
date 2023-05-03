#ifndef USERWINDOW_H
#define USERWINDOW_H
#pragma once

#include <QWidget>

namespace Ui {
	class UserForm;
}

class UserWindow  : public QWidget
{
	Q_OBJECT

public:
	explicit UserWindow(QWidget* parent = nullptr);
	~UserWindow();

private:
	Ui::UserForm* ui;
};


#endif // USERWINDOW_H