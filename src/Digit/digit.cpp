#include "digit.h"

Digit::Digit(QList<QPushButton *> buttons, Calculator* calc, QLabel* parentDisplay){
    this->calculatorHandle = calc;
    this->parentDisplay = parentDisplay;
    filterDigitButtons(buttons);
    for(int i = 0; i < buttons.length(); i++){
        QPushButton* digit = buttons.at(i);
        connect(digit, SIGNAL(pressed()), this, SLOT(appendDigit()));
    }
}

void Digit::appendDigit(){
    QPushButton* pb = (QPushButton*) QObject::sender();
    QString digit = pb->text();
    QString displayText = this->parentDisplay->text();
    if(displayText == "0" || State.operationPerformed){
        displayText = "";
    }
    QString result = displayText + digit;
    this->parentDisplay->setText(result);
    State.operationPerformed = false;
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
        QRegExp re("[0-9]*");
        if(!re.exactMatch(buttonText)){
            iter.remove();
        }
    }
}