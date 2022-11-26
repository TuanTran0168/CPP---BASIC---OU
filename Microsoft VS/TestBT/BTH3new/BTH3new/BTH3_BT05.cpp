#include <iostream>
using namespace std;
int main5 ()
{
	float a;
	cout <<" nhap diem tich luy cua sinh vien : ";
	cin >> a;
	if(a >= 9)
		cout <<"xep loai xuat sac " << endl;
	else 
	if(a >= 8)
		cout <<"xep loai gioi " << endl;
	else
	if(a>=7)
		cout <<"xep loai kha" << endl;
	else
	if(a>=6)
		cout <<"xep loai trung binh kha" << endl;
	else
	if(a>=5)
		cout <<"xep loai trung binh" << endl;
	else
		cout <<" xep loai yeu" << endl;
	system ("pause");
	return 0;
}

