#include <iostream>
#include <cmath>
using namespace std;
//Hàm có floor ceil
int nearestwithcmath(double num)
{
    int floorval = floor(num);
    int ceilval = ceil(num);
    if(abs(abs(floorval)-abs(num)) < abs(abs(ceilval) - abs(num)))
    {
        return floorval;
    }else
    {
        return ceilval;
    }
}
// Hàm không có floor ceil
double nearestwithoutcmath(double num)
{
    int ceilval = num;
    int floorval;
    if(num > 0)
    {
        floorval = num+1;
    }else
    {
        floorval = num-1;
    }
    if(abs(abs(floorval)-abs(num)) < abs(abs(ceilval) - abs(num)))
    {
        return floorval;
    }else
    {
        return ceilval;
    }
}
int main()
{
    cout << nearestwithoutcmath(2.6) << endl;
    cout << nearestwithcmath(2.6) << endl;
    return 0;
}
