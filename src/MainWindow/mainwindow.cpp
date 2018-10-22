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
    this->calculatorHandle = new Calculator();
    this->unaryControls = new UnaryControls(this->calculatorHandle, this->display);
    this->initEventListeners();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initEventListeners(){
    UnaryControls* unary = this->unaryControls;
    connect(this->addButton, SIGNAL(pressed()), unary, SLOT(add()));
    connect(this->subtractButton, SIGNAL(pressed()), unary, SLOT(subtract()));
    connect(this->multiplyButton, SIGNAL(pressed()), unary, SLOT(multiply()));
    connect(this->divideButton, SIGNAL(pressed()), unary, SLOT(divide()));
}
