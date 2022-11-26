#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ofstream ghiFile;
	string Data, Adress;
	cout << "Nhap dia chi tap tin ban muon ghi: ";	//	D:\TXT\FileDeGhi.txt
	cin >> Adress;
	fflush(stdin);	//	Xóa bộ nhớ đệm đang lưu dấu endter
	ghiFile.open(Adress, ios::out);
	if(ghiFile.is_open())
	{
		cout << "\nMoi ban nhap du lieu vao File: " << Adress << endl;
		do
		{
			cout <<"=> ";
			getline(cin, Data);
			ghiFile << Data << endl;
			if(Data == "")
				break;

		}while(1);

		cout << "\nDa luu thanh cong vao File: " << Adress << endl;
	}
	else
	{
		cout << "Khong mo duoc tap tin";
	}

	cout << endl;
	system("pause");
	return 0;
}