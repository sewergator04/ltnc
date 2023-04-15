#include <iostream>
#include <cmath>
using namespace std;
void swap_pointers(char* &x, char* &y)
{
   char *tmp;
   tmp = x;
   x = y;
   y = tmp;
}
int main()
{
   char a[] = "I should print second";
   char b[] = "I should print first";

   char *s1 = a;
   char *s2 = b;
   swap_pointers(s1,s2);
   cout << "s1 is " << s1 << endl;
   cout << "s2 is " << s2 << endl;
   return 0;
}

//Nhận xét: Con trỏ được truyền vào theo kiểu copy giá trị
//=> Cách sửa: chuyển thành tham chiếu
