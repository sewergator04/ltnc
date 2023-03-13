#include <iostream>
using namespace std;

double H(int N) {
   if (N == 1) return 0.0;
   else return H(N-1) + 1.0/N;
}

int main()
{
    int n = 1000000;
    cout << H(n);
    return 0;
}
// Nhận xét: Chương trình vẫn được biên dịch, nhưng báo lỗi trong lúc chạy
//Do số truyền vào quá lớn => chương trình phải thực hiện vòng lặp quá nhiều lần
