#ifndef OPERATIONAL_CONTROLS
#define OPERATIONAL_CONTROLS

#include "../DisplayInterface/display_interface.h"

class OperationalControls : public QObject, public DisplayInterface {
    Q_OBJECT

    public:
        OperationalControls();
        ~OperationalControls(){}

    public slots:
        void cancel();
};

#endif // OPERATIONAL_CONTROLS