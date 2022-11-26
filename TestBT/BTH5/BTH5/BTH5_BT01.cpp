#include <iostream>
using namespace std;
int main ()
{
	int n;
	int t=0;
	cout<<"nhap n : ";
	cin>>n;
	for( int i=0 ; i<=n ; i++)
	{
		t = t + i;
	}
	cout<<"tong la : " <<t << endl;
	system("pause");
	return 0;
}
