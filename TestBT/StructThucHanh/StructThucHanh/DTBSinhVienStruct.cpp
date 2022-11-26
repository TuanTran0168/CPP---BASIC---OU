#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void ham_NhapSinhVien(struct SinhVien &a);
void ham_XuatSinhVien(struct SinhVien a);
double ham_TinhDiemTB(struct SinhVien a);
const int MAX = 45;

struct NTN		// NTN = Ngày Tháng Nãm
{
	int ngay, thang, nam;
};

struct SinhVien
{
	string mssv;
	string hoten;
	string diachi;
	NTN ngaysinh;
	double diemToan;
	double diemVan;
	double diemNgoaiNgu;
};

int main1()
{
	SinhVien a, b;

	cout << "\n\t\t\t============NHAP THONG TIN============\n\n";
	cout << "\tSINH VIEN a\n";
	ham_NhapSinhVien(a);
	cout << "\n\tSINH VIEN b\n";
	ham_NhapSinhVien(b);
	
	cout << "\n\t\t\t============XUAT THONG TIN============\n\n";
	cout << "\tSINH VIEN a\n";
	ham_XuatSinhVien(a);
	cout << "\nDiem trung binh la: " << ham_TinhDiemTB(a);
	cout << "\n\n\tSINH VIEN b\n";
	ham_XuatSinhVien(b);
	cout << "\nDiem trung binh la: " << ham_TinhDiemTB(b);

	cout << endl;
	system("pause");
	return 0;
}

void ham_NhapSinhVien(struct SinhVien &a)
{
	cout << "\nNhap ma so sinh vien: ";
	getline(cin, a.mssv);
	cout << "Nhap ho ten sinh vien: ";
	getline(cin, a.hoten);
	cout << "Nhap dia chi sinh vien: ";
	getline(cin, a.diachi);
	cout << "Nhap ngay sinh sinh vien: ";
	cin >> a.ngaysinh.ngay;
	cout << "Nhap thang sinh sinh vien: ";
	cin >> a.ngaysinh.thang;
	cout << "Nhap nam sinh sinh vien: ";
	cin >> a.ngaysinh.nam;
	cout << "Nhap diem mon Toan: ";
	cin >> a.diemToan;
	cout << "Nhap diem mon Van: ";
	cin >> a.diemVan;
	cout << "Nhap diem mon Ngoai Ngu: ";
	cin >> a.diemNgoaiNgu;
	fflush(stdin);
}

void ham_XuatSinhVien(struct SinhVien a)
{
	cout << "\nMa so sinh vien: " << a.mssv;
	cout << "\nHo ten sinh vien: " << a.hoten;
	cout << "\nDia chi sinh vien: " << a.diachi;
	cout << "\nNgay Thang Nam sinh sinh vien: " << a.ngaysinh.ngay << '/' << a.ngaysinh.thang << '/' << a.ngaysinh.nam;
	cout << "\nDiem mon Toan: " << a.diemToan;
	cout << "\nDiem mon Van: " << a.diemVan;
	cout << "\nDiem mon Ngoai Ngu: " << a.diemNgoaiNgu;
}

double ham_TinhDiemTB(struct SinhVien a)
{
	return ((a.diemToan + a.diemVan) * 2 + a.diemNgoaiNgu) / 5;
}
