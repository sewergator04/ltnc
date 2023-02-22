#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    cout << (abs(x+y) + abs(x-y))/2 << endl;
    return 0;
}
