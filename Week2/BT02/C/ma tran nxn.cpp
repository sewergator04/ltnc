#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int lap = 0;
    int thaydoibatdau = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = thaydoibatdau; j <= n; j++)
        {
            cout << j << " ";
        }
        for(int x = 1; x <= lap; x++)
        {
            cout << x << " ";
        }
        thaydoibatdau++;
        lap++;
        cout << endl;
    }
    return 0;
}
