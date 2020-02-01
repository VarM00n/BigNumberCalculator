#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <string>

class Number {
private:
    std::string value;
    bool sign = false; // false - positive, true - negative
public:
    Number(std::string value, bool sign);

    Number(std::string value);

    void setNumberInPosition(long position, char digit);

    void setNumberInPosition(long position, unsigned digit);

    unsigned getDigitFromPosition(long position);

    unsigned size();

    bool getSign();

    std::string getValue();

    bool checkingForASign(std::string number);
};


#endif //CALCULATOR_NUMBER_H
