//
// Created by Cezary on 24.11.2019.
//

#include "Calculator.h"
#include <string>

using namespace std;

string Calculator::substract(Number &n1, Number &n2) {
    string wynik;

    size_t n1_i = n1.size() - 1;
    size_t n2_i = n2.size() - 1;

    for (size_t i = 0; i < n1.size() + 1; n1_i--, n2_i--, i++) {
        unsigned pierwsza = n1.getDigitFromPosition(n1_i);
        unsigned druga = n2.getDigitFromPosition(n2_i);

        if (druga > pierwsza) {
            pierwsza += 10;

            unsigned long index = n1.size() - 1;
            while (n1.getDigitFromPosition(index) == 0) {
                n1.setNumberInPosition(index, '9');
                index--;
            }

            n1.setNumberInPosition(index, n1.getDigitFromPosition(index) - 1);
        }

        wynik.insert(0, to_string((char) (pierwsza - druga)));
    }

    return Calculator::removeTrailingZeros(wynik);
}

string Calculator::removeTrailingZeros(string str) {
    while (str[0] == '0')
        str.erase(0, 1);
    return str;
}

string Calculator::substract(string n1, string n2) {
    Number nn1(std::move(n1), false);
    Number nn2(std::move(n2), false);
    return this->substract(nn1, nn2);
}