#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void ham_NhapSinhVien(struct SinhVien &a);
void ham_XuatSinhVien(struct SinhVien a);
const int MAX = 45;

struct NTN // NTN = Ngày Tháng Năm
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

int main()
{
	SinhVien a, b;
	SinhVien DS[MAX + 1];

	cout << "\n\t\t\t============NHAP THONG TIN============\n\n";
	cout << "Sinh vien a\n";
	ham_NhapSinhVien(a);
	cout << "\nSinh vien b\n";
	ham_NhapSinhVien(b);

	cout << "\n\t\t\t============XUAT THONG TIN============\n\n";
	cout << "Sinh vien a\n";
	ham_XuatSinhVien(a);
	cout << "\n\nSinh vien b\n";
	ham_XuatSinhVien(b);

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

int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = NULL;
		if (p != NULL)
			while (p->link != NULL)
			{
				q = p;
				p = p->link;
			}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
