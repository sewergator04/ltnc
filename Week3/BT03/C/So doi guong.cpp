
//Đã làm tại Hackerearth. Đúng mọi test case

#include <iostream>
#include <string>
using namespace std;
struct limits
{
	int A;
	int B;
	int demsolan = 0;
};
int main() {
	int num;
	cin >> num;
	limits limit[num];
	for(int i = 0; i < num; i++)
	{
		cin >> limit[i].A >> limit[i].B;
	}
	for(int i = 0; i < num; i++)
	{

		int dau = limit[i].A;
		int cuoi = limit[i].B;
		for(int j = dau; j <= cuoi; j++)
		{
			string kiemtra = to_string(j);
			int dodai = kiemtra.length();
			int tam = dodai - 1;
			int dem = 0;
            int chinhgiua = dodai/2;
            for(int k = 0; k < chinhgiua; k++)
            {
                if(kiemtra[k] == kiemtra[tam])
                {
                    dem++;
                }
                tam--;
            }
            if(chinhgiua == dem)
		    {
			    limit[i].demsolan++;
		    }
		}
	}
	for(int i = 0; i < num; i++)
	{
		cout << limit[i].demsolan << endl;
	}
	return 0;
}
