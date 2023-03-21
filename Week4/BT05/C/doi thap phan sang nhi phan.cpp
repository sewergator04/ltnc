#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void binaryconversion(int n)
{
    vector<int> reversebinary;
    while(n != 0)
    {
        reversebinary.push_back(n%2);
        n = n/2;
    }
    int vecsize = reversebinary.size();
    for(int i = vecsize - 1; i >= 0; i--)
    {
        cout << reversebinary.at(i);
    }
}
int main()
{
    int num = 100;
    binaryconversion(num);
    return 0;
}
