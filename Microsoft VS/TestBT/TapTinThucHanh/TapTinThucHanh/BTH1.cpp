#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main1()
{
	ofstream FILE;		// FILE de ghi outfile
	FILE.open("D:\\TXT\\TEST.txt", ios::app);	// ios::app ghi tiep len file khong xoa
	int a, b;
	cout << "Nhap 2 so: ";
	cin >> a;
	cin >> b;
	cout << "Ket qua la: " << a + b;
	if(FILE.is_open())
	{
		FILE << "Ket qua la: " << a + b << endl;
		FILE.close();
		cout << "\nGhi du lieu thanh cong";
	}
	else
	{
		cout << "\nGhi Khong Thanh Cong";
	}

	cout << endl;
	system("pause");
	return 0;
}