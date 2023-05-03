#include "Wasalni.h"
#include <QtWidgets/QApplication>
#include <ui_Wasalni.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wasalni w;
    w.setWindowTitle("Hello WASALNI");
    w.show();
    return a.exec();
}
