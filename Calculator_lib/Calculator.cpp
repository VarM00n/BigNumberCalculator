#include "Calculator.h"
#include <string>
#include <utility>
#include <vector>

using namespace std;

Number Calculator::preAddition(Number &a, Number &b) {
    // a + (-b) = a - b
    if (a.isPositive() && b.isNegative()) {
        b.setSign(false);
        return preSubstract(a, b);
    }

    // (-a) + b = b - a
    if (a.isNegative() && b.isPositive()) {
        a.setSign(false);

        return preSubstract(b, a);
    }

    // (-a) + (-b) = -(a+b)
    if (a.isNegative() && b.isNegative()) {
        a.setSign(false);
        b.setSign(false);

        Number result = additionOperation(a, b);
        result.setSign(true);
        return result;
    }

    // a + b
    return additionOperation(a, b);
}

Number Calculator::preSubstract(Number &a, Number &b) {
    if(a == b)
        return Number("0");

    // a - (-b) = a + b
    if (a.isPositive() && b.isNegative()) {
        b.setSign(false);
        return preAddition(a, b);
    }

    // (-a) - b = -(a+b)
    if (a.isNegative() && b.isPositive()) {
        a.setSign(false);

        Number result = preAddition(a, b);
        result.setSign(true);
        return result;
    }

    // (-a) - (-b) = b - a
    if (a.isNegative() && b.isNegative()) {
        a.setSign(false);
        b.setSign(false);

        if(b > a)
            return substractOperation(b, a);
        else {
            Number result = substractOperation(a, b);
            result.setSign(true);
            return result;
        }
    }

    // a - b
    if(a > b)
        return substractOperation(a, b);
    else {
        Number result = substractOperation(b, a);
        result.setSign(true);
        return result;
    }
}

Number Calculator::preMultiplication(Number &a, Number &b) {
    // a * 0 = 0
    // 0 * b = 0
    if(a == Number("0") || b == Number("0"))
        return Number("0");

    // a * b = a * b
    // (-a) * (-b) = a*b
    if((a.isPositive() && b.isPositive()) || (a.isNegative() && b.isNegative())) {
        a.setSign(false);
        b.setSign(false);

        return multiplicationOperation(a, b);
    }

    // (-a) * b = -(a*b)
    // a * (-b) = -(a*b)
    if((a.isPositive() && b.isNegative()) || (a.isNegative() && b.isPositive()))
    {
        a.setSign(false);
        b.setSign(false);

        Number result = preMultiplication(a, b);
        result.setSign(true);
        return result;
    }

    return Number("0");
}


Number Calculator::preExponentiation(Number &a, Number &b) {
    // todo
    return exponentiationOperation(a, b);
}


Number Calculator::additionOperation(Number &n1, Number &n2) {
    unsigned long maks_rozmiar = n1.size();
    if (n2.size() > n1.size()) maks_rozmiar = n2.size();
    string result;
    unsigned carry = 0;
    long n1_i = (long) n1.size() - 1;
    long n2_i = (long) n2.size() - 1;
    for (size_t i = 0; i < maks_rozmiar + 1; n1_i--, n2_i--, i++) {
        unsigned n1_n = n1.getDigitFromPosition(n1_i);
        unsigned n2_n = n2.getDigitFromPosition(n2_i);

        result.insert(0, to_string(((n1_n + n2_n + carry) % 10)));
        carry = (n1_n + n2_n + carry) / 10;
    }
    return Number(result);
}

Number Calculator::substractOperation(Number &n1, Number &n2) {
    string result;
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

        result.insert(0, to_string((char) (n1_n - n2_n)));
    }

    return Number(result);
}

