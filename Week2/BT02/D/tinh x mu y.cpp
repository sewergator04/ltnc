#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    int lap = x;
    int results = pow(x,y);
    for(int i = 1; i < y; i++)
    {
        x = x*lap;
    }
    cout << x << endl;
    cout << results << endl;
    return 0;
}
