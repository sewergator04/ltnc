//Phan a
#include <iostream>
using namespace std;

int main()
{
    char mang[10] = {30,31,37,33,34,35,36,37,38,39};
    cout << "Gia tri mang ban dau: ";
    for(int i = 0; i < 10; i++)
    {
        cout << mang[i] << " ";
    }
    cout << endl;
    cout << "Gia tri tai index = -1: ";
    cout << mang[-1] << endl;
    cout << "Gia tri tai index = 10: ";
    cout << mang[10] << endl;
    cout << "Gia tri tai index = 11: ";
    cout << mang[11] << endl;
    return 0;
}

//Ket luan: Khong co loi
// cac bien duoc in ra o -1 la ngau nhien, khong ton tai trong mang
// cac bien tai 10 va 11 khong ton tai, in ra khoang trong

