//Phan a
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string n;
    int dodai = n.length();
    for(int i = 0; i < dodai; i++)
    {
        cout << n[i];
    }
    cout << endl;
    cout << n << endl;
    return 0;
}
//Output: " " va " "


//Phan b
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string n = "abcd";
    int dodai = n.length();
    for(int i = 0; i < dodai; i++)
    {
        cout << n[i];
    }
    cout << endl;
    cout << n << endl;
    return 0;
}
//Output: "abcd" va "abcd"
//=> ket luan: 2 cach in string giong nhau
