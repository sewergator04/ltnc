#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    char bombs[a][b];
    int maps[a][b];
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cin >> bombs[i][j];
            maps[i][j] = 0;
            if(bombs[i][j] == '*')
            {
                maps[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(maps[i][j] != -1)
            {
                if(i - 1 >= 0)
                {
                    if(maps[i-1][j] == -1)
                      {
                          maps[i][j] += 1;
                      }
                    if(maps[i-1][j+1] == -1)
                      {
                           maps[i][j] += 1;
                      }
                      if(j - 1 >= 0 && maps[i-1][j-1] == -1)
                      {
                          maps[i][j] += 1;
                      }
                }
                if(j - 1 >= 0 && maps[i][j-1] == -1)
                {
                    maps[i][j] += 1;
                }
                if(maps[i][j+1] == -1)
                {
                    maps[i][j] += 1;
                }
                if(j - 1 >= 0 && maps[i+1][j-1] == -1)
                {
                    maps[i][j] += 1;
                }
                if(maps[i+1][j] == -1)
                {
                    maps[i][j] += 1;
                }
                if(maps[i+1][j+1] == -1)
                {
                    maps[i][j] += 1;
                }
            }
        }
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
           if(maps[i][j] != -1)
           {
               bombs[i][j] = maps[i][j] + '0';
           }
        }
    }
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            cout << bombs[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
