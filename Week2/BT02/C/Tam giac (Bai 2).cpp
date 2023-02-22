#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sao = n;
    int daucach = 0;
    for(int i = 0; i < n; i++)
    {
        for(int x = 1; x <= daucach; x++)
        {
            cout << " ";
        }
        for(int j = 1; j <= sao; j++)
        {
            cout << "*";
        }
        sao--;
        daucach++;
        cout << endl;
    }
    return 0;
}
