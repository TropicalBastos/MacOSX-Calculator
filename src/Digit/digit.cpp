#include "digit.h"

Digit::Digit(QList<QPushButton *> buttons, Calculator* calc, QLabel* parentDisplay, State* state = NULL){
    this->calculatorHandle = calc;
    this->parentDisplay = parentDisplay;
    this->state = state;
    filterDigitButtons(buttons);
    for(int i = 0; i < buttons.length(); i++){
        QPushButton* digit = buttons.at(i);
        connect(digit, SIGNAL(pressed()), this, SLOT(appendDigit()));
    }
}

bool Digit::displayHasPeriod(){
    QRegExp re("[.]+");
    if(re.indexIn(parentDisplay->text(), 0) != -1){
        return true;
    }
    return false;
}

void Digit::appendDigit(){
    QPushButton* pb = (QPushButton*) QObject::sender();
    QString digit = pb->text();
    QString displayText = parentDisplay->text();
    if(displayText == "0" || state->operationPerformed){
        displayText = "";
    }
    if(displayText == "" && digit == "."){
        displayText = parentDisplay->text();
    }
    if(displayHasPeriod() && digit == "."){
        state->operationPerformed = false;
        return;
    }
    QString result = displayText + digit;
    parentDisplay->setText(result);
    state->operationPerformed = false;
}

/**
 * @brief Filters a list of buttons in place
 *  by digit-based buttons i.e buttons that have a number text
 * @param buttons
 * @return
 */
void Digit::filterDigitButtons(QList<QPushButton*>& buttons){
    QMutableListIterator<QPushButton*> iter(buttons);
    while(iter.hasNext()){
        QString buttonText = iter.next()->text();
        QRegExp re("[0-9.]*");
        if(!re.exactMatch(buttonText)){
            iter.remove();
        }
    }
}
