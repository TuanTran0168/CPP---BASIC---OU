#include <iostream>
#include <string>
using namespace std;
void ham_NhapMotCongDan(CCCD &a);

struct CCCD
{
	int MaTinhThanh;
	int MaGioiTinh;
	int MaNamSinh;
	int SoNgauNhien;
};

int main()
{
	int n;
	CCCD *DS = new CCCD [n];

	CCCD a;
	ham_NhapMotCongDan(a);

	system("pause");
	return 0;
}

void ham_NhapMotCongDan(CCCD &a)
{
	cout << "\nNhap ma tinh thanh (3 chu so dau tien): ";
	cin >> a.MaTinhThanh;
	cout << "Nhap ma the ky va gioi tinh (1 chu so tiep theo): ";
	cin >> a.MaGioiTinh;
	cout << "Nhap ma nam sinh (2 chu so tiep theo): ";
	cin >> a.MaNamSinh;
	cout << "Nhap so ngau nhien (6 so cuoi cung): ";
	cin >> a.SoNgauNhien;
}