#include <iostream>
using namespace std;

int count_even(int* arr, int arrsize)
{
    int counts = 0;
    for(int i = 0; i < arrsize; i++)
    {
        if(arr[i]%2 == 0)
        {
            counts++;
        }
    }
    return counts;
}
int main()
{
    int samplearr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << count_even(samplearr, 10) << endl;
    int firsthalf[5];
    int secondhalf[5];
    for(int i = 0; i < 5; i++)
    {
        firsthalf[i] = samplearr[i];
    }
    for(int i = 5; i < 10; i++)
    {
        secondhalf[i-5] = samplearr[i];
    }
    cout << count_even(firsthalf,5) << endl;
    cout << count_even(secondhalf,5) << endl;
    return 0;
}
