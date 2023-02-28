#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;


int main() {
    int cantim;
    bool isFound = false;
    int num[3000];
    int temp = 0;
    ifstream doctest("test 1.txt");
    if(!doctest)
    {
        cout << "Doc test that bai" << endl;
    }else
    {
        cout << "Nhap so can tim: ";
        cin >> cantim;
        while(!doctest.eof())
        {
            doctest >> num[temp];
        }
        for(int i = 0; i < temp; i++)
        {
            if(cantim == num[i])
            {
                isFound = true;
                break;
            }
        }
        if(isFound)
        {
            cout << "So can tim ton tai" << endl;
        }else
        {
            cout << "So can tim khong ton tai" << endl;
        }
        doctest.close();
    }
    return 0;
}
