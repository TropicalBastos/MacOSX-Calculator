#include "operational_controls.h"

OperationalControls::OperationalControls(Calculator* calculatorHandle, QLabel* parentDisplay, State* state){
    this->calculatorHandle = calculatorHandle;
    this->parentDisplay = parentDisplay;
    this->state = state;
}

double OperationalControls::getDisplayNumber(){
    QString text = parentDisplay->text();
    return text.toDouble();
}

void OperationalControls::performLeftOperation(){
    calculatorHandle->setLeftOperand(getDisplayNumber());
    state->operationPerformed = true;
}

void OperationalControls::cancel(){
    parentDisplay->setText("0");
    calculatorHandle->clearOperands();
}

void OperationalControls::modulo(){
    performLeftOperation();
    calculatorHandle->setMode(CalculatorMode::MODULO);
}

void OperationalControls::toggleSign(){
    QRegExp re("^-.+");
    QString displayText = parentDisplay->text();
    if(!re.exactMatch(displayText)){
        displayText = "-" + displayText;
    } else {
        displayText.remove('-');
    }
    parentDisplay->setText(displayText);
}
