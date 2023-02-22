#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string n;
    cin >> n;
    int* mang;
    int dem = 0;
    int nhapso = 1;
    while (nhapso != 0)
    {
        cin >> nhapso;
        mang[dem] = nhapso;
        dem++;
    }

    delete [] mang;
    return 0;
}
