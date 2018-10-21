#include "MainWindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator");
    w.setFixedSize(w.width(), w.height());
    w.setWindowFlags(Qt::Dialog);
    w.show();

    return a.exec();
}
