#include <iostream>
using namespace std;
int main1 ()
{
	int n,t=0;
	cout<<"nhap so nguyen n : ";
	cin>>n;
	while(n>0)
	{
		t= t + n;
		n--;
	}
	cout<<"Tong so tu 1 toi n la : " << t << endl;
	system("pause");
	return 0;
}