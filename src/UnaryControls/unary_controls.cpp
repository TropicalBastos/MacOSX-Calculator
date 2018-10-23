#include "../MainWindow/mainwindow.h"
#include "unary_controls.h"

UnaryControls::UnaryControls(Calculator* calculatorHandle, QLabel* parentDisplay){
    this->calculatorHandle = calculatorHandle;
    this->parentDisplay = parentDisplay;
}

void UnaryControls::performLeftOperation(){
    this->calculatorHandle->setLeftOperand(getDisplayNumber());
    State.operationPerformed = true;
}

void UnaryControls::add(){
    performLeftOperation();
    this->calculatorHandle->setMode(CalculatorMode::ADD);
}

void UnaryControls::subtract(){
    performLeftOperation();
    this->calculatorHandle->setMode(CalculatorMode::SUBTRACT);
}

void UnaryControls::multiply(){
    performLeftOperation();
    this->calculatorHandle->setMode(CalculatorMode::MULTIPLY);
}

void UnaryControls::divide(){
    performLeftOperation();
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
