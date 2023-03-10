#include <iostream>
using namespace std;

int factorial(int x)
{
    int result;
    if(x == 1 || x == 0)
    {
        cout << "x = " << x << " at " << &x << endl;
        return 1;
    }else
    {
        result = x * factorial(x-1);
    }
    cout << "x = " << result << " at " << &result << endl;
    return result;
}

int main()
{
    int n;
    cin >> n;
    factorial(n);
    return 0;
}

//Nhận xét: Chuỗi giá trị giống nhau ở đầu 0x61f
//ký tự thứ 3 từ dưới lên đi từ b đến d
//Ký tự thứ 2 từ dưới lên có giá trị là b khi x = 1, lần lượt thay đổi theo thứ tự d 1 5 9 cho các giá trị x còn lại
//Ký tự cuối có giá trị là 0 khi x = 1, còn lại có giá trị = c
// => Kích thước của một stack frame là 4 bytes
//=> Có 9 stack frame trong hàm => kích thước của tất cả các stack frame là 9x4 = 36 bytes
