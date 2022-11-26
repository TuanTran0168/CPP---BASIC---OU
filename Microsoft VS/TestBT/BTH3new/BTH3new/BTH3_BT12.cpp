#include <iostream>
using namespace std;
int main ()
{
	float a,b;
	cout <<"nhap so thu nhat :";
	cin>>a;
	cout <<"nhap so thu hai :";
	cin>>b;
	float x= -b/a;
	if(a==0) 
	{
		if(b==0)
			cout<<"phuong trinh vo so nghiem" << endl;
		else 
			cout<<"phuong trinh vo nghiem" << endl;
	}	
	
	else 
			cout <<"nghiem cua phuong trinh bac nhat la : " << x << endl;
			
			
	 system("pause");
	return 0; 
}