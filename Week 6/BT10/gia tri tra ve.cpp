#include <iostream>
#include <cmath>
using namespace std;
struct Point
{
    double x;
    double y;
};

Point mid_point(const Point A, const Point B)
{
    Point mid;
    mid.x = (A.x+B.x)/2;
    mid.y = (A.y+B.y)/2;
    return mid;
}

void print(Point target)
{
    cout << target.x << " " << target.y << endl;
}
int main()
{
    Point pointA, pointB;
    pointA.x = 10;
    pointA.y = 5;
    pointB.x = 1;
    pointB.y = -7;
    Point midab = mid_point(pointA,pointB);
    print(midab);
    return 0;
}
