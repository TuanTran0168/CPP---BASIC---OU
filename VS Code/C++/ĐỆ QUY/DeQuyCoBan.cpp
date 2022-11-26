#include <iostream>
#include <cmath>
const double pi = 3.1415;
using namespace std;
int ham_Tong(int n);
int ham_TongBinhPhuong(int n);
double ham_TongPhanSoMauLe(int n);
int ham_TongGiaiThua(int n);
int ham_GiaiThua(int n);
int ham_Fibonacci(int n);
int ham_LuyThua(int x, int n);
int ham_DemSoChuSo(int n);
int ham_DaoNguocSo(int n);
int ham_TongCacChuSoChan(int n);
int ham_TongCacChuSoLe(int n);
long long ham_ThapPhanSangNhiPhan(int n);
int ham_USCLN(int a, int b);
int ham_KySoLonNhat(int n);
int ham_DemSoLeTrongMotSoNguyen(int n);
int ham_DemSoLeTuMotToiN(int n);
double ham_TongPhanSo(int n);
int ham_CapSoCong(int n, int a, int d);
int ham_CapSoNhan(int n, int a, int q);
long long ham_NhiPhanSangThapPhan(long long n, double a);
double ham_DienTichHinhVuongHinhTronLongNhau(int n, double a);
int ham_TinhTongMang(int a[], int n);
double ham_TimSoLonNhatTrongMang(int a[], int n);
int ham_SoNgayLayCovid(int Q, int N, int M);

int main()
{
    system("cls");
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {9, 6, 5, 3, 4};
    int n = 4;
    int a = 2;
    int R = 3;
    /*cout << "\nCau 1: " << ham_Tong(5);
    cout << "\nCau 2: " << ham_GiaiThua(5);
    cout << "\nCau 3: " << ham_Fibonacci(5);
    cout << "\nCau 4: " << ham_USCLN(125, 20);
    cout << "\nCau 5: " << ham_DemSoChuSo(1230456);
    cout << "\nCau 6: " << ham_KySoLonNhat(813456963);
    cout << "\nCau 7: " << ham_DemSoLeTrongMotSoNguyen(123456789);
    cout << "\nCau 8: " << ham_DemSoLeTuMotToiN(20);
    cout << "\nCau 9: " << ham_TongPhanSo(5);
    cout << "\nCau 10: " << ham_CapSoCong(3, 10, 3);
    cout << "\ncau 11: " << ham_CapSoNhan(5, 2, 3);*/
    cout << ham_NhiPhanSangThapPhan(10011, 0);
    //cout << ham_ThapPhanSangNhiPhan(19);

    //cout << ham_DienTichHinhVuongHinhTronLongNhau(n, a);
    // cout << "\nTong mang: " << ham_TinhTongMang(b, sizeof(b) / sizeof(b[0]) - 1);
    // cout << "\nSo lon nhat trong mang: " << ham_TimSoLonNhatTrongMang(c, sizeof(c) / sizeof(c[0]));
    // cout << "\nSo ngay: " << ham_SoNgayLayCovid(1, 1, 8);

    cout << endl;
    system("pause");
    return 0;
}

// S1 = 1 + 2 + 3 + 4 + .... + n (n là số nguyên dương)
int ham_Tong(int n)
{
    if (n == 1)
        return 1;
    else
        return n + ham_Tong(n - 1);
}

// S2 = 1^2 + 2^2 + 3^2 + ... + n^2 (n là số nguyên dương)
int ham_TongBinhPhuong(int n)
{
    if (n == 1)
        return 1;
    else
        return n * n + ham_TongBinhPhuong(n - 1);
}

//S3 = 1 + 1/3 + 1/5 + ... + 1/n (n là số nguyên dương và là số lẻ)
double ham_TongPhanSoMauLe(int n)
{
    if (n == 1)
        return 1;
    else
        return (1 * 1.0) / n + ham_TongPhanSoMauLe(n - 2);
}

// S4 = 1! + 2! + 3! + ... + n!
int ham_TongGiaiThua(int n)
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
        return gt + ham_TongGiaiThua(n - 1);
    }
}

// Câu 2: Tính giai thừa
int ham_GiaiThua(int n)
{
    if (n == 1)
        return 1;
    else
        return n * ham_GiaiThua(n - 1);
}

