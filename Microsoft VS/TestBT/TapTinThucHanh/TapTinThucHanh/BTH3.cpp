#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	ifstream docFILE;
	ofstream ghiFILE;
	ghiFILE.open("D:\\TXT\\BTH3.txt", ios::app);
	int a, b, c;
	cout << "Nhap 3 so: ";
	cin >> a;
	cin >> b;
	cin >> c;

	if(ghiFILE.is_open())
	{
		ghiFILE << a << '#' << b << '#' << c << endl;	//Xuat gia tri vao tap tin FILE 
		ghiFILE.close();
		cout << "Ghi FILE thanh cong";
	}
	else
	{
		cout << "\nKhong mo duoc FILE";
	}

	cout << "\n--------------------------------------------\n";

	docFILE.open("D:\\TXT\\BTH3.txt", ios::in);
	if(docFILE.is_open())
	{
		cout << "\nDoc FILE thanh cong";
		while(!docFILE.eof())
		{
			while(!docFILE.eof()) //Doc tap tin vua nhap neu khong co chi doc duoc tap tin dau tien
			{
				docFILE >> a;						//Doc gia tri tu tap tin FILE
				docFILE.ignore(1);
				docFILE >> b;
				docFILE.ignore(1);
				docFILE >> c;
			}
			cout << "\nTrung binh cong 3 so la: " << (a + b + c) * 1.0 / 3;
			docFILE.close();
		}
	}
	else
	{
		cout <<"\nKhong mo duoc FILE";
	}

	system("pause");
	return 0;
}