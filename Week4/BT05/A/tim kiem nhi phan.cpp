#include <iostream>
using namespace std;

int BinarySearchRec(int high, int low, int mang[], int key)
{
    if(low > high)
    {
        return -1;
    }
    int mid = (low+high)/2;
    if(mang[mid] == key)
    {
        return mid;
    }else if(mang[mid] > key)
    {
        return BinarySearchRec(mid-1,low,mang,key);
    }else if(mang[mid] < key)
    {
        return BinarySearchRec(high,mid+1,mang,key);
    }
}

void BinarySearch(int high, int low, int mang[], int key)
{
    bool isFound = false;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(mang[mid] == key)
        {
            isFound = true;
            break;
        }else if(mang[mid] > key)
        {
            high = mid-1;
        }else if(mang[mid] < key)
        {
            low = mid+1;
        }
    }
    if(isFound)
    {
        cout << "Non Recursion - Key is available " << endl;
    }else
    {
        cout << "Non Recursion - Key is not available" << endl;
    }
}
int main()
{
    int mang[10] = {1,2,3,4,5,6,7,8,9,10};
    int key = 0;
    int low = 0;
    int high = 9;
    BinarySearch(high,low,mang,key);
    if(BinarySearchRec(high,low,mang,key) == -1)
    {
        cout << "Recursion - Key is not available" << endl;
    }else
    {
        cout << "Recursion - Key is available" << endl;
    }
    return 0;
}
