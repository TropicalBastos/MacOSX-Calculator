#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->addButton = ui->add;
    this->subtractButton = ui->subtract;
    this->multiplyButton = ui->multiply;
    this->divideButton = ui->divide;
    this->display = ui->display;
    this->initEventListeners();
    this->calculatorHandle = new Calculator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initEventListeners(){
    connect(this->addButton, SIGNAL(pressed()), this, SLOT(add()));
    connect(this->subtractButton, SIGNAL(pressed()), this, SLOT(subtract()));
    connect(this->multiplyButton, SIGNAL(pressed()), this, SLOT(multiply()));
    connect(this->divideButton, SIGNAL(pressed()), this, SLOT(divide()));
}

void MainWindow::add(){
    qDebug("ADDING");
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::ADD);
}

void MainWindow::subtract(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::SUBTRACT);
}

void MainWindow::multiply(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::MULTIPLY);
}

void MainWindow::divide(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::DIVIDE);
}

double MainWindow::getDisplayNumber(){
    QString text = this->display->text();
    return text.toDouble();
}
