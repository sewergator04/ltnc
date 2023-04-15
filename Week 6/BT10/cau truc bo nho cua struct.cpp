#include <iostream>
#include <cmath>
using namespace std;
struct Point
{
    int x;
    int y;
};

int main()
{
    Point point;
    point.x = 10;
    point.y = 5;
    cout << &point << " " << &point.x << " " << &point.y;
    return 0;
}
//Nhận xét: Địa của x là 0x61fe18 và địa chỉ của y là 0x61fe1c => cách nhau 4 bytes = độ lớn của biến int
// địa chỉ của biến point = địa chỉ của point.x
// => các biến của 1 cấu trúc được xếp liền kể nhau, địa chỉ của cấu trúc chính là địa chỉ của biến đầu tiên
