#ifndef UNARYCONTROLS 
#define UNARYCONTROLS

#include <QObject>
#include <QLabel>
#include "../Calculator/calculator.h"
#include "../DisplayInterface/display_interface.h"
#include "../State/state.h"
#include "../ControlInterface/control_interface.h"

class UnaryControls : public QObject, public DisplayInterface, public ControlInterface {
    Q_OBJECT

    public:
        UnaryControls(Calculator* calc, QLabel* parentDisplay, State* state = NULL);
        ~UnaryControls(){}
        double getDisplayNumber();

    private:
        QLabel* parentDisplay;
        Calculator* calculatorHandle;
        State* state;
        void performLeftOperation();

    public slots:
        void add();
        void subtract();
        void multiply();
        void divide();
        void equals();
};

#endif // UNARYCONTROLS
