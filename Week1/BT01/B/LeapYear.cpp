#include <iostream>
using namespace std;
int main()
{
    int year;
    bool isLeap = false;
    cin >> year;
    if(year%4 == 0)
    {
        isLeap = true;
    }
    if(year%100 == 0)
    {
        if(year%400 != 0)
        {
            isLeap = false;
        }else
        {
            isLeap = true;
        }
    }
    if(isLeap == true)
    {
        cout << "true" << endl;
    }else
    {
        cout << "false" << endl;
    }
    return 0;
}
