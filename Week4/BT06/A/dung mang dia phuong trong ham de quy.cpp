#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int sum(int sizearr)
{
    int lol[200];
    if(sizearr = 0)
    {
        return lol[0];
    }else
    {
        return sum(sizearr - 1);
    }
}
int main()
{
    sum(200);
    return 0;
}
