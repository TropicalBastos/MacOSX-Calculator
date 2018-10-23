#include "State/state.h"
#include "MainWindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    State state{ false };
    w.setState(state);
    w.setWindowTitle("Calculator");
    w.setFixedSize(w.width(), w.height());
    w.setWindowFlags(Qt::Dialog);
    w.initControls();
    w.show();

    return a.exec();
}
