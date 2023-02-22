#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    bool isPrime = true;
    cin >> n;
    if(n == 0 || n == 1)
    {
        isPrime = false;
    }
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if(isPrime == true)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
    return 0;
}
