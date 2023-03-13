#include <iostream>
using namespace std;

long F(int n) {
   if (n == 0) return 0;
   else if (n == 1) return 1;
   else return F(n-1) + F(n-2);
}

int main()
{
    int n = 50;
    cout << F(n);
    return 0;
}
// Nhận xét: Chương trình vẫn chạy, nhưng mất tận 93.78s để tính toán

#include <iostream>
using namespace std;
int main()
{
    int n = 50;
    long long int f0 = 0;
    long long int f1 = 1;
    long long int sum = 0;
    for(int i = 2; i <= n;i++)
    {
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }
    cout << sum << endl;
    return 0;
}
//Nhận xét: Chương trình mất 0.066s để tính toán
//Kết luận: Vòng lặp chạy nhanh hơn rất nhiều đệ quy
