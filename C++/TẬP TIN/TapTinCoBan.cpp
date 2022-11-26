#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream docFile;
	ofstream ghiFile;
	ghiFile.open("D:\\TXT\\BTVN.txt", ios::out); // Xoa xong ghi lai tu dau
	// ghiFile.open("D:\\TXT\\BTVN.txt", ios::in); // Chi doc
	// ghiFile.open("D:\\TXT\\BTVN.txt", ios::app); // Ghi tiep tuc neu tap tin da co du lieu

	int a, b, c;
	int KQ;
	cout << "Nhap 3 so nguyen: ";
	cin >> a;
	cin >> b;
	cin >> c;
	if(ghiFile.is_open())
	{
		ghiFile << a << '-' << b << '-' << c << endl;	// XUẤT, IN RA TẬP TIN THAY VÌ IN RA MÀN HÌNH CONSOLE
		ghiFile.close();
		cout <<"Ghi file thanh cong";
	}
	else
	{
		cout << "Khong mo duoc file";
	}

	// =========================================================== //

	docFile.open("D:\\TXT\\BTVN.txt");
	if(docFile.is_open())
	{
		docFile >> a;			// GHI TỪ FILE TẬP TIN BỎ VÀO BIẾN THAY VÌ NHẬP TỪ BÀN PHÍM  
		docFile.ignore(1);
		docFile >> b;
		docFile.ignore(1);
		docFile >> c;
		KQ = a * b * c;
		cout << "\nTich 3 so la: " << KQ;
		docFile.close();
	}
	else
	{
		cout << "Doc khong thanh cong";
	}

	cout << endl;
	system("pause");
	return 0;
}