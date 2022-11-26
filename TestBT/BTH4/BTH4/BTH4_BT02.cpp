#include <iostream>
using namespace std;
int main2 ()
{
	int n;
	int i=1, tich=1;
	cout<<"nhap n : ";
	cin>>n;
	if(n>=1)
	{
		while(i<=n)
		{
			tich = tich * i;
			i=i+2;
		}
		cout<<"tich cua cac so le tu 1 toi "<< n  <<" la : "<<  tich  <<endl;
	}
	
	system("pause");
	return 0;
}