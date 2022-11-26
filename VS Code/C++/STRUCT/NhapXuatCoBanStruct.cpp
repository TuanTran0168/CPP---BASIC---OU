#include <iostream>
#include <string>
using namespace std;

void ham_NhapThongTinSinhVien(struct SinhVien &a);
void ham_XuatThongTinSinhVien(struct SinhVien a);

struct SinhVien
	{
		string name;
		string mssv;
		double diem;
	};

int main()
{
	SinhVien a, b, c;
	cout << "\n\t\t\t============NHAP THONG TIN============\n\n";
	cout << "Sinh vien a\n";
	ham_NhapThongTinSinhVien(a);
	cout << "Sinh vien b\n";
	ham_NhapThongTinSinhVien(b);
	cout << "Sinh vien c\n";
	ham_NhapThongTinSinhVien(c);

	cout << "\n\t\t\t============XUAT THONG TIN============\n\n";
	cout << "Sinh vien a\n";
	ham_XuatThongTinSinhVien(a);
	cout << "Sinh vien b\n";
	ham_XuatThongTinSinhVien(b);
	cout << "Sinh vien c\n";
	ham_XuatThongTinSinhVien(c);

	cout << endl;
	system("pause");
	return 0;
}
void ham_NhapThongTinSinhVien(struct SinhVien &a)
{
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, a.name);
	cout << "Nhap ma so sinh vien: ";
	getline(cin, a.mssv);
	cout << "Nhap diem sinh vien: ";
	cin >> a.diem;
	fflush(stdin);		// Xóa đi dấu enter trong bộ đệm để không bị lỗi chuỗi tiếp theo
	cout << endl;
}

void ham_XuatThongTinSinhVien(struct SinhVien a)
{
	cout << "Ho ten sinh vien: " << a.name << endl;
	cout << "Ma so sinh vien: " << a.mssv << endl;
	cout << "Diem sinh vien: " << a.diem << endl;
	cout << endl;
}