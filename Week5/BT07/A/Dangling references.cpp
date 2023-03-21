#include <iostream>
using namespace std;
char* weird_string() {
   char c[] = "123345";
   return c;
}
int main()
{
    cout << weird_string();
    return 0;
}
//Cảnh báo của trình biên dịch: address of local variable 'c' returned [-Wreturn-local-addr]
//(Trả về địa chỉ của biến địa phương)
//Output của hàm main không có gì cả vì biến c đã bị hủy
