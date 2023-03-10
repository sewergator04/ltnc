#include <iostream>
using namespace std;
void referencing(int &refn)
{
    cout << &refn << endl;
}
int main()
{
    int n = 10;
    cout << &n << endl;
    referencing(n);
    return 0;
}
//2 địa chỉ bộ nhớ giống nhau => Biến tham chiếu và biến nó chiếu tới là cùng 1 biến trong bộ nhớ

#include <iostream>
using namespace std;
int main()
{
    int &n;
    cout << n << endl;
    return 0;
}
//Lỗi : error: 'n' declared as reference but not initialized
//=> Không thể khai báo một tham chiếu mà chưa chiếu tới biến nào
#include <iostream>
using namespace std;
int main()
{
    int nine = 9;
    int ten = 10;
    int &n = nine;
    cout << &n << " " << n << endl;
    n = ten;
    cout << &n << " " << n << endl;
    return 0;
}
//Nhận xét: Lệnh cout đầu cho ra địa chỉ 0x61fe0c và giá trị = 9
//Lệnh cout thứ 2 cho ra địa chỉ 0x61fe0c và giá trị = 10
//=> Có thể chiếu tới biến khác với đích ban đầu
