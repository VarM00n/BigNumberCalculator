#include <iostream>
#include <string>

#include "Calculator.h"

using namespace std;


int main(){
    Calculator calc;

    string a;
    cin >> a;
    string b;
    cin >> b;
    Number n1(a);
    Number n2(b);
    cout << calc.interpreterForSubstract(a,b);
    return 0;
}


//int main(int argc, char **argv) {
//    Calculator calc;
//
//    string add = "+";
//    string sub = "-";
//    string mul = "*";
//
//    if(argv[2] == add)
//    {
//        string a = argv[1];
//        string b = argv[3];
//
//        cout << calc.addition(a, b);
//    }
//    else if(argv[2] == sub)
//    {
//        string a = argv[1];
//        string b = argv[3];
//
//        cout << calc.substract(a, b);
//    }
//    else if(argv[2] == mul)
//    {
//        string a = argv[1];
//        string b = argv[3];
//
//        cout << calc.multiplication(a, b);
//    }
//    return 0;
//}