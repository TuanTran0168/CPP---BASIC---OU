#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double cau1(double canh)
{
	return canh * canh;
}

double cau2(double chieuDai, double chieuRong)
{
	return chieuDai * chieuRong;
}

void cau3(string ten, int ngayLamViec, double tienCong)
{
	double tienLuong = ngayLamViec * tienCong;
	cout << ten << " tien luong la: " << tienLuong;
}

const double PI = 3.141593;

double cau4(double banKinh)
{
	return PI * banKinh * banKinh;
}

double cau5(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * sqrt(p - a) * sqrt(p - b) * sqrt(p - c));
}

int cau6(int n, bool check)
{
	int tong = 0;
	int soDaoNguoc = 0;
	int soDuocTach = 0;

	while (n > 0)
	{
		soDuocTach = n % 10;
		tong = tong + soDuocTach;
		n = n / 10;
		soDaoNguoc = soDaoNguoc * 10 + soDuocTach;
	}
	if (check)
		return tong;
	else
		return soDaoNguoc;
}

double cau9(int tongSoSach, double tongSoTien)
{
	double tienThueVaCaTienSach = tongSoTien * 0.075 + tongSoTien;
	double tienVanChuyen = tongSoSach * 2000;
	return tienThueVaCaTienSach + tienVanChuyen;
}

double cau10_a(char kyTu)
{
	return double (kyTu);
}

void cau11(double x)
{
	cout << sin(x) << endl;
	cout << cos(x) << endl;
	cout << tan(x);
}

int cau12(string chuoi)
{
	return chuoi.length();
}

int main ()
{
	
	cout << endl;
	system("pause");
	return 0;
}