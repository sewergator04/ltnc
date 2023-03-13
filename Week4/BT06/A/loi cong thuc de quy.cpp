#include <iostream>
using namespace std;

double H(int N) {
   if (N == 1) return 1.0;
   return H(N) + 1.0/N;
}

int main()
{
    int n = 10;
    cout << H(n);
    return 0;
}
// Nhận xét: Chương trình vẫn được biên dịch, nhưng báo lỗi trong lúc chạy
//Do thiếu lệnh else của mệnh đề if nên hàm trả về 2 kết quả khác nhau.
