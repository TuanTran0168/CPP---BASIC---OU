#include <iostream>
using namespace std;
int main ()
{
int so;
double i=1,t=0;
int a,b;
do
{
cout<<"nhap so tu 1 toi 6 : "<< endl;
cout<<"so 1 la phep cong"<<endl;
cout<<"so 2 la phep tru"<<endl;
cout<<"so 3 la phep nhan"<< endl;
cout<<"so 4 la phep chia"<< endl;
cout<<"so 5 la tinh tong 1+1/2+1/3+...1/n"<< endl;
cout<<"so 6 la ket thuc"<< endl;
cin>>so;
	
					switch(so)
					{
							case 1:
							{
								cout<<"phep cong " << endl;
								cout<<"nhap so thu nhat : ";
								cin>>a;
								cout<<"nhap so thu hai : ";
								cin>>b;
								cout <<"dap an : " << a+b << endl;
								break;
							}
							case 2:
							{
								cout<<"phep tru " << endl;
								cout<<"nhap so thu nhat : ";
								cin>>a;
								cout<<"nhap so thu hai : ";
								cin>>b;
								cout <<"dap an : " << a-b << endl;
								break;
							
							}
							case 3:
							{
								cout<<"phep nhan " << endl;
								cout<<"nhap so thu nhat : ";
								cin>>a;
								cout<<"nhap so thu hai : ";
								cin>>b;
								cout <<"dap an : " << a*b << endl;
								break;
							}
							case 4:
							{
							
								cout<<"phep chia " << endl;
								cout<<"nhap so thu nhat : ";
								cin>>a;
								cout<<"nhap so thu hai : ";
								cin>>b;
								if(b!=0)
									{
										cout <<"dap an : " << a*1.0/b << endl;
									}
								else
									cout<<"khong hop le";
								
								break;
							}
							case 5:
							{
								cout<<"tinh tong tu 1 toi so ban nhap la " << endl;
								cout<<"nhap so : ";
								cin>> so;
								while(so>0 && i<=so)
								{
								t = t  + (1/i);
								i++;
								}
								cout<<"tong cac so tu 1 toi so ban nhap la : " << t<< endl;
								break;
							}
					}
	}
	while(so!=6); 

	

}



