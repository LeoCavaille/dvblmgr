#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//a new object MainWindow is created
    w.show();//the window is displayed

    return a.exec();
}
