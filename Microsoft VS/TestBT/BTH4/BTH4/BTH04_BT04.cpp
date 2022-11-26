#include <iostream>
using namespace std;
int main4 ()
{
	int so;
	cin>> so;
	int kq = 0;
	int t = 0;
	while(so>0)
	{
		t = t + so%10;
		kq++;
		so = so / 10;

	}
	cout <<"so chu so "<< kq<<endl;
	cout<<"tong "<< t <<endl;
	system("pause");
	return 0;
}