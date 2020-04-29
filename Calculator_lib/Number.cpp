#include "Number.h"

using namespace std;

Number::Number() {
    this->setSign(false);
    setValue("0");
}

Number::Number(const string &val, bool sign) {
    this->sign = sign;
    setValue(val);
}

Number::Number(const string &val) {
    if (val[0] == '-')
        sign = true;
    setValue(val);
    sanitizeValue();
}

bool Number::isNegative() const {
    return sign;
}

bool Number::isPositive() const {
    return !sign;
}

void Number::setSign(bool sign) {
    Number::sign = sign;
}

string Number::toString() const {
    if (sign)
        return "-" + value;
    return value;
}

void Number::sanitizeValue() {
    string output;
    output.reserve(value.size()); // prevent string realloc in loop

    // zero cannot be negative
    if (value == "-0") {
        sign = false;
        value = "0";
        return;
    }

    // TODO spróbować zrobić to z mniejszą złożonością
    int valueSize = (int)size();
    for(int i = valueSize - 1; i > 0; i--){
        if(getValue()[i] == '.'){
            setFloatingPos(valueSize - i -1);
            break;
        }
    }

    // get rid of all chars expect digits
    for (char i : value) {
        if (i >= 48 && i <= 57 )
            output += i;
    }

    this->setValue(output);
    this->removeLeadingZeros();
}

string Number::getValue() {
    return this->value;
}

void Number::setValue(const string &val) {
    Number::value = val;
}

void Number::setFloatingPos(const int& fp) {
    Number::floating_pos = fp;
}

int Number::getFloatingPos() const {
    return Number::floating_pos;
}

unsigned Number::size() {
    return this->value.size();
}

unsigned Number::getDigitFromPosition(long position) {
    if (position < 0)
        return 0;

    char digit = this->value[position];

    // #TODO: obsługa błędu
    if (digit < 48 || digit > 57)
        __builtin_trap();

    return (digit - '0');
}

void Number::setNumberInPosition(long position, char digit) {
    // todo tutaj jest dziwny błąd podczas debugu
    if (position < 0 || position > this->size() - 1)
        return;
//        __builtin_trap();
    if (digit < (0 + '0') || digit > (9 + '0'))
        return;
//        __builtin_trap();

    this->value[position] = digit;
}

void Number::setNumberInPosition(long position, unsigned digit) {
    this->setNumberInPosition(position, (char) (digit + '0'));
}

bool Number::isValueBigger(string val1, string val2) {
    if (val1.size() > val2.size())
        return true;
    else if (val1.size() < val2.size())
        return false;
    else
        for (int i = 0; i < val1.size(); ++i) {
            if (val1[i] > val2[i])
                return true;
            else if (val1[i] < val2[i])
                return false;
        }

    // is equal
    return false;
}

bool Number::operator>(const Number &r) {
    if (this->sign && !r.sign)
        return false;
    if (!this->sign && r.sign)
        return true;

    if (this->sign == r.sign) {
        if (this->value == r.value)
            return false;

        return this->isValueBigger(this->value, r.value);
    }

    return true;
}

bool Number::operator<(const Number &r) {
    if (!this->sign && r.sign)
        return false;
    if (this->sign && !r.sign)
        return true;

    if (this->sign == r.sign) {
        if (this->value == r.value)
            return false;

        return !this->isValueBigger(this->value, r.value);
    }

    return true;
}

string Number::add_coma(int place_of_comma){
    std::string val;
    val = "";
//    if(this->sign){
//        value += "-";
//    }
    for(int i = 0 ; i < this->size(); i++){
        if(i == place_of_comma) {
            val += (char) 46;
            val += this->getValue()[i];
        }
        else{
            val += this->getValue()[i];
        }
    }
    return val;
}

Number* Number::removeLeadingZeros() {
    while ((this->getValue()[0] == '0' && this->getValue()[1] != '.') || this->getValue()[0] == '-') {
        this->setValue(this->getValue().erase(0, 1));
    }

    if (this->getValue().empty()) {
        this->setValue("0");
        this->setSign(false);
    }

    return this;
}
