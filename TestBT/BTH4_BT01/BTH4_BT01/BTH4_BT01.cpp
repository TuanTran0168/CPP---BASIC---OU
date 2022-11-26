#include <iostream> 
using namespace std;
int main()
{
	int n,t;
	cout<<"nhap n : ";
	cin>> n; 
	t = 0;
	while(n>0)
	{
		t = t + n;
		n--;
	}
			cout<<"tong cua cac so tu 1 toi n la : " << t << endl; 
	 system("pause");
	 return 0; 
}  