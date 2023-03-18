#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
    bool result = true;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0)
        {
            result = false;
        }
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime(i))
        {
            cout << i << " ";
        }
    }
    return 0;
}
