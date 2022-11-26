#include <iostream>
#include <cmath>
using namespace std;
int main7 ()
{
	double x1,y1,x2,y2;
	cout <<" nhap toa do diem thu 1 : " << endl;
	cout << " nhap x1: ";
	cin >> x1;
	cout << " nhap y1: ";
	cin >> y1;
	cout << " nhap toa do diem thu 2 : " << endl;
	cout << " nhap x2: ";
	cin >> x2;
	cout << " nhap y2: ";
	cin >> y2;
	float a = (x2 - x1) * (x2 - x1);
	float b = (y2 - y1) *  (y2 - y1);
    cout << "a";
	cout << "b"; 
	float p = sqrt(a + b);
	cout << "khoang cach giua 2 diem la : " << p;
	system ("pause");
	return 0;
}