
#include <iostream>
using namespace std;
int main ()
{

	int c,dt,cv;


cout<<"Nhap canh hinh vuong: ";
cin>>c;
if (c<=0)
{
cout<<"Khong the duoc!!";
return 0;
}
if (c>0)
{
cv=4*c;
dt=c*c;
cout<<"Chu vi = "<<cv<<endl;
cout<<"Dien tich = "<<dt<<endl;
}
system("pause");
return 0;
}