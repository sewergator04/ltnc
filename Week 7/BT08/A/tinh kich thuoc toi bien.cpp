#include <iostream>
#include <cmath>
using namespace std;
int main( )
{
   char a[4] = "abc";
   for (char *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}
//Nhận xét: con trỏ lần lượt chạy đến từng phần tử của mảng

//b) chương trình với mảng int
#include <iostream>
#include <cmath>
using namespace std;
int main( )
{
   int a[4] = {1,2,3};
   for (int *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}


//c) chương trình với mảng double
#include <iostream>
#include <cmath>
using namespace std;
int main( )
{
   double a[4] = {1.6,2.7,3.3};
   for (double *cp = a; (*cp) != '\0'; cp++) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}

//d) sửa chương trình
#include <iostream>
#include <cmath>
using namespace std;
int main( )
{
   double a[4] = {1.6,2.7,3.3};
   for (double *cp = a; (*cp) != '\0'; cp+=2) {
      cout << (void*) cp << " : " << (*cp) << endl;
   }
   return 0;
}
//Nhận xét: sửa thành cp+=2 sẽ in ra kết quả ngẫu nhiên ngoài mảng
