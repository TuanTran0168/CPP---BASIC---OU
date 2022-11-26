#include <iostream>
using namespace std;
int main ()
{
	int thang,nam;
	cout <<"nhap thang : ";
	cin >> thang;
	cout <<"nhap nam : ";
	cin >> nam;
	if(thang==2 && nam%400==0)
    
	
		//thang 2 , nam nhuan
    
		cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"29 ngay " << endl;
	if(thang==2 && nam%400!=0)
    
		//thang 2 nam khong nhuan
    
			cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"28 ngay " << endl;
    
    else
    
    if(thang!= 2 && thang <7 && thang%2==0)
    cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"30 ngay " << endl;
    if(thang!=2 && thang<7 && thang%2!=0)
    
    cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"31 ngay " << endl;
    if(thang!=2 && thang > 7 && thang%2!=0)
    cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"30 ngay " << endl;
    else 
    if(thang!=2 && thang >=7)
    cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"31 ngay " << endl;


	return 0;
}