#include <iostream>
using namespace std;

void binarysearchptr(int* arr, int arrsize, int key)
{
    int right = 0;
    int left = arrsize - 1;
    bool isFound = false;
    while(right <= left)
    {
        int mid = (right+left)/2;
        if(*(arr+mid) == key)
        {
            cout << "Key is at " << mid << endl;
            isFound = true;
            break;
        }else if(*(arr+mid) > key)
        {
            left = mid - 1;
        }else if(*(arr+mid) < key)
        {
            right = mid + 1;
        }
    }
    if(!isFound)
    {
        cout << "Key is unavailable" << endl;
    }
}
int main()
{
    int* arrangedarr = new int[10];
    int key = 1;
    for(int i = 0; i < 10; i++)
    {
        *(arrangedarr+i) = i+1; //Tăng dần từ 1 đến 10
    }
    binarysearchptr(arrangedarr,10,key);
    delete [] arrangedarr;
    return 0;
}
