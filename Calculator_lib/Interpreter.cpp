#include "Interpreter.h"


int Interpreter::isOperand(char character) {
    switch (character) {
        case '^':
            return 1;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 3;
        default:
            return 0;
    }

//
//    for (int i = 0; i < sizeof(this->operands); ++i)
//        if (character == this->operands[i])
//            return i + 1;
//
//    return 0;
}

//
//void Interpreter::expressionToRpn(const string &expression) {
//    for (int i = 0; i < expression.size(); ++i)
//        if (isOperand(expression[i]))
//            return;
//}
void Interpreter::infixToPostfix() {
    stack<char> s;
    vector<string> r;

    string tmp; // for building whole numbers from digit

    for (char c : infixExpression) {
        if (c == ' ')
            continue;

        if (isdigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            tmp += c;
            continue;
        } else if (!tmp.empty()) {
            r.push_back(tmp);
            tmp = "";
        }

        if (c == ')') {
            while (s.top() != '(') {
                r.emplace_back(1, s.top());
                s.pop();
            }
            s.pop();
        } else if (c == '(') {
            s.push(c);
        }
        else if(int priority = isOperand(c))
        {
            if(!s.empty() && isOperand(s.top()) && priority >= isOperand(s.top()))
            {
                r.emplace_back(1, s.top());
                s.pop();
            }

            s.push(c);
        }

    }

    // writing all that remains
    if (!tmp.empty()) {
        r.push_back(tmp);
        tmp = "";
    }

    // writing remaining operator in proper order
    while (!s.empty()) {
        r.emplace_back(1, s.top());
        s.pop();
    }

    RPN = r;
}

string Interpreter::infixToPostfix(const string &expression) {
    infixExpression = expression;
    infixToPostfix();

    ostringstream imploded;
    copy(RPN.begin(), RPN.end() - 1,
         ostream_iterator<std::string>(imploded, " "));

    return imploded.str() + RPN.back();
}

