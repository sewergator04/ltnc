/*#include <iostream>
using namespace std;
void arrfunction(int test[])
{
    test[2] = 0;
    test[9] = 0;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};  //arr[2] = 3, arr[9] = 10
    arrfunction(arr);
    cout << arr[2] << " " << arr[9] << endl;
    return 0;
}*/
//Kết quả: In ra 0 0 => arr[2] và arr[9] bị thay đổi
//=> pass-by-reference
#include <iostream>
#include <cstring>
using namespace std;
string uglify(string beautiful)
{
    beautiful = "You are ugly";
    return beautiful;
}
string uglify2(string &beautiful)
{
    beautiful = "You are ugly";
    return beautiful;
}
int main()
{
    string n = "You are beautiful";
    uglify(n);
    cout << n << endl;
    uglify2(n);
    cout << n << endl;
    return 0;
}
//Kết quả: Hàm 1 trả về You are beautiful, Hàm 2 trả về You are ugly
//=> String được truyền theo kiểu pass-by-value
