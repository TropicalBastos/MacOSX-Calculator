#include "../MainWindow/mainwindow.h"
#include "unary_controls.h"

UnaryControls::UnaryControls(Calculator* calculatorHandle, QLabel* parentDisplay){
    this->calculatorHandle = calculatorHandle;
    this->parentDisplay = parentDisplay;
}

UnaryControls::~UnaryControls(){}

void UnaryControls::add(){
    qDebug("ADDING");
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::ADD);
}

void UnaryControls::subtract(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::SUBTRACT);
}

void UnaryControls::multiply(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::MULTIPLY);
}

void UnaryControls::divide(){
    this->calculatorHandle->setLeftOperand(this->getDisplayNumber());
    this->calculatorHandle->setMode(CalculatorMode::DIVIDE);
}

void UnaryControls::equals(){
    this->calculatorHandle->setRightOperand(this->getDisplayNumber());
    double result = this->calculatorHandle->processArithmetic();
    this->parentDisplay->setText(QString::number(result));
}

double UnaryControls::getDisplayNumber(){
    QString text = this->parentDisplay->text();
    return text.toDouble();
}
