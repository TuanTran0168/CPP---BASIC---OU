#include <iostream>
using namespace std;
int main8 ()
{
	int thang,nam;
	cout <<"nhap thang : ";
	cin >> thang;
	cout <<"nhap nam : ";
	cin >> nam;
	if(thang>=13 || thang<=0)
	{
	   cout <<"khong hop le" << endl;
	   system("pause");
	  return 0; 
	}
    if(nam<=0)
    {
        cout <<"khong hop le" << endl;
		system("pause");
        return 0;
    }
	if(thang==2 && nam%400==0)	
		//thang 2 , nam nhuan 
		cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"29 ngay " << endl;
	if(thang==2 && nam%4!=0)
		//thang 2 nam khong nhuan
			cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"28 ngay " << endl;
				if(thang==2 && nam%4==0 && nam%400!=0)	
		cout <<"so ngay cua thang " << thang << " nam " << nam <<" la : " <<"29 ngay " << endl;
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
    system("pause");
	return 0; 
}