#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));
    const int n = 10000;
    int num[n];
    int dem = 0;
    bool isCorrect = false;
    for(int i = 0; i < n; i++)
    {
        num[i] = rand() %10000 + 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(num[i] == num[j])
            {
                cout << "YES" << endl;
                isCorrect = true;
                break;
            }
        }
        if(isCorrect == true)
        {
            break;
        }
    }
    if(isCorrect == false)
    {
        cout << "NO" << endl;
    }
    return 0;
}
