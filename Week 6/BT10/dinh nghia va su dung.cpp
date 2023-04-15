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
    cout << target.x << " " << target.y;
}

int main()
{
    Point point;
    point.x = 10;
    point.y = 5;
    print(point);
    return 0;
}
