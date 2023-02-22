#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    srand(time(0));
    int x,y;
    int choice;
    x = rand() % 100;
    y = rand() % 100;
    cout << "Bob da xem the ben trai" << endl;
    if(x >= 50)
    {
        cout << "Bob chon the ben trai" << endl;
        choice = 1;
    }else
    {
        cout << "Bob chon the ben phai" << endl;
        choice = 2;
    }
    cout << "Ket qua 2 the la: " << x << " va " << y << endl;
    if(x > y)
    {
        if(choice == 1)
        {
            cout << "Bob thang" << endl;
        }else if(choice == 2)
        {
            cout << "Bob thua" << endl;
        }
    }else if(x < y)
    {
        if(choice == 1)
        {
            cout << "Bob thua" << endl;
        }else if(choice == 2)
        {
            cout << "Bob thang" << endl;
        }
    }else if(x == y)
    {
        cout << "2 so bang nhau. Khong hop le" << endl;
    }
    return 0;
}
