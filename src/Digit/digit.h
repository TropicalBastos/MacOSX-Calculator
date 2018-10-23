#ifndef DIGIT 
#define DIGIT

#include <QObject>
#include <QLabel>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QMutableListIterator>
#include <QRegExp>
#include <QDebug>
#include "../Calculator/calculator.h"
#include "../State/state.h"

class Digit: public QObject {
    Q_OBJECT

    public:
        Digit(QList<QPushButton *> buttons, Calculator*, QLabel* parentDisplay, State* state);
        ~Digit(){};
        void filterDigitButtons(QList<QPushButton*>& buttons);

    public slots:
        void appendDigit();

    private:
        QLabel* parentDisplay;
        Calculator* calculatorHandle;
        State* state;

};

#endif // DIGIT
