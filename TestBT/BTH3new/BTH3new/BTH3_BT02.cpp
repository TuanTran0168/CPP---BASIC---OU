#include <iostream>
using namespace std;
int main2 ()
{
	double a,b,max;
	cout <<"nhap so thu nhat : ";
	cin >> a;
	cout <<"nhap so thu hai : ";
	cin >> b;
	if(a >= b)
		max = a;
	else 
	    max = b;
	cout <<"so lon nhat la : " << max << endl;
	system ("pause");
	return 0;
}