#include <iostream>
using namespace std;
int main6 () 
{
	int nam;
	cout <<"nhap nam : ";
	cin >> nam;
	if(nam%4==0) 
		// nam chia het cho 400
		cout <<"nam " << nam <<" la nam nhuan " << endl;
		else 
			//nam khong chia het cho 400 
			cout <<"nam " << nam <<" la nam khong nhuan " << endl;
	if(nam%400==0)
		cout <<"nam " << nam <<" la nam nhuan "<< endl;
	system ("pause");
	return 0;
} 