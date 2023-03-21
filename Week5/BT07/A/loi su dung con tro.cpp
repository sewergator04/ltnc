//Lỗi chưa khởi tạo con trỏ
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int *pX;
    printf("%d\n", pX);
    printf("%d\n", *pX);
    *pX = 0;
    return 0;
}


//Lỗi truy nhập vào con trỏ null
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int *pX = NULL;
    printf("%d\n", pX);
    printf("%d\n", *pX);
    *pX = 0;
    return 0;
}

//Lỗi dangling reference
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int* weird_sum(int a, int b) {

int c;

c = a + b;

return &c;

}
int main()
{
    int a = 20, b = 25, *pG;
    cout << *weird_sum(a,b);
    return 0;
}
