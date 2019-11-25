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
unsigned Number::getDigitFromPosition(long position) {
    if (position < 0)
        return 0;

    char digit = this->value[position];

    // #TODO: obsługa błędu
    if (digit < 48 || digit > 57)
        __builtin_trap();

    return (digit - '0');
}

unsigned Number::size() {
    return this->value.size();
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