// Câu 3: Tính dãy Fibonancci
int ham_Fibonacci(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return ham_Fibonacci(n - 2) + ham_Fibonacci(n - 1);
}

// Câu 4: Tính lũy thừa x^n
int ham_LuyThua(int x, int n)
{
    if (n == 1)
        return x;
    else
        return x * ham_LuyThua(x, n - 1);
}

// Câu 5: Đếm số chữ số của một số nguyên không âm
int ham_DemSoChuSo(int n)
{
    if (n < 10)
        return 1;
    else
        return 1 + ham_DemSoChuSo(n / 10);
    /* ham_DemChuSo(3260) = 4
        return 1 + ham_DemChuSo(326) = 1 + 3 = 4
                    return 1 + ham_DemChuSo(32) = 1 + 2 = 3
                                 return 1 + ham_DemChuSo(3) = 1 + 1 = 2
                                            return 1;  = 1      */
}

// Câu 6: Đảo ngược 1 số nguyên không âm
int ham_DaoNguocSo(int n)
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
            x *= 10;
        }
        return x + ham_DaoNguocSo(n / 10);
        /*
               ham_DaoNguocSo(3293)
                return 3000 +  ham_DaoNguocSo(329)
                                return 900 +  ham_DaoNguocSo(29)
                                                return 20 + ham_DaoNguocSo(2)
                                                             return  3    
        */
    }
}

//Câu 7: Tính tổng các chữ số chẵn / lẻ của một số nguyên không âm
int ham_TongCacChuSoChan(int n)
{
    if (n < 10)
    {
        if (n % 2 == 0)
            return n;
        else
            return 0;
    }
    else
    {
        int x = (n % 10);
        if (x % 2 == 0)
            return x + ham_TongCacChuSoChan(n / 10); // Số chẵn thì cộng vào
        else
            return ham_TongCacChuSoChan(n / 10); // Số lẻ bỏ qua
    }
}

int ham_TongCacChuSoLe(int n)
{
    if (n < 10)
    {
        if (n % 2 != 0)
            return n;
        else
            return 0;
    }
    else
    {
        int x = n % 10;
        if (x % 2 != 0)
            return x + ham_TongCacChuSoLe(n / 10); // Số lẻ thì cộng vào
        else
            return ham_TongCacChuSoLe(n / 10); // Số chẵn bỏ qua
    }
}

//Câu 8: hàm chuyển số thập phân sang nhị phân
long long ham_ThapPhanSangNhiPhan(int n)
{
    if (n == 0) // Chia lần cuối = 0 thì trả về số dư
        return n % 2;
    else
        return (n % 2) + ham_ThapPhanSangNhiPhan(n / 2) * 10;
    /*

    ThapPhanSangNhiPhan(10)
      return 0 + ThapPhanSangNhiPhan(5) * 10  = 1010
                    return 1 + ThapPhanSangNhiPhan(2) * 10  = 101
                                return 0 + ThapPhanSangNhiPhan(1) * 10  = 10
                                             return 1;

      1010 = 1 * 1000 + 0 * 100 + 1 * 10 + 0
      n = 10 (hệ 10) = 1010 (hệ 2)
      10 / 2 = 5 dư 0	n = 5
      5 / 2 = 2  dư 1	n = 2
      2 / 2 = 1  dư 0	n = 1
      1 / 2 = 0  dư 1	n = 0 (điều kiện dừng (n = 0) và trả về số dư)
      ==> 1010 ( hệ 2)
  */
}

//Câu 9: Chuyển từ nhị phân sang thập phân
long long ham_NhiPhanSangThapPhan(long long n, double a)
{
    if (n == 0)
        return 0;
    else
    {
        return (n % 10) * pow(double(2), double(a)) + ham_NhiPhanSangThapPhan(n / 10, a + 1);
    }
    /*
	NhiPhanSangThapPhan(10111)
	  return 1 * 2^0 + NhiPhanSangThapPhan(1011)
						return 1 + 2^1 + NhiPhanSangThapPhan(101)
											return 1 * 2^2 + NhiPhanSangThapPhan(10)
																return 0 * 2^3 + NhiPhanSangThapPhan(1)
																					return 1 * 2^4 + NhiPhanSangThapPhan(0)
																										return 0;
	10111 = 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 1 * 2^1 + 1 * 2^0 = 23
	10111 (hệ 2) = 23 (hệ 10)
	10111 / 10 = 1011 dư 1	n = 1011	a = 0
	1011  / 10 = 101  dư 1	n = 101		a = 1
	101   / 10 = 10   dư 1	n = 10		a = 2
	10    / 10 = 1    dư 0  n = 1		a = 3
	1     / 10 = 0    dư 1	n = 0		a = 4 (điều kiện dừng (n = 0) và trả về số 0)
	
	*/
}

