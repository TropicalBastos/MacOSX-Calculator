#ifndef DISPLAY_INTERFACE
#define DISPLAY_INTERFACE

class DisplayInterface
{
public:
    DisplayInterface(){}
    virtual ~DisplayInterface(){}
    virtual double getDisplayNumber() = 0;
};

#endif // DISPLAY_INTERFACE
