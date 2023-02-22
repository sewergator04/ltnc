#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int gannhat = 1e9;
    int trungbinh = a+b+c+d+e/5;
    int ogiua = 0;
    gannhat = abs(a - trungbinh);
    if(gannhat >= abs(b-trungbinh))
    {
        gannhat = abs(b-trungbinh);
        ogiua = 1;
    }
    if(gannhat >= abs(c-trungbinh))
    {
        gannhat = abs(c-trungbinh);
        ogiua = 2;
    }
    if(gannhat >= abs(d-trungbinh))
    {
        gannhat = abs(d-trungbinh);
        ogiua = 3;
    }
    if(gannhat >= abs(e-trungbinh))
    {
        gannhat = abs(e-trungbinh);
        ogiua = 4;
    }
    switch (ogiua)
    {
case 1:
    cout << a << endl;
    break;
case 2:
    cout << b << endl;
    break;
case 3:
    cout << c << endl;
    break;
case 4:
    cout << d << endl;
    break;
    }

    return 0;
}
