//Phan a
#include <iostream>
using namespace std;

int main()
{
   char daytab[2][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼


#include <iostream>
using namespace std;

int main()
{
   char daytab[2][12] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
   };

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//=> Ket luan: Ca 2 cach cho ra cung 1 ket qua




//Phan b
#include <iostream>
using namespace std;

int main()
{
   char daytab[2][12] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31};

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼

#include <iostream>
using namespace std;

int main()
{
   char daytab[2][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31}
};


   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼


//Phan c
#include <iostream>
using namespace std;

int main()
{
   char daytab[][12] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼


#include <iostream>
using namespace std;

int main()
{
   char daytab[2][] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Loi: declaration of 'daytab' as multidimensional array must have bounds for all dimensions except the first


#include <iostream>
using namespace std;

int main()
{
   char daytab[][] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Loi: declaration of 'daytab' as multidimensional array must have bounds for all dimensions except the first



#include <iostream>
using namespace std;

int main()
{
   char daytab[][12] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
   };

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Output: ▼ ∟ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼
//        ▼ ↔ ▼ ▲ ▼ ▲ ▼ ▼ ▲ ▼ ▲ ▼


#include <iostream>
using namespace std;

int main()
{
   char daytab[2][] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
   };

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Loi: declaration of 'daytab' as multidimensional array must have bounds for all dimensions except the first


#include <iostream>
using namespace std;
int main()
{
   char daytab[][] = {
  31,28,31,30,31,30,31,31,30,31,30,31,
  31,29,31,30,31,30,31,31,30,31,30,31
   };

   for(int i = 0 ; i < 2; i++)
   {
       for(int j = 0; j < 12; j++)
       {
           cout << daytab[i][j] << " ";
       }
       cout << endl;
   }
    return 0;
}
//Loi: declaration of 'daytab' as multidimensional array must have bounds for all dimensions except the first
