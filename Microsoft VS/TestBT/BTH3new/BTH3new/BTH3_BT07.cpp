#include <iostream>
using namespace std;
int main7 ()
{
	int thang;
	cout <<"nhap thang : ";
	cin >> thang;
	if(thang==2)
		cout <<"thang " << thang <<" co 28 hoac 29 ngay " << endl;
	else
		//thang khac 2
	  if(thang%2==0 && thang<7)
		  cout <<"thang " << thang <<" co 30 ngay " << endl;
	  else
		  //thang bang 2
	  if(thang%2!=0 && thang>7)
		  cout <<"thang " << thang <<" co 30 ngay "<< endl;
	  else
		  //thang khac 2
		  cout <<"thang " << thang <<" co 31 ngay " << endl;
	system("pause");
	return 0;
}