Number Calculator::multiplicationOperation(Number &n1, Number &n2) {
    if (n1.size() < n2.size()) swap(n1, n2);
    vector<string> tu_sum = {};

    for (long i = (long) n1.size() - 1; i >= 0; i--) { //for po mniejszej liczbie
        string tmp;
        unsigned carry = 0;
        for (long k = (long) (n1.size() - i - 1); k > 0; --k)
            tmp.insert(0, "0");
        for (long j = (long) n2.size() - 1; j >= 0; j--) { //for po większej liczbie
            unsigned n1_n = n1.getDigitFromPosition(i);
            unsigned n2_n = n2.getDigitFromPosition(j);
            unsigned mul = (n1_n * n2_n + carry);
            tmp.insert(0, to_string((mul % 10)));
            carry = mul / 10;
        }
        tmp.insert(0, to_string(carry));
        // todo może lepiej korzystać z number? w całym algorytmie
        tmp = Number(tmp).removeLeadingZeros()->toString();
        tu_sum.push_back(tmp);
    }

    string result;
    for (const auto &i : tu_sum) {
        result = addition(result, i);
    }
    return Number(result);
}

Number Calculator::exponentiationOperation(Number &a, Number &b) {
    Number c;
    // todo co to kurwa jest XD???!   Number(to_string(i)) < b
    for (int i = 0; Number(to_string(i)) < b; ++i) {
        // todo potęgowanie
    }

    if(b.isNegative())
    {
        // todo odwrócenie liczby
    }

    return Number();
}

Number Calculator::floatingMultiplicationOperation(Number &n1, Number &n2) {
    //setting place of comma in a result
    int place_of_comma_in_result = n2.getFloatingPos() + n1.getFloatingPos();
    //multiplication
    Number result(multiplication(n1, n2));
    result.setValue(result.add_coma(result.size() - place_of_comma_in_result));
    result.removeLeadingZeros();
    return result;
}

Number Calculator::floatingAdditionOperation(Number &n1, Number &n2){
    //setting place of comma in a result
    int place_of_comma_in_result =  n2.getFloatingPos(), temp = 0;
    if (place_of_comma_in_result < n1.getFloatingPos()){
        place_of_comma_in_result = n1.getFloatingPos();
        temp++;
    }
    if(temp == 0){
        //example first number x.xx, second number y.yyy  (x, y -> Natural number)
        for (int i = 0; i < n2.getFloatingPos() - n1.getFloatingPos(); i++)
            n1.setValue(n1.getValue() += "0");

    }
    else if(temp == 1){
        //example first number x.xxx, second number y.yy  (x, y -> Natural number)
        for(int i = 0 ; i < n1.getFloatingPos() - n2.getFloatingPos(); i++)
            n2.setValue(n2.getValue() += "0");

    }
    //addition
    Number result(addition(n1, n2));
    result.setValue(result.add_coma(result.size() - place_of_comma_in_result));
    result.removeLeadingZeros();
    return result;
}

Number Calculator::floatingSubstractOperation(Number &n1, Number &n2){
    //setting place of comma in a result
    int place_of_comma_in_result =  n2.getFloatingPos(), temp = 0;
    if (place_of_comma_in_result < n1.getFloatingPos()){
        place_of_comma_in_result = n1.getFloatingPos();
        temp++;
    }
    if(temp == 0){
        //example first number x.xx, second number y.yyy  (x, y -> Natural number)
        for (int i = 0; i < n2.getFloatingPos() - n1.getFloatingPos(); i++)
            for (int j = 0; j < n2.getFloatingPos() - n1.getFloatingPos(); j++)
            n1.setValue(n1.getValue() += "0");

    }
    else if(temp == 1){
        //example first number x.xxx, second number y.yy  (x, y -> Natural number)
        for(int i = 0 ; i < n1.getFloatingPos() - n2.getFloatingPos(); i++)
            n2.setValue(n2.getValue() += "0");
    //substract
    }
    Number result(substract(n1, n2));
    result.setValue(result.add_coma(result.size() - place_of_comma_in_result));
    result.removeLeadingZeros();
    return result;
}


// TODO liczy wrzysko dobrze tylko nie chce wyświetlać

Number Calculator::division(Number &n1, Number &n2, int apr) {
    Number rest("0");
    Number result("0");
    Number zero("0");
    Number one("1");
    Number two("2");
    if(n2.getValue() == "0"){
        __builtin_trap();
    }
    while(substract(n1, n2) > zero){
        n1.setValue(substract(n1, n2).getValue());
        result.setValue(addition(result, one).getValue());
    }
    if(multiplication(n1, two) > n2){
        result.setValue(addition(result, one).getValue());
    }
    return result;
}
