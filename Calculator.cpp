//
// Created by Cezary on 24.11.2019.
//

#include "Calculator.h"
#include <string>

using namespace std;

string Calculator::substract(Number &n1, Number &n2) {
    string wynik;

    long n1_i = (long) n1.size() - 1;
    long n2_i = (long) n2.size() - 1;

    for (size_t i = 0; i < n1.size() + 1; n1_i--, n2_i--, i++) {
        unsigned n1_n = n1.getDigitFromPosition(n1_i);
        unsigned n2_n = n2.getDigitFromPosition(n2_i);

        if (n1_n < n2_n) {
            n1_n += 10;

            long index = (long) (n1.size() - i - 2);
            while (n1.getDigitFromPosition(index) == 0) {
                n1.setNumberInPosition(index, '9');
                index--;
            }

            n1.setNumberInPosition(index, n1.getDigitFromPosition(index) - 1);
        }

        wynik.insert(0, to_string((char) (n1_n - n2_n)));
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