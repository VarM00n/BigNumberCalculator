#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dodawanie
{
private:

public:
    string pierwsza_l;
    string druga_l;
    string dodawanie(string liczba1, string liczba2);
    void wpisywanie();
    string mnozenie(string pierwsza_l, string druga_l);
};

void Dodawanie::wpisywanie()
{
    // ./skrypt.sh arg1 arg2
    cin >> pierwsza_l;
    cin >> druga_l;
}

string Dodawanie::dodawanie(string liczba1, string liczba2)
{
    unsigned long maks_rozmiar = liczba1.size();
    if(liczba2.size() > liczba1.size()) maks_rozmiar = liczba2.size();
    string wynik;
    int przeniesienie = 0;
    int i = (int) (liczba1.size()-1);
    int k = (int) (liczba2.size()-1);
    for(int j =0; j < maks_rozmiar+1; i--, k--, j++) {
        int pierwsza = (int) liczba1[i]-48;
        int druga = (int) liczba2[k]-48;
        if( k < 0){
            druga = 0;
        }
        if( i < 0){
            pierwsza = 0;
        }
            wynik.insert(0,to_string(((pierwsza + druga + przeniesienie) % 10)));
            przeniesienie = (pierwsza + druga + przeniesienie) / 10;
    }
    if(wynik[0] == 48){
        wynik.erase(0,1);
    }
    return wynik;
}

string Dodawanie::mnozenie(string liczba1, string liczba2)
{
    if(liczba1.size() < liczba2.size()) swap(liczba1, liczba2);
    vector<string> tu_sum = {};
    for(int i = liczba1.size()-1; i >= 0; i--) { //for po mniejszej liczbie
        string temp = "";
        int przeniesienie = 0;
        for (int k = liczba1.size() - i - 1; k > 0; --k)
            temp.insert(0, "0");
        for(int j = liczba2.size()-1; j >= 0; j--) { //for po większej liczbie
            int pierwsza = (int) liczba1[i]-48;
            int druga = (int) liczba2[j]-48;
            int w = (pierwsza * druga + przeniesienie);
            temp.insert(0,to_string((w % 10)));
            przeniesienie = w / 10;
        }
        temp.insert(0, to_string(przeniesienie));
        if(temp[0] == 48){
            temp.erase(0,1);
        }
        tu_sum.push_back(temp);
    }
    string c = "";
    for (const auto &i : tu_sum) {
        c = dodawanie(c, i);
    }
    return c;
}

int main() {
    Dodawanie dzialanie;
//    cout << dzialanie.dodawanie("779159259269", "5925925926000");
    dzialanie.wpisywanie();
//    cout << endl;
//    cout << dzialanie.mnozenie(dzialanie.pierwsza_l, dzialanie.druga_l);
    cout << dzialanie.mnozenie(dzialanie.pierwsza_l, dzialanie.druga_l);
    return 0;
}