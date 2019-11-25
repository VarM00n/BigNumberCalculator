//
// Created by Cezary on 24.11.2019.
//

#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <string>

class Number {
private:
    std::string value;
    bool sign = false; // false - positive, true - negative
public:
    Number(std::string value, bool sign);

    void setNumberInPosition(long position, char digit);

    void setNumberInPosition(long position, unsigned digit);

    unsigned getDigitFromPosition(long position);

    unsigned size();
};


#endif //CALCULATOR_NUMBER_H
