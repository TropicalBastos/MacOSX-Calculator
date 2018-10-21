#ifndef CALCULATOR
#define CALCULATOR

enum CalculatorMode {
    ADD,
    SUBTRACT,
    MULTIPLY,
    MODULO,
    DIVIDE
};

class Calculator {
    public:
        Calculator();
        ~Calculator();
        void setMode(int mode);
        double processArithmetic();
        void setLeftOperand(double num);
        void setRightOperand(double num);
        void clearOperands();
        double getLeftOperand();
        double getRightOperand();

    private:
        double add(double a, double b);
        double subtract(double a, double b);
        double multiply(double a, double b);
        double modulo(int a, int b);
        double divide(double a, double b);
        double leftOperand;
        double rightOperand;
        int mode;
};

#endif // CALCULATOR