#include <iostream>
using namespace std;

void demofunction(int x)
{
    cout << &x << endl;
}
void demofunction2(int &x)
{
    cout << &x << endl;
}

int main()
{
    int n;
    cin >> n;
    cout << &n << endl;
    demofunction(n);
    demofunction2(n);
    return 0;
}
// Địa chỉ của đối số là 0x61fe1c
// Địa chỉ của tham trị là 0x61fdf0
// Địa chỉ của tham biến là 0x61fe1c
