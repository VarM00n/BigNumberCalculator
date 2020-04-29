#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include "Number.h"

using namespace std;

class Calculator {
private:
    /**
     * Validation and standarization of output string
     *
     * @param output String to validate
     * @return String with valid value
     */
    static string prepareOutputDataString(string output);
    /**
     * Validation and standarization of output number
     *
     * @param output String to validate
     * @return Number object with valid attributes
     */
    static Number prepareOutputDataNumber(string output);

    // Core calculation functions
    static Number additionOperation(Number &n1, Number &n2);
    static Number preAddition(Number &a, Number &b);

    static Number substractOperation(Number &n1, Number &n2);
    static Number preSubstract(Number &a, Number &b);

    static Number multiplicationOperation(Number &n1, Number &n2);
    static Number preMultiplication(Number &a, Number &b);

    static Number divisionOperation(Number &n1, Number &n2);
    static Number preDivision(Number &a, Number &b);
    static Number div(Number &a, Number &b);

public:


    static string addition(const string &val1, const string &val2);
    static Number addition(Number &a, Number &b);
    static Number floatingAdditionOperation(Number &a, Number &b);
    static string division(const string& val1, const string& val2);

    static string substract(const string &n1, const string &n2);
    static string multiplication(const string &n1, const string &n2);

    static string removeTrailingZeros(string str);
    static string removeOneZero(string str);


    static Number substract(Number &a, Number &b);
    static Number multiplication(Number &a, Number &b);

    static string removeTrailingZeros(Number &str);
    static string removeOneZero(Number &str);
    static string changeToFloat(Number &str);

    static Number floatingSubstractOperation(Number &a, Number &b);
    static Number floatingMultiplicationOperation(Number &a, Number &b);
    static Number floatingDivisionOperation(Number &n1, Number &n2, int app);


};


#endif //CALCULATOR_CALCULATOR_H
