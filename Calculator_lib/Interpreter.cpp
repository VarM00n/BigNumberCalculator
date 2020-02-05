#include "Interpreter.h"


int Interpreter::isOperand(char character) {
    for (int i = 0; i < sizeof(this->operands); ++i)
        if (character == this->operands[i])
            return i;

    return -1;
}

void Interpreter::expressionToRpn(const string &expression) {
    for (int i = 0; i < expression.size(); ++i)
        if (isOperand(expression[i]))
            return;
}
string Interpreter::infixToPostfix(const string &expression) {
    stack<char> s;
    s.push('X'); // end of stack marker
    string result;

    for (char c : expression) {
        if (c < 48 || c > 57)
            result += c;
        else if(c == '(')
            s.push(c);
        else if(c == ')')
        {
            while(s.top() != 'X' && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            if(s.top() == '(')
                s.pop();
        } else {
            // operator
            while (isOperand(c) <= isOperand(s.top()) && s.top() != 'X')
            {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(s.top() != 'X')
    {
        result+=s.top();
        s.pop();
    }
//
//    for (int i = 0; i < expression.size(); ++i) {
//        if(s[i])
//    }
    return this->postfixExpression = result;
}

