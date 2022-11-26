#include <iostream>
#include <math.h>
using namespace std;
int main13 ()
{
	int a,b,c;
	cout <<" nhap so thu nhat : ";
	cin >> a;
	cout <<" nhap so thu hai : ";
	cin >> b;
	cout <<" nhap so thu ba : ";
	cin >> c;
	float denta= b*b - 4*a*c;
	float x1= (-b + sqrt(denta))/2*a;
	float x2= (-b - sqrt(denta))/2*a;
	float xkep= -b/2*a;
	if(denta==0)
	{
		cout<<"phuong trinh co nghiem kep x= " << xkep<<endl;
		system("pause");
		return 0;
	}
	if(denta<0)
		cout <<"phuong trinh vo nghiem" << endl;
	else
	{
		cout<<" phuong trinh co nghiem x1 = " << x1<<endl;
	    cout<<" phuong trinh co nghiem x2 = " << x2<<endl;
	}
	 system("pause");
	return 0; 
}