#include <iostream>
#include <math.h>
using namespace std;

// S1 = 1 + 2 + 3 + 4 + .... + n (n là số nguyên dương)
int Tong(int n)
{
    if (n == 1)
        return 1;
    else
        return n + Tong(n - 1);
}

// S2 = 1^2 + 2^2 + 3^2 + ... + n^2 (n là số nguyên dương)
int TongBinhPhuong(int n)
{
    if (n == 1)
        return 1;
    else
        return n * n + TongBinhPhuong(n - 1);
}

//S3 = 1 + 1/3 + 1/5 + ... + 1/n (n là số nguyên dương và là số lẻ)
double TongPhanSoMauLe(int n)
{
    if (n == 1)
        return 1;
    else
        return (1 * 1.0) / n + TongPhanSoMauLe(n - 2);
}

// S4 = 1! + 2! + 3! + ... + n!
int TongGiaiThua(int n)
{
    if (n == 1)
        return 1;
    else
    {
        int gt = 1;
        for (int i = 1; i <= n; i++)
        {
            gt = gt * i;
        }
        return gt + TongGiaiThua(n - 1);
    }
}

// Câu 2: Tính giai thừa
int GiaiThua(int n)
{
    if (n == 1)
        return 1;
    else
        return n * GiaiThua(n - 1);
}

// Câu 3: Tính dãy Fibonancci
int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fibonacci(n - 2) + Fibonacci(n - 1);
}

// Câu 4: Tính lũy thừa x^n
int LuyThua(int x, int n)
{
    if (n == 1)
        return x;
    else
        return x * LuyThua(x, n - 1);
}

int DemSoChuSo(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + DemSoChuSo(n / 10);
    /* DemChuSo(3260) = 4
		return 1 + DemChuSo(326) = 1 + 3 = 4
					return 1 + DemChuSo(32) = 1 + 2 = 3
								return 1 + DemChuSo(3) = 1 + 1 = 2
											return 1;	= 1			*/
}

int DaoNguocSo(int n)
{
    if (n < 10)
        return n;
    else
    {
        int sl = 0;
        int x = n % 10; // Tách số cuối để nhân tương ứng
        int n1 = n;
        while (n1 != 0) // Đếm số lượng chữ số
        {
            n1 /= 10;
            sl++;
        }
        for (int i = 0; i < sl - 1; i++) // Nhân tương ứng với hàng trăm, hàng chục, hàng đơn vị
        {
            x = x * 10;
        }

        return x + DaoNguocSo(n / 10); //  MÌNH ĐỈNH VÃI ĐÁI :))
    }
}

int main()
{
    int n = 5;
    int a = 34500678;
    cout << "Cau 1: ";
    cout << "\nS1 = " << Tong(n);
    cout << "\nS2 = " << TongBinhPhuong(n);
    cout << "\nS3 = " << TongPhanSoMauLe(n);
    cout << "\nS4 = " << TongGiaiThua(n);

    cout << "\n\nCau 2: ham tinh giai thua bang de quy: " << GiaiThua(n);
    cout << "\nCau 3: ham tinh Fibonacci bang de quy: " << Fibonacci(n);
    cout << "\nCau 4: ham tinh luy thua bang de quy: " << LuyThua(3, 3);
    cout << "\nCau 5: ham dem so chu so bang de quy: " << DemSoChuSo(19009009);
    cout << "\nCau 6: ham dao nguoc so bang de quy: " << DaoNguocSo(a);

    cout << endl;
    system("pause");
    return 0;
}