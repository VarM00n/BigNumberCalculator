#include "Calculator.h"

using namespace std;

string Calculator::addition(const string& val1, const string& val2) {
    Number n1(val1);
    Number n2(val2);
    return preAddition(n1, n2).toString();
}

string Calculator::substract(const string& val1, const string& val2) {
    Number n1(val1);
    Number n2(val2);
    return preSubstract(n1, n2).toString();
}

string Calculator::multiplication(const string& val1, const string& val2) {
    Number n1(val1);
    Number n2(val2);
    return preMultiplication(n1, n2).toString();
}


Number Calculator::addition(Number &a, Number &b) {
    return preAddition(a, b);
}

Number Calculator::substract(Number &a, Number &b) {
    return preSubstract(a, b);
}

Number Calculator::multiplication(Number &a, Number &b) {
    return preMultiplication(a, b);
}

Number Calculator::exponentiation(Number &a, Number &b) {
    return preExponentiation(a, b);
}
