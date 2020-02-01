#include "Calculator.h"
#include <string>
#include <vector>

using namespace std;


/**
 * SUB
 */

string Calculator::substract(Number &n1, Number &n2) {
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
    result = Calculator::removeTrailingZeros(result);
    return result;
}

string Calculator::substract(string n1, string n2) {
    Number nn1(move(n1));
    Number nn2(move(n2));
    return this->substract(nn1, nn2);
}

string Calculator::interpreterForSubstract(string n1, string n2){
    if(n1[0] != '-'){
        if(n2[0] != '-'){
            if(checkIfBigger(n1, n2)){
                if(!checkIfEqual(n1, n2)){
                    return substract(n1, n2);
                }
                return "0";
            }
            else{
                if(!checkIfEqual(n1, n2)){
                    swap(n1, n2);
                    return '-' + substract(n1, n2);
                }
                return "0";
            }
        }
        else{
            if(checkIfBigger(n1, n2)){
                return addition(n1, n2);
            }
            else{
                return addition(n1, n2);
            }
        }
    }
    else{
        if(n2[0] != '-'){
                return '-' + addition(n1, n2);
        }
        else{
            if(!checkIfEqual(n1, n2)) {
                if (checkIfBigger(n1, n2)) {
                    return '-' + substract(n1, n2);
                } else {
                    swap(n1, n2);
                    return substract(n1, n2);
                }
            }
            return "0";
        }
    }
} // używać jako odejmowania

/**
 * ADD
 */

std::string Calculator::addition(Number &n1, Number &n2) {

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
    return result = Calculator::removeTrailingZeros(result);
}

string Calculator::addition(string n1, string n2) {
    Number nn1(move(n1));
    Number nn2(move(n2));
    return this->addition(nn1, nn2);
}

string Calculator::interpreterForAddition(string n1, string n2){
    if(n1[0] != '-'){
        if(n2[0] != '-'){
            return addition(n1, n2);
        }
        else{
            if(!checkIfEqual(n1, n2)) {
                if (checkIfBigger(n1, n2)) {
                    return substract(n1, n2);
                } else {
                    swap(n1, n2);
                    return '-' + substract(n1, n2);
                }
            }
            return "0";
        }
    }
    else{
        if(n2[0] != '-'){
            if(!checkIfEqual(n1, n2)) {
                swap(n1, n2);
                if (checkIfBigger(n1, n2)) {
                    return substract(n1, n2);
                } else {
                    swap(n1, n2);
                    return '-' + substract(n1, n2);
                }
            }
            return "0";
        }
        else{
            return '-' + addition(n1, n2);
        }
    }
} // używać jako dodawania

/**
 * MUL
 */

string Calculator::multiplication(Number &n1, Number &n2) {
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
        tmp = Calculator::removeTrailingZeros(tmp);
        tu_sum.push_back(tmp);
    }

    string result;
    for (const auto &i : tu_sum) {
        result = this->addition(result, i);
    }
    return result;
}

string Calculator::multiplication(string n1, string n2) {
    Number nn1(move(n1));
    Number nn2(move(n2));
    return this->multiplication(nn1, nn2);
}

string Calculator::interpreterForMultiplication(string n1, string n2){
    if(n1[0] != '-'){
        if(n2[0] != '-'){
            return multiplication(n1, n2);
        }
        else{
            return '-' + multiplication(n1, n2);
        }
    }
    else{
        if(n2[0] != '-'){
            return '-' + multiplication(n1, n2);
        }
        else{
            return multiplication(n1, n2);
        }
    }
}

/**
 * HELP
 */

string Calculator::removeTrailingZeros(string str) {
    while (str[0] == '0')
        str.erase(0, 1);
    return str;
}

bool Calculator::checkIfBigger (Number &n1, Number &n2){ // sprawdzamy czy n1 > n2
    if(n1.size() > n2.size()){
        return true;
    }
    else if(n1.size() < n2.size()){
        return false;
    }
    else{
        for(int i = 0 ; i < n1.size(); i++){
            if(n1.getValue()[i] > n2.getValue()[i]){
                return true;
            }
            else if(n1.getValue()[i] < n2.getValue()[i]){
                return false;
            }
        }
    }
}

bool Calculator::checkIfBigger (string n1, string n2){ // sprawdzamy czy n1 > n2
    Number nn1(move(n1));
    Number nn2(move(n2));
    return this->checkIfBigger(nn1, nn2);
}

bool Calculator::checkIfEqual (Number &n1, Number &n2){
    for(int i = 0; i < n1.getValue().size(); i++){
        if(n1.getValue()[i] != n2.getValue()[i]) {
            return false;
        }
    }
    return true;
}

bool Calculator::checkIfEqual (string n1, string n2){
    Number nn1(move(n1));
    Number nn2(move(n2));
    return this->checkIfEqual(nn1, nn2);
}