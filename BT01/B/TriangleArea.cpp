#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x,y,z;
    cin >> x >> y >> z;
    double s = (x+y+z)/2;
    cout << sqrt(s*(s-x)*(s-y)*(s-z)) << endl;
    return 0;
}
