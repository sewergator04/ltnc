#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    srand(time(NULL));
    const int n = 100;
    int num[n];
    for(int i = 0; i < n; i++)
    {
        num[i] = rand()%100;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(num[j] < num[i])
            {
                int tam = num[i];
                num[i] = num[j];
                num[j] = tam;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}
