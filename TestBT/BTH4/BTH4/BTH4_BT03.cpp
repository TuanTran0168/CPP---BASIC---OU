#include <iostream>
using namespace std;
int main3 ()
{
	int n;
	int i1=2,i2=1;
	long chan=1, le=1;
	cout<<"nhap n : ";
	cin>>n;
	if(n>1)
	{
		while(i1 <= n)
		{
			chan = chan * i1;
			i1 = i1 + 2;
		}
			cout<<"tich cac so chan tu 1 toi " << n <<" la : " << chan << endl;

		while(i2 <= n)
		{
			le = le * i2;
			i2 = i2 + 2;
		}
			cout<<"tich cac so chan tu 1 toi " << n <<" la : " << le << endl;
	}
	else
		cout<<" khong hop le " << endl;

		system("pause");
	return 0;
}