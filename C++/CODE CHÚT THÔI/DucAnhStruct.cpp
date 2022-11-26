#include <iostream>
using namespace std;

/*========== XÂY DỰNG CẤU TRÚC PHÂN SỐ ==========*/
void ham_NhapMotPhanSo(struct PhanSo &x);
double ham_CongPhanSo(struct PhanSo x, struct PhanSo y);
double ham_TruPhanSo(struct PhanSo x, struct PhanSo y);
double ham_NhanPhanSo(struct PhanSo x, struct PhanSo y);
double ham_ChiaPhanSo(struct PhanSo x, struct PhanSo y);
double ham_UCLN(double a, double b);
struct PhanSo ham_RutGonPhanSo(struct PhanSo x);
void ham_XuatPhanSoRutGon(struct PhanSo x);
void ham_CapPhatMangPhanSo(struct PhanSo *&P, int &n);
void ham_XuatMangPhanSo(struct PhanSo *P, int n);
void ham_RutGonMangPhanSo(struct PhanSo *P, int n);
double ham_TimMaxMin(struct PhanSo *P, int n, bool o);
void ham_SapXep(struct PhanSo *P, int n, bool o);

/*========== XÂY DỰNG CẤU TRÚC SỐ PHỨC ==========*/
void ham_NhapMotSoPhuc(struct SoPhuc &C);
void ham_CongSoPhuc(struct SoPhuc x, struct SoPhuc y);
void ham_TruSoPhuc(struct SoPhuc x, struct SoPhuc y);
void ham_NhanSoPhuc(struct SoPhuc x, struct SoPhuc y);

struct PhanSo
{
	double TuSo;
	double MauSo;
};

struct SoPhuc
{
	double PhanThuc;
	double PhanAo;
};

int main()
{
	/*PhanSo *P;
	int n;
	ham_CapPhatMangPhanSo(P, n);
	ham_XuatMangPhanSo(P, n);
	ham_RutGonMangPhanSo(P, n);
	cout << "\nMax la: " << ham_TimMaxMin(P, n, 1);
	cout << "\nMin la: " << ham_TimMaxMin(P, n, 0);
	ham_SapXep(P, n, 1);
	ham_XuatMangPhanSo(P, n);
	ham_SapXep(P, n, 0);
	ham_XuatMangPhanSo(P, n);*/

	/*=====================================================================*/

	SoPhuc x, y;
	ham_NhapMotSoPhuc(x);
	ham_NhapMotSoPhuc(y);
	ham_CongSoPhuc(x, y);
	ham_TruSoPhuc(x, y);
	ham_NhanSoPhuc(x, y);

	//delete[] P;
	system("pause");
	return 0;
}
/*============================== XÂY DỰNG CẤU TRÚC PHÂN SỐ ==============================*/

void ham_NhapMotPhanSo(struct PhanSo &x)
{
	cout << "\nNhap tu so: ";
	cin >> x.TuSo;
	while (1)
	{
		cout << "Nhap mau so: ";
		cin >> x.MauSo;

		if (x.MauSo != 0)
			break;
	}
}

double ham_CongPhanSo(struct PhanSo x, struct PhanSo y)
{
	return (x.TuSo * y.MauSo + y.TuSo * x.MauSo) / (x.MauSo * y.MauSo);
}

double ham_TruPhanSo(struct PhanSo x, struct PhanSo y)
{
	return (x.TuSo * y.MauSo - y.TuSo * x.MauSo) / (x.MauSo * y.MauSo);
}

double ham_NhanPhanSo(struct PhanSo x, struct PhanSo y)
{
	return (x.TuSo * y.TuSo) / (x.MauSo * y.MauSo);
}

double ham_ChiaPhanSo(struct PhanSo x, struct PhanSo y)
{
	return (x.TuSo * y.MauSo) / (x.MauSo * y.TuSo);
}

double ham_UCLN(double a, double b)
{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}

	return a;
}

struct PhanSo ham_RutGonPhanSo(struct PhanSo x)
{
	PhanSo KQ;
	KQ.TuSo = x.TuSo / ham_UCLN(x.TuSo, x.MauSo);
	KQ.MauSo = x.MauSo / ham_UCLN(x.TuSo, x.MauSo);

