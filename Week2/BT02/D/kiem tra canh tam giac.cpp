#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int loaitamgiac = 0;
    if(a+b > c && a+c > b)
    {
        if(b+c > a)
        {
            loaitamgiac = 1;
        }
    }
    if(a == b && b == c)
    {
        loaitamgiac = 2;
    }else if(a == b || b== c)
    {
        loaitamgiac = 3;
    }else if(a == c)
    {
        loaitamgiac = 3;
    }else if(a > b && a > c)
    {
        if(a*a == b*b + c*c)
        {
            loaitamgiac = 4;
        }
    } else if(b > a && b > c)
    {
      if(b*b == a*a + c*c)
        {
            loaitamgiac = 4;
        }
    }else if(c > b && c > a)
    {
        if(c*c == b*b + a*a)
        {
            loaitamgiac = 4;
        }
    }
    if(a <= 0 || b <= 0)
    {
        loaitamgiac = 0;
    }else if(c <= 0)
    {
        loaitamgiac = 0;
    }
    switch (loaitamgiac)
    {
        case 0:
        cout << "Invalid" << endl;
        break;
        case 1:
        cout << a+b+c << endl;
        cout << "thuong" << endl;
        break;
        case 2:
        cout << a+b+c << endl;
        cout << "deu" << endl;
        break;
        case 3:
        cout << a+b+c << endl;
        cout << "can" << endl;
        break;
        case 4:
        cout << a+b+c << endl;
        cout << "vuong" << endl;
        break;
    }
    return 0;
}
