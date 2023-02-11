#include <iostream>
using namespace std;
int main()
{
    for(int i = 0; i < 24; i++)
    {
        if(i == 0)
        {
            cout << "12 midnight" << endl;
        }else if(i >= 1 && i <= 11)
        {
            cout << i << " am" << endl;
        }else if(i >= 13 && i <= 23)
        {
            cout << i-12 << " pm" << endl;
        }else if(i == 12)
        {
            cout << "12 noon" << endl;
        }
    }
    return 0;
}
