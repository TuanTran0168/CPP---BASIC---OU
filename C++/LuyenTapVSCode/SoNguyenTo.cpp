#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n;
	int dem=0;
   
	cout<<"nhap so nguyen: ";
	cin>>n;
	if(n < 2)
	{
		cout<<"khong phai so nguyen to\n";
	}
   
	else //n>=2
	{
		for(int i = 2; i < n; i++)
		{
			if(n % i == 0)
			{
				dem++;
			}
		}
	}

	if(dem == 0)
	{
		cout<<"la so nguyen to\n";
	}
	else
	{
		cout<<"khong phai la so nguyen to\n";
	}
	system("pause");
	return 0;
}