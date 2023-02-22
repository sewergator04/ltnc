#include <iostream>
#include <cmath>
using namespace std;

void dichso(int socandich)
{
    switch (socandich)
    {
    case 1:
        cout << "one ";
        break;
    case 2:
        cout << "two ";
        break;
    case 3:
        cout << "three ";
        break;
    case 4:
        cout << "four ";
        break;
    case 5:
        cout << "five ";
        break;
    case 6:
        cout << "six ";
        break;
    case 7:
        cout << "seven ";
        break;
    case 8:
        cout << "eight ";
        break;
    case 9:
        cout << "nine ";
        break;
    }
}

void dichsochuc (int sochuccandich, int sohangdonvi)
{
    switch (sochuccandich)
    {
    case 1:
        switch (sohangdonvi)
    {
    case 0:
        cout << "ten ";
        break;
    case 1:
        cout << "eleven ";
        break;
    case 2:
        cout << "twelve ";
        break;
    case 3:
        cout << "thirteen ";
        break;
    case 4:
        cout << "fourteen ";
        break;
    case 5:
        cout << "fifteen ";
        break;
    case 6:
        cout << "sixteen ";
        break;
    case 7:
        cout << "seventeen ";
        break;
    case 8:
        cout << "eighteen ";
        break;
    case 9:
        cout << "nineteen ";
        break;
    }
        break;
    case 2:
        cout << "twenty";
        break;
    case 3:
        cout << "thirty";
        break;
    case 4:
        cout << "forty";
        break;
    case 5:
        cout << "fifty";
        break;
    case 6:
        cout << "sixty";
        break;
    case 7:
        cout << "seventy";
        break;
    case 8:
        cout << "eighty";
        break;
    case 9:
        cout << "ninety";
        break;
    }
}

void dichhangso(int hangso)
{
    int hangtram = 0;
    int hangchuc = 0;
    int hangdonvi = 0;
    if(hangso/100 != 0)
    {
        hangtram = hangso/100;
        dichso(hangtram);
        cout << "hundred ";
    }
    if(hangso/10 != 0)
    {
        hangchuc = (hangso - hangtram*100)/10;
        hangdonvi = hangso - hangchuc*10 - hangtram*100;
        dichsochuc(hangchuc, hangdonvi);
        if(hangchuc != 1)
        {
            if(hangchuc != 0)
            {
                cout << "-";
                dichso(hangdonvi);
            }
            if(hangchuc == 0)
            {
                dichso(hangdonvi);
            }
        }
    }
    if(hangso < 10)
    {
        dichso(hangso);
    }
}

void phantichso(int so)
{
    int hangtrieu = 0;
    int hangtram = 0;
    int hangnghin = 0;
    if(so/1000000 != 0)
    {
        hangtrieu = so/1000000;
        dichhangso(hangtrieu);
        cout << "million ";
    }
    if(so/1000 != 0)
    {
        hangnghin = (so - hangtrieu*1000000)/1000;
        hangtram = so - hangtrieu*1000000 - hangnghin*1000;
        dichhangso(hangnghin);
        if(hangnghin != 0)
        {
            cout << "thousand ";
        }
        dichhangso(hangtram);
    }
    if(so < 1000)
    {
        dichhangso(so);
    }
}
int main()
{
    long long int so;
    cin >> so;
    if(so > 0)
    {
        phantichso(so);
    }else if(so < 0)
    {
        cout << "negative ";
        phantichso(abs(so));
    } else if(so == 0)
    {
        cout << "zero";
    }
    return 0;
}

