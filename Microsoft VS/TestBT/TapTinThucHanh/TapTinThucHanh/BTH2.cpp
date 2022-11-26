#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main1()
{
	ifstream FILE;		//FILE de doc	infile
	FILE.open("D:\\TXT\\TEST.txt", ios::in);
	string Data = " ";
	if(FILE.is_open())
	{
		while(!FILE.eof())
		{
			getline(FILE, Data);
			cout  << Data << endl;
		}
		cout << "\nDoc thanh cong du lieu";
		FILE.close();
	}
	else
	{
		cout << "\nKhong mo duoc file";
	}

	cout << endl;
	system("pause");
	return 0;
}