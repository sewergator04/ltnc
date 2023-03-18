#include <iostream>
#include <cmath>
using namespace std;

void print(int spacenums, int starnums)
{
    for(int i = 0; i < spacenums; i++)
    {
        cout << " ";
    }
    for(int i = 0; i < starnums; i++)
    {
        cout << "*";
    }
    cout << endl;
}
int main()
{
    int triangle;
    cin >> triangle;
    int spaces = triangle - 1;
    int stars = 1;
    for(int i = 0; i < triangle; i++)
    {
        print(spaces,stars);
        spaces--;
        stars += 2;
    }
    return 0;
}
