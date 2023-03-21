#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int toHop(int k, int n)
{
    int giaithuan = 1;
    int giaithuak = 1;
    int giaithuantruk = 1;
    for(int i = 1; i <= n; i++)
    {
        giaithuan *= i;
    }
    for(int i = 1; i <= k; i++)
    {
        giaithuak *= i;
    }
    for(int i = 1; i <= n-k; i++)
    {
        giaithuantruk *= i;
    }
    int ketqua = giaithuan/(giaithuak*giaithuantruk);
    return ketqua;
}

int KiemTra(int k, int n)
{
    if(0 <= k && k <= n && 1 <= n && n <= 20)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void nhapKN(vector<int>& sok, vector<int>& son)
{
    int khientai, nhientai;
    while(true)
    {
        cin >> khientai >> nhientai;
        if(khientai == nhientai && khientai == -1)
        {
            break;
        }
        if(KiemTra(khientai,nhientai) == 1)
        {
            sok.push_back(khientai);
            son.push_back(nhientai);
        }
    }
}

int main()
{
    vector<int> k;
    vector<int> n;
    nhapKN(k,n);
    int dodai = k.size();
    for(int i = 0; i < dodai; i++)
    {
        cout << toHop(k.at(i),n.at(i)) << endl;
    }
    return 0;
}
