#ifndef CALCULATOR_INTERPRETER_H
#define CALCULATOR_INTERPRETER_H

#include <stack>
#include <string>

using namespace std;

class Interpreter {
    string postfixExpression;
    stack<string> rpn; // reversed polish notation

    char operands[5] = {'+', '-', '*', '/', '^'};

    int isOperand(char character);

    void expressionToRpn(const string& expression);

public:
    string infixToPostfix(const string& expression);


//    void evaluateExpression
};


#endif //CALCULATOR_INTERPRETER_H
