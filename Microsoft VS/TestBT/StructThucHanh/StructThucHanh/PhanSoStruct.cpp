#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void ham_NhapPhanSo(struct PhanSo &x);
void ham_XuatPhanSo(struct PhanSo x);
double ham_CongPhanSo(struct PhanSo x, struct PhanSo y);
double ham_TruPhanSo(struct PhanSo x, struct PhanSo y);
double ham_NhanPhanSo(struct PhanSo x, struct PhanSo y);
double ham_ChiaPhanSo(struct PhanSo x, struct PhanSo y);

struct PhanSo
{
	double TuSo;
	double MauSo;
};

int main2()
{
	PhanSo a, b;
	ham_NhapPhanSo(a);
	ham_XuatPhanSo(a);

	ham_NhapPhanSo(b);
	ham_XuatPhanSo(b);

	cout << "\nPhep cong 2 phan so: " << ham_CongPhanSo(a, b);
	cout << "\nPhep tru 2 phan so: " << ham_TruPhanSo(a, b);
	cout << "\nPhep nhan 2 phan so: " << ham_NhanPhanSo(a, b);
	cout << "\nPhep chia 2 phan so: " << ham_ChiaPhanSo(a, b);

	cout << endl;
	system("pause");
	return 0;
}

void ham_NhapPhanSo(struct PhanSo &x)
{
	cout << "\nNhap tu so: ";
	cin >> x.TuSo;
	do
	{
		cout << "Nhap mau so: ";
		cin >> x.MauSo;
	}while(x.MauSo == 0);
}

void ham_XuatPhanSo(struct PhanSo x)
{
	cout << "Phan so cua ban: " << x.TuSo << "/" << x.MauSo << endl;
}

double ham_CongPhanSo(struct PhanSo x, struct PhanSo y)
{
	double a = (x.TuSo * y.MauSo) + (y.TuSo * x.MauSo);
	double b = x.MauSo * y.MauSo;
	return a/b;
}

double ham_TruPhanSo(struct PhanSo x, struct PhanSo y)
{
	double a = (x.TuSo * y.MauSo) - (y.TuSo * x.MauSo);
	double b = x.MauSo * y.MauSo;
	return a/b;
}

double ham_NhanPhanSo(struct PhanSo x, struct PhanSo y)
{
	double a = x.TuSo * y.TuSo;
	double b = x.MauSo * y.MauSo;
	return a/b;
}

double ham_ChiaPhanSo(struct PhanSo x, struct PhanSo y)
{
	double a = x.TuSo * y.MauSo;
	double b = x.MauSo * y.TuSo;
	return a/b;
}