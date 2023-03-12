#include <iostream>
using namespace std;

bool eq(int arr1[], int arr2[], int sizeofarr)
{
    bool isEqual = true;
    for(int i = 0; i < sizeofarr; i++)
    {
        if(arr1[i] != arr2[i])
        {
            isEqual = false;
        }
    }
    return isEqual;
}
int main()
{
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int bothsize = 10;
    bool result = eq(arr1,arr2,bothsize);
    if(result)
    {
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }
    return 0;
}
