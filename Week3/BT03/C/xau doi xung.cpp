#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int dodai = n.length();
    int tam = dodai - 1;
    int dem = 0;
    if(n[0] != n[dodai-1])
    {
        cout << "NO" << endl;
        return 0;
    }
    int chinhgiua = dodai/2;
    for(int i = 0; i < chinhgiua; i++)
    {
        if(n[i] == n[tam])
            {
                dem++;
            }
            tam--;
    }
    if(chinhgiua == dem)
    {
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }

    return 0;
}
