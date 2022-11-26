#include <iostream>
using namespace std;

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
    system("pause");
    return 0;
}