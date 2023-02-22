#include <iostream>
using namespace std;
int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    if(x == y && y == z)
    {
        cout << "true" << endl;
    }else
    {
        cout << "false" << endl;
    }
    return 0;
}
