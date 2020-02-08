#ifndef CALCULATOR_INTERPRETER_H
#define CALCULATOR_INTERPRETER_H

#include <stack>
#include <vector>
#include <sstream>
#include <iterator>
#include <string>
#include "Number.h"

using namespace std;

class Interpreter {
    string infixExpression;
    vector<string> RPN;

    /**
     * Returns 0 if character is not operator or priority otherwise
     * order start from 1 and thats highest priority
     * @param character
     * @return
     */
    static int isOperand(char character);
    void infixToRPN();

public:
    string infixToRPN(const string& expression);


    Number evaluateExpression(const string& expression);
};


#endif //CALCULATOR_INTERPRETER_H
