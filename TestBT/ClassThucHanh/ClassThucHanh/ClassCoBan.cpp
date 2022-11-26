#include <iostream>
#include <string>
using namespace std;

class Diem
{
public:
	double x, y;
	Diem()
	{
		x = 0;
		y = 0;
	}

	Diem(double a, double b)
	{
		x = a;
		y = b;
	}

	~Diem()
	{}

	void InThongTin()
	{
		cout << "\nDiem co toa do la: (" << x << ")(" << y << ")\n";
	}
};

class HinhChuNhat
{
private:
	int ChieuDai;
	int ChieuRong;
public:

	HinhChuNhat()
	{};

	HinhChuNhat(int ChieuDai, int ChieuRong)
	{
		int x = ChieuDai;
		int y = ChieuRong;
	}
	~HinhChuNhat()
	{
		cout << "\nHello\n";
	}

	void XuatThongTin(int x, int y)
	{
		cout << "\nChieu dai: " << x;
		cout << "\nChieu rong: " << y;
	}

	int DienTich(int x, int y)
	{
		return x * y;
	}

	int ChuVi(int x, int y)
	{
		return (x + y) * 2;
	}

};

class DaThucBac2
{
private:
    double a, b, c;

public:
    DaThucBac2() { a = b = c = 0; }

    DaThucBac2(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
    }
    
    double GiaTriDaThuc(double x)
    {
        return a * x * x + b * x + c;
    }

    void NhanDaThuc(double k)
    {
        a = a * k;
        b = b * k, c = c * k;
    }
    void CongDaThuc(DaThucBac2 p)
    {
        a = a + p.a;
        b = b + p.b;
        c = c + p.c;
    }
    void DaoHam(DaThucBac2 &p)
    {
        p.a = 0;
        p.b = 2 * a;
        p.c = b;
    }
    void InThongTin()
    {
        cout << a << "*x*x + " << b << "*x + " << c << endl;
    }
};

int main()
{
	HinhChuNhat hcn;
	int x = 5, y = 6;
	hcn.XuatThongTin(x, y);
	cout << "\nDien tich: " << hcn.DienTich(x, y);
	cout << "\nChu vi: " << hcn.ChuVi(x, y);
	//hcn.~HinhChuNhat();

	system("pause");
	return 0;
}