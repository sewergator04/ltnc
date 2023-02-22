#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x,y;
    cin >> x >> y;
    int tam1 = x;
    int tam2 = y;
    if(tam1 < tam2)
    {
        int thaydoi = tam1;
        tam1 = tam2;
        tam2 = thaydoi;
    }
    while(tam2 != 0)
    {
        int thaydoi2 = tam2;
        tam2 = tam1%tam2;
        tam1 = thaydoi2;
    }
    cout << "x/y = " << x/tam1 << "/" << y/tam1 << endl;
    return 0;
}
