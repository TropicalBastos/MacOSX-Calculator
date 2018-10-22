#ifndef UNARYCONTROLS 
#define UNARYCONTROLS

#include <QObject>
#include <QLabel>
#include "../Calculator/calculator.h"
#include "../DisplayInterface/display_interface.h"

class UnaryControls : public QObject, public DisplayInterface {
    Q_OBJECT

    public:
        UnaryControls(Calculator* calc, QLabel* parentDisplay);
        ~UnaryControls();
        double getDisplayNumber();

    private:
        QLabel* parentDisplay;
        Calculator* calculatorHandle;

    public slots:
        void add();
        void subtract();
        void multiply();
        void divide();
        void equals();
};

#endif // UNARYCONTROLS
