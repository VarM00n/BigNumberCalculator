//
// Created by Cezary on 24.11.2019.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include "Number.h"

class Calculator {
public:
    static std::string removeTrailingZeros(std::string str);

    std::string substract(Number &n1, Number &n2);

    std::string substract(std::string n1, std::string n2);
};


#endif //CALCULATOR_CALCULATOR_H
