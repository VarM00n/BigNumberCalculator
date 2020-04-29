#ifndef CALCULATOR_NUMBER_H
#define CALCULATOR_NUMBER_H

#include <string>

using namespace std;

class Number {
private:
    string value;
    /**
     * false - number is positive
     * true - number is negative
     */
    bool sign = false;

    bool floating = false;

    int floating_pos = 0;

    /**
     * Validing and fixing value string
     */
    void sanitizeValue();

public:
    // todo output prepare by value nie mogło być "00012312"
    explicit Number(const string& value);

    // todo output prepare by value nie mogło być "00012312"
    Number(const string& value, bool sign);

    // todo dodać konstruktor który utworzy obiekt number na podstawie np int, long, long long, unsigned ...

    string toString() const;

    bool isNegative() const;

    bool isPositive() const;

    void setSign(bool sign);

    void setFloatingPos(const int& floating_position);

    int getFloatingPos();

    // todo output prepare by value nie mogło być "00012312"
    void setValue(const string &value);

    void setNumberInPosition(long position, char digit);

    void setNumberInPosition(long position, unsigned digit);

    /**
     * Returns digit from given position in number string
     * @param position
     * @return int 0-9
     */
    unsigned getDigitFromPosition(long position);

    unsigned size();

    string getValue();

    string add_coma(int place_of_comma);



    /**
 * Comparison of val1 to val2
 * val1 > val2
 */
    static bool isValueBigger(string val1, string val2);

    // todo inkrementacja
    // todo dekrementacja
    // todo array operator

    bool operator> (const Number& r);
    bool operator< (const Number& r);
    bool operator== (const Number& r);
    bool operator!= (const Number& r);

    // todo dodawanie
    // todo odejmowanie
    // todo mnożenie
    // todo dzielenie

    friend ostream& operator<< (ostream& stream, const Number& num)
    {
        return stream << num.toString();
    }
};

#endif //CALCULATOR_NUMBER_H
