#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->addButton = ui->add;
    this->subtractButton = ui->subtract;
    this->multiplyButton = ui->multiply;
    this->divideButton = ui->divide;
    this->equalsButton = ui->equals;
    this->display = ui->display;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initEventListeners(){
    /** Delegate all unary controls to the appropriate class */
    UnaryControls* unary = this->unaryControls;
    connect(this->addButton, SIGNAL(pressed()), unary, SLOT(add()));
    connect(this->subtractButton, SIGNAL(pressed()), unary, SLOT(subtract()));
    connect(this->multiplyButton, SIGNAL(pressed()), unary, SLOT(multiply()));
    connect(this->divideButton, SIGNAL(pressed()), unary, SLOT(divide()));
    connect(this->equalsButton, SIGNAL(pressed()), unary, SLOT(equals()));
}

void MainWindow::setState(State state){
    this->state = &state;
}

/**
 * @brief Should be called only after the state has been set
 */
void MainWindow::initControls(){
    this->calculatorHandle = new Calculator();
    this->unaryControls = new UnaryControls(this->calculatorHandle, this->display, this->state);
    initEventListeners();

    /** Delegate all digit based buttons to the digit control class */
    QList<QPushButton *> allButtons = this->findChildren<QPushButton *>();
    Digit* digitControls = new Digit(allButtons, this->calculatorHandle, this->display, this->state);
    this->digitControls = digitControls;
}
