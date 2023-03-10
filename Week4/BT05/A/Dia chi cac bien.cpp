#include <iostream>
using namespace std;
int main()
{
    int a[3];
    char b[3];
    cout << (void *)&a[0] << endl;
    cout << (void *)&a[1] << endl;
    cout << (void *)&a[2] << endl;
    cout << (void *)&b[0] << endl;
    cout << (void *)&b[1] << endl;
    cout << (void *)&b[2] << endl;
    return 0;
}
//Nhận xét: Địa chỉ của mảng a và b đều có đầu 0x61fe
//mảng a có đuôi bắt đầu từ 14, tăng thêm 4 đơn vị khi chuyển sang địa chỉ biến khác
//mảng b có đuôi bắt đầu từ 11, tăng thêm 1 đơn vị khi chuyển sang địa chỉ biến khác

#include <iostream>
using namespace std;
int main()
{
    int a[3];
    char b[3];
    a[0] = 10;
    a[1] = 22;
    a[2] = 36;
    b[0] = 'f';
    b[1] = 'z';
    b[2] = 'd';
    cout << (void *)&a[0] << endl;
    cout << (void *)&a[1] << endl;
    cout << (void *)&a[2] << endl;
    cout << (void *)&b[0] << endl;
    cout << (void *)&b[1] << endl;
    cout << (void *)&b[2] << endl;
    return 0;
}
//Nhận xét: địa chỉ của các phần tử không đổi khi chèn giá trị vào
