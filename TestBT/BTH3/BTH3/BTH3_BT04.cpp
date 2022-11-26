#include <iostream>
using namespace std;
int main4 ()
{
	int so1,so2;
	cout <<"nhap so nguyen thu nhat : ";
	cin >> so1;
	cout <<"nhap so nguyen thu hai : ";
	cin >> so2;
	if(so1 > so2)
		cout <<"so thu nhat lon hon so thu hai" << endl;
	else
		if(so1 < so2)
			cout <<"so thu nhat be hon so thu hai" << endl;
		else 
			cout <<"hai so bang nhau" << endl;
	system ("pause");
	return 0;

}