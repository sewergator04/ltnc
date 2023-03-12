#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
char** generatemap(int m, int n, int k)
{
    srand(time(NULL));
    char** initmap = new char*[m];
    for(int i = 0; i < m; i++)
    {
        *(initmap + i) = new char [n];
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            initmap[i][j] = '-';
        }
    }
    for(int i = 0; i < k; i++)
    {
        int hang = rand()%m;
        int cot = rand()%n;
        if(initmap[hang][cot] == '-')
        {
            initmap[hang][cot] = '*';
        }else
        {
            i--;
        }
    }
    return initmap;
}

int** ingamemap(int m, int n)
{
    int** ingame = new int*[m];
    for(int i = 0; i < m; i++)
    {
        *(ingame+i) = new int [n];
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ingame[i][j] = 0;
        }
    }
    return ingame;
}

void processguess(int x, int y, int** charmap, char** mapinited, int m, int n)
{
    if(x>1)
    {
        if(y > 1 && mapinited[x-1][y-1] == '*')
        {
            charmap[x][y]++;
        }
        if(mapinited[x-1][y] == '*')
        {
            charmap[x][y]++;
        }
        if(y < n - 1 && mapinited[x-1][y+1] == '*')
        {
            charmap[x][y]++;
        }
    }
    if(y > 1 && mapinited[x][y-1] == '*')
    {
        charmap[x][y]++;
    }
    if(y < n - 1 && mapinited[x][y+1] == '*')
    {
        charmap[x][y]++;
    }
    if(y >1 && x < m - 1 && mapinited[x+1][y-1] == '*')
    {
        charmap[x][y]++;
    }
    if(x < m - 1 && mapinited[x+1][y] == '*')
    {
        charmap[x][y]++;
    }
    if(x < m - 1 && y < n - 1 && mapinited[x+1][y+1] == '*')
    {
        charmap[x][y]++;
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << charmap[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    char** gamemap = generatemap(m,n,k);
    int** ongoing = ingamemap(m,n);
    /*for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << gamemap[i][j] << " ";
        }
        cout << endl;
    }*/
    maingameloop:
    cout << "Nhap toa do (x,y) can mo: ";
    int x,y;
    cin >> x >> y;
    if(gamemap[x][y] != '*')
    {
        cout << "O nay khong co bom" << endl;
        processguess(x,y,ongoing,gamemap,m,n);
        goto maingameloop;
    }else
    {
        cout << "YOU'RE DEAD!" << endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << gamemap[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
