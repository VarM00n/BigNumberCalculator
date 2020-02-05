#include "Number.h"

using namespace std;

Number::Number(const string &val, bool sign) {
    this->sign = sign;
    setValue(val);
}

Number::Number(const string &val) {
    if (val[0] == '-')
        sign = true;
    setValue(val);
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

string Number::toString() {
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

    // get rid of all chars expect digits
    for (char i : value) {
        if (i >= 48 && i <= 57)
            output += i;
    }

    // remove unnecessary zeros from the beginning of the number
    while (output[0] == '0')
        output.erase(0, 1);

    // empty value is zero
    if (output.empty()) {
        sign = false;
        value = "0";
        return;
    }

    value = output;

    if (value == "0")
        sign = false;
}

string Number::getValue() {
    return this->value;
}

void Number::setValue(const string &val) {
    Number::value = val;
    sanitizeValue();
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
    if (position < 0 || position > this->size() - 1)
        __builtin_trap();
    if (digit < (0 + '0') || digit > (9 + '0'))
        __builtin_trap();

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

bool Number::operator==(const Number &r) {
    return this->sign == r.sign && this->value == r.value;
}

bool Number::operator!=(const Number &r) {
    return !operator==(r);
}
