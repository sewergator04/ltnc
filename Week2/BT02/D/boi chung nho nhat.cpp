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
    for(int i = x; i <= x*y; i += x)
    {
        if(i%y == 0)
        {
            cout << "BCNN la: " << i << endl;
            break;
        }
    }
    return 0;
}
