#include "State/state.h"
#include "MainWindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    State.operationPerformed = false;
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calculator");
    w.setFixedSize(w.width(), w.height());
    w.setWindowFlags(Qt::Dialog);
    w.show();

    return a.exec();
}
