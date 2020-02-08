#ifndef CALCULATOR_INTERPRETER_H
#define CALCULATOR_INTERPRETER_H

#include <stack>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

class Interpreter {
    string infixExpression;
    vector<string> RPN;
    stack<string> rpn; // reversed polish notation

    // todo wywalić
    // the operations order is from 0
    // most importand operations has lower index in this array
//    char operands[5] = {'^', '*', '/', '+', '-'};

    static int isOperand(char character);

public:
    string infixToPostfix(const string& expression);
    void infixToPostfix();

//    void evaluateExpression
};


#endif //CALCULATOR_INTERPRETER_H
