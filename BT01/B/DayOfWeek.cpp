#include <iostream>
using namespace std;
int main()
{
    int d,m,y;
    cin >> d >> m >> y;
    int hangso[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if(m < 3)
    {
        y--;
    }
    int ngaycantim = (y + y / 4 - y / 100 + y / 400 + hangso[m - 1] + d)%7;
    switch(ngaycantim)
    {
    case 0:
        cout << "Sunday" << endl;
        break;
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    }
    return 0;
}
