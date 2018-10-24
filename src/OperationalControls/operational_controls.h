#ifndef OPERATIONAL_CONTROLS
#define OPERATIONAL_CONTROLS

#include <QString>
#include <QLabel>
#include <QRegExp>
#include "../DisplayInterface/display_interface.h"
#include "../Calculator/calculator.h"
#include "../ControlInterface/control_interface.h"
#include "../State/state.h"

class OperationalControls : public QObject, public DisplayInterface, public ControlInterface {
    Q_OBJECT

    public:
        OperationalControls(Calculator* calculatorHandle, QLabel* label, State* state = NULL);
        ~OperationalControls(){}
        double getDisplayNumber();
        void performLeftOperation();

    public slots:
        void cancel();
        void toggleSign();
        void modulo();

    private:
        Calculator* calculatorHandle;
        QLabel* parentDisplay;
        State* state;
};

#endif // OPERATIONAL_CONTROLS
