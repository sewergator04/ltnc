#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string f0,f1;
    int n;
    f0 = "a";
    f1 = "b";
    string fn;
    cin >> n;
    if(n == 0)
    {
        cout << f0 << endl;
    }else if(n == 1)
    {
        cout << f1 << endl;
    }else
    {
         for(int i = 2; i <= n; i++)
         {
             fn = f1 + f0;
             f0 = f1;
             f1 = fn;
         }
    cout << fn << endl;
    }
    return 0;
}
