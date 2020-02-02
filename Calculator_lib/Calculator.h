#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include "Number.h"

class Calculator {
public:
    static std::string removeTrailingZeros(std::string str);

    // #TODO zmienić nazewnictwo
    std::string addition(Number &n1, Number &n2);
    std::string addition(std::string n1, std::string n2);
    std::string interpreterForAddition(std::string n1, std::string n2);

    std::string substract(Number &n1, Number &n2);
    std::string substract(std::string n1, std::string n2);
    std::string interpreterForSubstract(std::string n1, std::string n2);

    std::string multiplication(Number &n1, Number &n2);
    std::string multiplication(std::string n1, std::string n2);
    std::string interpreterForMultiplication(std::string n1, std::string n2);

    bool checkIfBigger (Number &n1, Number &n2);

    bool checkIfBigger (std::string n1, std::string n2);

    bool checkIfEqual (Number &n1, Number &n2);

    bool checkIfEqual (std::string n1, std::string n2);
};


#endif //CALCULATOR_CALCULATOR_H
