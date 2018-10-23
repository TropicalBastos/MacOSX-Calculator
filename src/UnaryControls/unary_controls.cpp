#include "../MainWindow/mainwindow.h"
#include "unary_controls.h"

UnaryControls::UnaryControls(Calculator* calculatorHandle, QLabel* parentDisplay, State* state){
    this->calculatorHandle = calculatorHandle;
    this->parentDisplay = parentDisplay;
    this->state = state;
}

void UnaryControls::performLeftOperation(){
    calculatorHandle->setLeftOperand(getDisplayNumber());
    state->operationPerformed = true;
}

void UnaryControls::add(){
    performLeftOperation();
    calculatorHandle->setMode(CalculatorMode::ADD);
}

void UnaryControls::subtract(){
    performLeftOperation();
    calculatorHandle->setMode(CalculatorMode::SUBTRACT);
}

void UnaryControls::multiply(){
    performLeftOperation();
    calculatorHandle->setMode(CalculatorMode::MULTIPLY);
}

void UnaryControls::divide(){
    performLeftOperation();
    calculatorHandle->setMode(CalculatorMode::DIVIDE);
}

void UnaryControls::equals(){
    calculatorHandle->setRightOperand(getDisplayNumber());
    double result = calculatorHandle->processArithmetic();
    parentDisplay->setText(QString::number(result));
}

double UnaryControls::getDisplayNumber(){
    QString text = parentDisplay->text();
    return text.toDouble();
}
