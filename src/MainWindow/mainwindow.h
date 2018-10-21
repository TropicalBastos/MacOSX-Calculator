#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "../Calculator/calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton* addButton;
    QPushButton* subtractButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;
    QLabel* display;
    Calculator* calculatorHandle;
    void initEventListeners();
    double getDisplayNumber();

private slots:
    void add();
    void subtract();
    void multiply();
    void divide();
};

#endif // MAINWINDOW_H
