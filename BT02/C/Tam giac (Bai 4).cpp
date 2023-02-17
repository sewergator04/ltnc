#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int daucach = 0;
    int sao = 2*n-1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= daucach; j++)
        {
            cout << " ";
        }
        for(int x = 1; x <= sao; x++)
        {
            cout << "*";
        }
        daucach++;
        sao -= 2;
        cout << endl;
    }
    return 0;
}