	return KQ;
}

void ham_XuatPhanSoRutGon(struct PhanSo x) // Cái này chỉ xuất chứ không rút gọn trong mảng
{
	cout << (x.TuSo / ham_UCLN(x.TuSo, x.MauSo)) << "/" << (x.MauSo / ham_UCLN(x.TuSo, x.MauSo));
}

void ham_CapPhatMangPhanSo(struct PhanSo *&P, int &n)
{
	cout << "Nhap so luong phan so: ";
	cin >> n;

	P = new PhanSo[n];

	for (int i = 0; i < n; i++)
	{
		cout << "\n\tNhap phan so thu (" << i << ")";
		ham_NhapMotPhanSo(P[i]);
	}
}

void ham_XuatMangPhanSo(struct PhanSo *P, int n)
{
	cout << "\n\tMang phan so cua ban\n";

	for (int i = 0; i < n; i++)
	{
		cout << P[i].TuSo << '/' << P[i].MauSo << "\t";
	}
}

void ham_RutGonMangPhanSo(struct PhanSo *P, int n)
{
	cout << "\n\tMang phan so da duoc rut gon\n";
	for (int i = 0; i < n; i++)
	{
		cout << ham_RutGonPhanSo(P[i]).TuSo << "/" << ham_RutGonPhanSo(P[i]).MauSo << "\t";
	}
}

double ham_TimMaxMin(struct PhanSo *P, int n, bool o)
{
	PhanSo temp;
	temp.TuSo = P[0].TuSo;
	temp.MauSo = P[0].MauSo;

	if (o == true) //MAX
	{
		for (int i = 1; i < n; i++)
		{
			if ((P[i].TuSo / P[i].MauSo) > (temp.TuSo / temp.MauSo))
			{
				temp.TuSo = P[i].TuSo;
				temp.MauSo = P[i].MauSo;
			}
		}
	}
	else if (o == false) //MIN
	{
		for (int i = 1; i < n; i++)
		{
			if ((P[i].TuSo / P[i].MauSo) < (temp.TuSo / temp.MauSo))
			{
				temp.TuSo = P[i].TuSo;
				temp.MauSo = P[i].MauSo;
			}
		}
	}

	return temp.TuSo / temp.MauSo;
}

void ham_SapXep(struct PhanSo *P, int n, bool o)
{
	if (o == true) // Tăng dần
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((P[i].TuSo / P[i].MauSo) > (P[j].TuSo / P[j].MauSo))
				{
					PhanSo temp = P[i];
					P[i] = P[j];
					P[j] = temp;
				}
			}
		}
	}
	else if (o == false) // Giảm dần
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((P[i].TuSo / P[i].MauSo) < (P[j].TuSo / P[j].MauSo))
				{
					PhanSo temp = P[i];
					P[i] = P[j];
					P[j] = temp;
				}
			}
		}
	}
}

/*============================== XÂY DỰNG CẤU TRÚC SỐ PHỨC ==============================*/

void ham_NhapMotSoPhuc(struct SoPhuc &C)
{
	cout << "\nNhap phan thuc: ";
	cin >> C.PhanThuc;
	cout << "Nhap phan ao: ";
	cin >> C.PhanAo;
}

void ham_CongSoPhuc(struct SoPhuc x, struct SoPhuc y)
{
	cout << "Dap an phep cong 2 so phuc: (" << x.PhanThuc + y.PhanThuc << ") + " << "(" << x.PhanAo + y.PhanAo << ")i" << endl;
}

void ham_TruSoPhuc(struct SoPhuc x, struct SoPhuc y)
{
	cout << "Dap an phep tru 2 so phuc: (" << x.PhanThuc - y.PhanThuc << ") + " << "(" << x.PhanAo - y.PhanAo << ")i" << endl;
}

void ham_NhanSoPhuc(struct SoPhuc x, struct SoPhuc y)
{
	cout << "Dap an phep nhan 2 so phuc: (" << (x.PhanThuc * y.PhanThuc) - (x.PhanAo * y.PhanAo) << ") + " << "(" << (x.PhanThuc * y.PhanAo) + (x.PhanAo * y.PhanThuc) << ")i" << endl;
}

