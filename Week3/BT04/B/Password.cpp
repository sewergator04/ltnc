//Đã làm tại Hackerearth. Đúng 8/10 test cases

#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int num;
	cin >> num;
	string pass[num];
	char* tempfirst = new char[num];
	char* templast = new char[num];
	string* suspects1 = new string[num];
	string* suspects2 = new string[num];
	string result;
	for(int i = 0; i < num; i++)
	{
		cin >> pass[i];
		suspects1[i] = "fillthehole";
		suspects2[i] = "nonemptyhole";
	}
	for(int i = 0; i < num; i++)
	{
		int dodai = pass[i].length();
		templast[i] = pass[i][dodai-1];
		tempfirst[i] = pass[i][0];
	}
	for(int i = 0; i < num; i++)
	{
		for(int j = i+1; j  < num; j++)
		{
			if(tempfirst[i] == templast[j])
			{
				suspects1[i] = pass[i];
				suspects2[i] = pass[j];
			}
		}
	}
	for(int i = 0; i < num; i++)
	{
		if(suspects1[i] != "fillthehole" && suspects2[i] != "nonemptyhole")
		{
			int dodai1 = suspects1[i].length();
		    int dodai2 = suspects2[i].length();
		    int dem = 0;
		    if(dodai1 == dodai2)
		    {
			    int middle = dodai1/2;
			    for(int j = 0; j < middle; j++)
			    {
				    if(suspects1[i][j] == suspects2[i][dodai2-1])
				    {
					    dem++;
				    }
				    dodai2--;
			    }
			    if(middle == dem)
			    {
					if(suspects1[i].length() != 0)
					{
						result = suspects1[i];
						break;
					}else if(suspects2[i].length() != 0)
					{
						result = suspects2[i];
						break;
					}else
					{
						continue;
					}

			    }
		    }
		}
	}
	cout << result.length() << " " << result[result.length()/2] << endl;
	delete[] tempfirst;
	delete[] templast;
	delete[] suspects1;
	delete[] suspects2;
	return 0;
}
