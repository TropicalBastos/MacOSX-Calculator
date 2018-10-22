#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QList>
#include "../Calculator/calculator.h"
#include "../UnaryControls/unary_controls.h"
#include "../Digit/digit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel* display;

private:
    Ui::MainWindow *ui;
    QPushButton* addButton;
    QPushButton* subtractButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;
    QPushButton* equalsButton;
    Calculator* calculatorHandle;
    UnaryControls* unaryControls;
    Digit* digitControls;
    void initEventListeners();
};

#endif // MAINWINDOW_H
