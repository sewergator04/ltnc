#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a1,b1,c1,a2,b2,c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int tam = a1;
    int tam2 = a2;
    if(tam == 0 && tam2 == 0)
    {
        if(c2/b2 != c1/b1)
        {
            cout << "Vo nghiem" << endl;
        }else
        {
            cout << "x = 0, y = " << c2/b2;
        }
    }
    if(b2 == b1 && b1 == 0)
    {
        if(c1/a1 != c2/a2)
        {
            cout << "Vo nghiem" << endl;
        }else
        {
            cout << "x = " << c1/a1 << ", y = 0";
        }
    }
    if(tam >= tam2 && tam2 != 0)
    {
        b2 = b2*a1/a2;
        c2 = c2*a1/a2;
        b2 = b2 - b1;
        c2 = c2 - c1;
        if(b2 == 0 && c2 == 0)
        {
            cout << "Vo so nghiem" << endl;
        } else if(b2 == 0 && c2 != 0)
        {
            cout << "Vo nghiem" << endl;
        } else if(b2 != 0)
        {
            cout << "x = " << (c1 - b1*(c2/b2))/a1 << ", y = " << c2/b2 << endl;
        }
    } else if(tam < tam2 && tam != 0)
    {
        b1 = b1*a2/a1;
        c1 = c1*a2/a1;
        b1 = b1 - b2;
        c1 = c1 - c2;
        if(b1 == 0 && c1 == 0)
        {
            cout << "Vo so nghiem" << endl;
        } else if(b1 == 0 && c1 != 0)
        {
            cout << "Vo nghiem" << endl;
        } else if(b1 != 0)
        {
            cout << "x = " << (c2 - b2*(c1/b1))/a2 << ", y = " << c1/b1 << endl;
        }
    }
    if(a1 == b1 && b1 == c1)
    {
        if(a1 == 0)
        {
            cout << "Vo so nghiem";
        }
    } else if(a2 == b2 && b2 == c2)
    {
        if(a2 == 0)
        {
            cout << "Vo so nghiem";
        }
    }
    return 0;
}
