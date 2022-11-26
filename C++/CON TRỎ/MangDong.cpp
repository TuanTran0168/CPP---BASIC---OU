#include <iostream>
using namespace std;
void ham_1(int &n);
void ham_NhapMang(int *a, int n);
void ham_XuatMang(int *a, int n);

int main()
{
    system("color 3");
    int n;

    cout << "\n====================== NHAP MANG 1 CHIEU CAP PHAT DONG======================\n\n";
    ham_1(n);
    int *a = new int[n];
    ham_NhapMang(a, n);

    cout << "\n====================== XUAT MANG 1 CHIEU CAP PHAT DONG======================\n\n";
    ham_XuatMang(a, n);
    delete[] a;

    cout << endl;
    system("pause");
    return 0;
}

void ham_1(int &n)
{
    do
    {
        cout << "Nhap so phan tu cua mang: ";
        cin >> n;
    } while (n <= 0);
}

void ham_NhapMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void ham_XuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}