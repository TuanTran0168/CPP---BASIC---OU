#include <iostream>
using namespace std;
int main ()
{
	int a, s=0, t=0;
	cout <<"nhap vao so co ba chu so : ";
	cin >> a;
	s = (a%10)*100 + ((a/10)%10)*10 + a/100;
	t = a/100 + a%10 +(a/10)%10;
	cout << " tong ba chu so la : " << t << endl;
	cout << " so dao nguoc la : " << s << endl;
	system ("pause");
	return 0;

}