// Câu 10: Tính tổng giá trị trong mảng 1 chiều có n phần tử
int ham_TinhTongMang(int a[], int n)
{
    if (n == 0)
        return a[n];
    else
        return a[n] + ham_TinhTongMang(a, n - 1);
}

//Câu 11: Tìm số lớn nhất trong mảng
double ham_TimSoLonNhatTrongMang(int a[], int n)
{
    if (n == 0)
        return a[n];
    else
    {
        if (a[n] > ham_TimSoLonNhatTrongMang(a, n - 1))
            return a[n];
        else
            return ham_TimSoLonNhatTrongMang(a, n - 1);
    }
}

/* Câu 12: Tính số ngày lây lan covid 19:

		   Tốc độ lây covid là Q người / ngày
		   Nghĩa là 1 người có thể lây lan cho Q người khác
		   So người ban đầu là N
		   Số người bị lây nhiễm là M
		   Tính số ngày để lây được từ N người lên M người
*/
int ham_SoNgayLayCovid(int Q, int N, int M)
{
    if (N >= M)
        return 0;
    else
        return 1 + ham_SoNgayLayCovid(Q, (N * Q) + N, M);
}

// ================================*****CÂU LÀM TRÊN LỚP*****=======================================
int ham_USCLN(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return ham_USCLN(b, a % b);
}

int ham_KySoLonNhat(int n)
{
    if (n < 10)
        return n;
    else
    {
        if (n % 10 > ham_KySoLonNhat(n / 10))
            return n % 10;
        else
            return ham_KySoLonNhat(n / 10);
    }
}

int ham_DemSoLeTrongMotSoNguyen(int n)
{
    if (n < 10)
    {
        if (n % 2 != 0)
            return 1;
    }
    else
    {
        if ((n % 10) % 2 != 0)
            return 1 + ham_DemSoLeTrongMotSoNguyen(n / 10);
        else
            return ham_DemSoLeTrongMotSoNguyen(n / 10);
    }
}

int ham_DemSoLeTuMotToiN(int n)
{
    if (n == 1)
        return 1;
    else
    {
        if (n % 2 != 0)
            return 1 + ham_DemSoLeTuMotToiN(n - 1);
        else
            return ham_DemSoLeTuMotToiN(n - 1);
    }
}

// S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
double ham_TongPhanSo(int n)
{
    if (n == 1)
        return 1;
    else
        return (1 * 1.0) / n + ham_TongPhanSo(n - 1);
}

// S = a + (a + d) + (a + 2d) + (a+ 3d) + ... + (a + nd) Cấp số cộng
int ham_CapSoCong(int n, int a, int d)
{
    if (n == 1)
        return a;
    else
        return (a + (n - 1) * d) + ham_CapSoCong(n - 1, a, d);
}

// S = a + a*q + a*q^2 + a*q^3 + ... + a*q^n
int ham_CapSoNhan(int n, int a, int q)
{
    if (n == 1)
        return a;
    else
    {
        int q1 = 1;
        for (int i = 1; i < n; i++)
        {
            q1 = q1 * q;
        }
        return a * q1 + ham_CapSoNhan(n - 1, a, q);
    }
}

double ham_DienTichHinhVuongHinhTronLongNhau(int n, double a)
{
    if (n % 2 != 0)
    {
        if (n == 1)
            return a * a;
        else
            return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a / sqrt(double(2)));
            //return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a) / 2;
    }
    else
    {
        if (n == 2)
            return pi * (a / 2) * (a / 2);
        else
            return ham_DienTichHinhVuongHinhTronLongNhau(n - 2, a / sqrt(double(2)));
    }
}
//============================================================================================================