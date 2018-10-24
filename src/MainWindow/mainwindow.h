#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QList>
#include "../Calculator/calculator.h"
#include "../UnaryControls/unary_controls.h"
#include "../OperationalControls/operational_controls.h"
#include "../Digit/digit.h"
#include "../State/state.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setState(State state);
    void initControls();
    QLabel* display;

private:
    Ui::MainWindow *ui;
    QPushButton* addButton;
    QPushButton* subtractButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;
    QPushButton* equalsButton;
    QPushButton* cancelButton;
    QPushButton* moduloButton;
    QPushButton* toggleSignButton;
    Calculator* calculatorHandle;
    UnaryControls* unaryControls;
    OperationalControls* operationalControls;
    Digit* digitControls;
    State* state;
    void initEventListeners();
};

#endif // MAINWINDOW_H
