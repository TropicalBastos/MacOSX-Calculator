#ifndef CONTROL_INTERFACE
#define CONTROL_INTERFACE

class ControlInterface {
    public:
        ControlInterface(){}
        ~ControlInterface(){}
        virtual void performLeftOperation() = 0;
};

#endif // CONTROL_INTERFACE