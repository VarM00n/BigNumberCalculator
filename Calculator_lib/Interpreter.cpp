#include "Interpreter.h"
#include "Calculator.h"

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
}

void Interpreter::infixToRPN() {
    stack<char> s;
    vector<string> r;

    string tmp; // for building whole numbers from digit
    bool lastOp = false;

    for (char c : infixExpression) {
        if (c == ' ')
            continue;

        if (isdigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || (c == '-' && lastOp)) {
            tmp += c;
            lastOp = false;
            continue;
        } else if (!tmp.empty()) {
            r.push_back(tmp);
            tmp = "";
        }

        lastOp = true;

        if (c == ')') {
            while (s.top() != '(') {
                r.emplace_back(1, s.top());
                s.pop();
            }
            s.pop();
        } else if (c == '(') {
            s.push(c);
        } else if (int priority = isOperand(c)) {
            if (!s.empty() && isOperand(s.top()) && priority >= isOperand(s.top())) {
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

string Interpreter::infixToRPN(const string &expression) {
    infixExpression = expression;
    infixToRPN();

    ostringstream imploded;
    copy(RPN.begin(), RPN.end() - 1,
         ostream_iterator<std::string>(imploded, " "));

    return imploded.str() + RPN.back();
}

Number Interpreter::evaluateExpression(const string &expression) {
    infixExpression = expression;
    infixToRPN();

    stack<string> numbers;
    for(string e : RPN)
    {
        if(e.size() != 1 || !isOperand(e[0]))
            numbers.push(e);
        else
        {
            Number a(numbers.top());
            numbers.pop();
            Number b(numbers.top());
            numbers.pop();

            switch (e[0])
            {
                case '+':
                    numbers.push(Calculator::addition(a, b).toString());
                    break;
                case '-':
                    numbers.push(Calculator::substract(a, b).toString());
                    break;
                case '*':
                    numbers.push(Calculator::multiplication(a, b).toString());
                    break;
                case '/':
                    // todo
//                    numbers.push(Calculator::division(a, b).toString());
                    break;
                case '^':
                    // todo
                    break;
                default:
                    break;
            }

        }
    }

    return Number(numbers.top());
}

