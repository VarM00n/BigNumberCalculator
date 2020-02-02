#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <string>

class Number {
private:
    std::string value;
    /**
     * false - number is positive
     * true - number is negative
     */
    bool sign = false;
public:
    explicit Number(std::string value);

    Number(std::string value, bool sign);

    
    void setValue(const std::string &value);

    bool isSign() const;

    void setSign(bool sign);

    void setNumberInPosition(long position, char digit);

    void setNumberInPosition(long position, unsigned digit);

    /**
     * Returns digit from given position in number string
     * @param position
     * @return int 0-9
     */
    unsigned getDigitFromPosition(long position);

    unsigned size();

    std::string getValue();
};


#endif //CALCULATOR_NUMBER_H
