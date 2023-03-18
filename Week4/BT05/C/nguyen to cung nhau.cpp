#include <iostream>
#include <cmath>
using namespace std;

int GCF(int a, int b)
{
    if(b == 0)
    {
        return a;
    }else
    {
        return GCF(b, a%b);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    if(a < b)
    {
        if(GCF(b,a) == 1)
        {
            cout << "YES" << endl;
        }else
        {
            cout << "NO" << endl;
        }
    }else
    {
        if(GCF(a,b) == 1)
        {
            cout << "YES" << endl;
        }else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
