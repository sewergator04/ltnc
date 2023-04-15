#include <iostream>
#include <cstring>
using namespace std;
struct Point
{
    int x;
    int y;
};

void print(Point target)
{
    cout << &target.x << " " << &target.y << endl;
}

void printreferences(Point &target)
{
    cout << &target.x << " " << &target.y << endl;
}
int main()
{
    Point point;
    point.x = 10;
    point.y = 5;
    cout << &point.x << " " << &point.y << endl;
    print(point);
    printreferences(point);
    return 0;
}

//Nhận xét: lệnh cout đầu và hàm printreferences() cho ra cùng 1 địa chỉ
//Hàm print() in ra địa chỉ khác
