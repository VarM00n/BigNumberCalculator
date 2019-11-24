//
// Created by Cezary on 24.11.2019.
//

#include "Number.h"

Number::Number(std::string value, bool sign) {
    this->value = std::move(value);
    this->sign = sign;
}

/**
 * Returns digit from given position in number string
 * @param position
 * @return int 0-9
 */
unsigned Number::getDigitFromPosition(unsigned long position) {
    if (position < 0)
        return 0;

    char digit = this->value[position];

    // #TODO: obsługa błędu
    if (digit < 48 || digit > 57)
        throw std::exception();

    return (digit - '0');
}

unsigned Number::size() {
    return this->value.size();
}

void Number::setNumberInPosition(unsigned long position, char digit) {
    if (position < 0 || position > this->size() - 1)
        throw std::exception();
    if (digit < 0 || digit > 9)
        throw std::exception();

    this->value[position] = digit;
}

void Number::setNumberInPosition(unsigned long position, unsigned digit) {
    this->setNumberInPosition(position, (char) (digit + '0'));
}
