#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    if(x < y)
    {
        int tam = x;
        x = y;
        y = tam;
    }
    while(y != 0)
    {
        int tam = y;
        y = x%y;
        x = tam;
    }
    cout << x << endl;
    return 0;
}
