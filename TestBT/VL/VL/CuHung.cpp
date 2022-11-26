#include <iostream>
using namespace std;
int soLuongChuSoChan (int n);
int main1()
{
	int n = 352642;
	cout << soLuongChuSoChan(n) << endl;
	system("pause");
	return 0;
}

int soLuongChuSoChan (int n)
{
	if (n < 10)
	{
		if (n % 2 == 0)
			return 1;
		else
			return 0;
	}
	else 
	{
		int x = n % 10;
		if (x % 2 == 0)
			return 1 + soLuongChuSoChan(n / 10);
		else 
			return soLuongChuSoChan(n / 10);
	}
}