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
    static Number substractOperation(Number &n1, Number &n2);
    static Number multiplicationOperation(Number &n1, Number &n2);
    static Number exponentiationOperation(Number &a, Number &b);

    /**
     * Prepares provided data to quick calculation
     * @param a
     * @param b
     * @return
     */
    static Number preAddition(Number &a, Number &b);
    /**
     * Prepares provided data to quick calculation
     * @param a
     * @param b
     * @return
     */


    /**
     *
     * @param a
     * @param b
     * @return
     */

    static Number preSubstract(Number &a, Number &b);
    /**
     * Prepares provided data to quick calculation
     * @param a
     * @param b
     * @return
     */
    static Number preMultiplication(Number &a, Number &b);

    static Number preExponentiation(Number &a, Number &b);
public:

    // Overloads
    static string addition(const string &val1, const string &val2);
    static string substract(const string &n1, const string &n2);
    static string multiplication(const string &n1, const string &n2);
    static string exponentiation(const string &a, const string &b);

    static string removeTrailingZeros(string str);

    static Number addition(Number &a, Number &b);
    static Number substract(Number &a, Number &b);
    static Number multiplication(Number &a, Number &b);
    static Number division(Number &n1, Number &n2, int apr);
    static Number exponentiation(Number &a, Number &b);

    static string removeTrailingZeros(Number &str);

    static Number floatingAdditionOperation(Number &a, Number &b);

    static Number floatingSubstractOperation(Number &a, Number &b);

    static Number floatingMultiplicationOperation(Number &a, Number &b);


};


#endif //CALCULATOR_CALCULATOR_H
