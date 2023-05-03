/********************************************************************************
** Form generated from reading UI file 'Wasalni.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WASALNI_H
#define UI_WASALNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WasalniClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *AdminButton;
    QPushButton *UserButton;
    QPushButton *ExitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WasalniClass)
    {
        if (WasalniClass->objectName().isEmpty())
            WasalniClass->setObjectName("WasalniClass");
        WasalniClass->resize(854, 505);
        WasalniClass->setMaximumSize(QSize(854, 550));
        WasalniClass->setBaseSize(QSize(854, 450));
        WasalniClass->setStyleSheet(QString::fromUtf8("background-color: #F1DEC9;\n"
""));
        centralWidget = new QWidget(WasalniClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 20, 581, 150));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(581, 150));
        label->setBaseSize(QSize(581, 121));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Variable Display Semib")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(false);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background :#C8B6A6;\n"
"border-radius: 40px;\n"
"padding: 5px;\n"
"box-shadow: 50px 5px 10px rgba(10, 10, 50, 10);"));
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(22);
        AdminButton = new QPushButton(centralWidget);
        AdminButton->setObjectName("AdminButton");
        AdminButton->setGeometry(QRect(90, 350, 161, 71));
        AdminButton->setStyleSheet(QString::fromUtf8("background-color : #A9907E;\n"
"font: 22pt \"Segoe Fluent Icons\";\n"
""));
        UserButton = new QPushButton(centralWidget);
        UserButton->setObjectName("UserButton");
        UserButton->setGeometry(QRect(340, 350, 161, 71));
        UserButton->setStyleSheet(QString::fromUtf8("background-color : #A9907E;\n"
"font: 22pt \"Segoe Fluent Icons\";\n"
""));
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(600, 350, 141, 71));
        ExitButton->setStyleSheet(QString::fromUtf8("background-color : #A9907E;\n"
"font: 22pt \"Segoe Fluent Icons\";\n"
""));
        WasalniClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WasalniClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 854, 22));
        WasalniClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WasalniClass);
        mainToolBar->setObjectName("mainToolBar");
        WasalniClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WasalniClass);
        statusBar->setObjectName("statusBar");
        WasalniClass->setStatusBar(statusBar);

        retranslateUi(WasalniClass);
        QObject::connect(ExitButton, SIGNAL(clicked()), WasalniClass, SLOT(onExitButtonClicked()));
        QObject::connect(UserButton, &QPushButton::clicked, WasalniClass, qOverload<>(&QMainWindow::hide));

        QMetaObject::connectSlotsByName(WasalniClass);
    } // setupUi

    void retranslateUi(QMainWindow *WasalniClass)
    {
        WasalniClass->setWindowTitle(QCoreApplication::translate("WasalniClass", "Wasalni", nullptr));
#if QT_CONFIG(accessibility)
        label->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("WasalniClass", "<html><head/><body><p align=\"center\"><span style=\" color:#000000;\">welcome to </span><span style=\" color:#7c3d07;\">WASALNI</span></p><p align=\"center\">your way to get your destination on time </p></body></html>", nullptr));
        AdminButton->setText(QCoreApplication::translate("WasalniClass", "Admin", nullptr));
        UserButton->setText(QCoreApplication::translate("WasalniClass", "User", nullptr));
        ExitButton->setText(QCoreApplication::translate("WasalniClass", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WasalniClass: public Ui_WasalniClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WASALNI_H
