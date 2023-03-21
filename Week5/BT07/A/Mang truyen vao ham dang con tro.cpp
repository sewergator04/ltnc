#include <iostream>
using namespace std;

void printsize(int arr[])
{
    int sizearroffunction = sizeof(arr);
    cout << sizearroffunction;
}
int main()
{
    int samplearr[10];
    int sizearr = sizeof(samplearr);
    cout << sizearr << endl;
    printsize(samplearr);
    return 0;
}
//Nhận xét: sizeof() trong hàm main trả về 40, vì mảng có 10 phần tử, mỗi phần tử chiếm 4 byte bộ nhớ
//sizeof trong hàm void trả về 8, vì đó là độ lớn của 1 con trỏ
