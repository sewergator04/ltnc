#include <iostream>
using namespace std;
int main()
{
    bool isOrdered = false;
    int x,y,z;
    cin >> x >> y >> z;
    if(x > y && y > z)
    {
        isOrdered = true;
    }else if(x < y && y < z)
    {
        isOrdered = true;
    }
    cout << isOrdered << endl;
    return 0;
}
