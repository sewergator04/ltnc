//Cách a
#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; i <= 100; i++)
    {
        if(i%2 == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}

//Cách b
#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; ; i++)
    {
        if(i%2 == 0)
        {
            cout << i << " ";
        }
        if(i == 100)
        {
            break;
        }
    }
    return 0;
}

//Cách c
#include <iostream>
using namespace std;
int main()
{
    int lim = 1;
    while(1412 == 1412)
    {
        if(lim%2 == 0)
        {
            cout << lim << " ";
        }
        if(lim == 100)
        {
            return 0;
        }
        lim++;
    }
    return 0;
}

//Cách d
#include <iostream>
using namespace std;
int main()
{
    int lim = 1;
    while(1412 == 1412)
    {
        if(lim%2 == 0)
        {
            cout << lim << " ";
        }
        if(lim == 100)
        {
            break;
        }
        lim++;
    }
    return 0;
}


//Cách e
#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; i <= 100; i++)
    {
        if(i%2 != 0)
        {
            continue;
        }else
        {
            cout << i << " ";
        }
    }
    return 0;
}

// ==> Cách a là cách tốt nhất

