#include <iostream>
using namespace std;
int main5 ()
{
	double a,b,c;
	cout <<" nhap canh thu nhat  hinh tam giac : ";
	cin >> a;
	cout <<" nhap canh thu hai  hinh tam giac : ";
	cin >> b;
	cout <<" nhap canh thu ba cua hinh tam giac : ";
	cin >> c;
	double p = (a + b + c)/2;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	cout <<" dien tich tam giac : " << S << endl;
	system ("pause");
	return 0;
}