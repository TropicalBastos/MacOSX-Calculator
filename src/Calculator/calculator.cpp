#include "calculator.h"

void Calculator::setMode(int m){
    this->mode = m;
}

double Calculator::processArithmetic(){
    double result = 0;
    double a = this->getLeftOperand();
    double b = this->getRightOperand();
    this->clearOperands();
    switch(this->mode){
        case CalculatorMode::ADD:
            result = this->add(a, b);
        case CalculatorMode::SUBTRACT:
            result = this->subtract(a, b);
        case CalculatorMode::MULTIPLY:
            result = this->multiply(a, b);
        case CalculatorMode::DIVIDE:
            result = this->divide(a, b);
        case CalculatorMode::MODULO:
            result = this->modulo(a, b);
    }
    this->setLeftOperand(result);
    return result;
}

void Calculator::setLeftOperand(double num){
    this->leftOperand = num;
}

void Calculator::setRightOperand(double num){
    this->rightOperand = num;
}

double Calculator::getLeftOperand(){
    return this->leftOperand;
}

double Calculator::getRightOperand(){
    return this->rightOperand;
}

void Calculator::clearOperands(){
    this->leftOperand = 0;
    this->rightOperand = 0;
}

double Calculator::add(double a, double b){
    return a + b;
}

double Calculator::subtract(double a, double b){
    return a - b;
}

double Calculator::multiply(double a, double b){
    return a * b;
}

double Calculator::divide(double a, double b){
    return a / b;
}

double Calculator::modulo(int a, int b){
    return a % b;
}