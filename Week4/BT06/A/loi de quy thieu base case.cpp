#include <iostream>
using namespace std;

double H(int N) {
   return H(N-1) + 1.0/N;
}

int main()
{
    int n = 10;
    cout << H(n);
    return 0;
}
// Nhận xét: Chương trình vẫn được biên dịch, nhưng báo lỗi trong lúc chạy
//Do không khởi tạo biến ban đầu N0 nên hàm được lặp vô tận.
