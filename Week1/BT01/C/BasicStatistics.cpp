#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num[n];
    int lonnhat = -1e9;
    int nhonhat;
    double trungbinh = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(lonnhat <= num[i])
        {
            lonnhat = num[i];
        }
        trungbinh += num[i];
    }
    nhonhat = lonnhat;
    trungbinh = trungbinh/n;
    for(int i = 0; i < n; i++)
    {
        if(nhonhat >= num[i])
        {
            nhonhat = num[i];
        }
    }
    cout << "Mean: " << trungbinh << endl;
    cout << "Max: " << lonnhat << endl;
    cout << "Min: " << nhonhat << endl;
    return 0;
}
