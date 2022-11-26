#include <iostream>
using namespace std;
int main5 ()
{
	int n;
	int soDaoNguoc = 0;
	cin>>n;
	while(n>0)
	{
		soDaoNguoc = soDaoNguoc * 10 + n%10;
		n = n / 10;
		
	}
	cout<<soDaoNguoc;
	system("pause");
	return 0;
}