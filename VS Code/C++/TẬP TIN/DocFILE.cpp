#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	ifstream FILE;
	string Adress = " ";
	cout << "\t\t==== THUC HANH TAP TIN ====\n";
	cout << "\nNhap dia chi tap tin: ";
	cin >> Adress;
	FILE.open(Adress, ios::in);			// D:\\TXT\\MoHo.txt	D:\\TXT\\NhuNhungPhutBanDau.txt		D:\TXT\VL.txt
	string Data = " ";
	if(FILE.is_open())
	{
		cout << "Doc thanh cong ^_^\n\n";
		while(!FILE.eof())
		{
			getline(FILE, Data);
			cout << Data << endl;
			//Sleep(300);  // ngung lai 0.3 giay
		}
		FILE.close();
	}
	else
	{
		cout << "Khong tim duoc tap tin";
	}

	cout << endl;
	system("pause");
	return 0;
}