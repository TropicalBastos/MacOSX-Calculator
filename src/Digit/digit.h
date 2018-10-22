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

class Digit: public QObject {
    Q_OBJECT

    public:
        Digit(QList<QPushButton *> buttons, Calculator*, QLabel* parentDisplay);
        ~Digit(){};
        void filterDigitButtons(QList<QPushButton*>& buttons);

    public slots:
        void appendDigit();

    private:
        QLabel* parentDisplay;
        Calculator* calculatorHandle;

};

#endif // DIGIT
