/********************************************************************************
** Form generated from reading UI file 'UserForm.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERFORM_H
#define UI_USERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserForm
{
public:

    void setupUi(QWidget *UserForm)
    {
        if (UserForm->objectName().isEmpty())
            UserForm->setObjectName("UserForm");
        UserForm->resize(689, 414);
        UserForm->setStyleSheet(QString::fromUtf8("background-color: #F1DEC9;"));

        retranslateUi(UserForm);

        QMetaObject::connectSlotsByName(UserForm);
    } // setupUi

    void retranslateUi(QWidget *UserForm)
    {
        UserForm->setWindowTitle(QCoreApplication::translate("UserForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserForm: public Ui_UserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERFORM_H
