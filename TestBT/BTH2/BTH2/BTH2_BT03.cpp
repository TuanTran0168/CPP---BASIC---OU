#include <iostream>
#include <string>
using namespace std;
int main3 ()
{
	string name;
	int a;
	double b;
	cout <<" nhap ten : " << endl;
	cin >> name;
	cout <<" nhap so ngay lam viec : " << endl;
	cin >> a;
	cout <<" tien cong mot ngay : " << endl;
	cin >> b;
	double p = a * b;
	cout <<" tien luong : " << p;
	system ("pause");
	return 0;

}