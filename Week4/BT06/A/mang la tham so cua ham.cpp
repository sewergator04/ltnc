#include <iostream>
using namespace std;

void arraylocation(int arr[])
{
    cout << arr[0] << " " << &arr << endl;
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    arraylocation(arr);
    cout << arr[0] << " " << &arr << endl;
    return 0;
}
//Nhận xét: Cả 2 kết quả từ hàm void và main đều cho cùng 1 địa chỉ và giá trị phần tử thứ nhất
//=> Mảng được truyền theo cơ chế pass-by-reference
