#include "calculator.h"

void Calculator::setMode(int m){
    this->mode = m;
}

double Calculator::processArithmetic(){
    double result = 0;
    double a = getLeftOperand();
    double b = getRightOperand();
    clearOperands();
    switch(this->mode){
        case CalculatorMode::ADD:
            result = add(a, b);
            break;
        case CalculatorMode::SUBTRACT:
            result = subtract(a, b);
            break;
        case CalculatorMode::MULTIPLY:
            result = multiply(a, b);
            break;
        case CalculatorMode::DIVIDE:
            result = divide(a, b);
            break;
        case CalculatorMode::MODULO:
            result = modulo(a, b);
            break;
        default:
            result = add(a, 0);
            break;
    }
    setMode(CalculatorMode::NONE);
    setLeftOperand(result);
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
