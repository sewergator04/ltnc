#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sotruoc = -1;
    while(n >= 0)
    {
        if(sotruoc != n)
        {
            cout << n << " ";
        }
        sotruoc = n;
        cin >> n;
    }
    cout << n << endl;
    return 0;
}
