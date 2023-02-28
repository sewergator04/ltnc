//Đã làm tại Hackerrank. Đúng 10/10 test cases

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    int A[n];
    int B[n+1];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n+1; i++)
    {
        cin >> B[i];
    }
    for(int i = 0; i < n+1; i++)
    {
        int dem = 0;
        for(int j = 0; j < n; j++)
        {
            if(A[j] != B[i])
            {
                dem++;
            }else
            {
                A[j] = -1;
                break;
            }
        }
        if(dem == n)
        {
            cout << B[i] << endl;
            break;
        }
    }
    return 0;
}
