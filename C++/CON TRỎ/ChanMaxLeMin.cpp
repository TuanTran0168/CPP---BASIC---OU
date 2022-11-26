#include <iostream>
using namespace std;
// Tìm số chẵn lớn nhất và số lẻ nhỏ nhất trong mảng
void ham_Nhap(int *&a, int &n);
void ham_Xuat(int *a, int n);
int ham_ChanMax(int *a, int n);
int ham_LeMin(int *a, int n);

int main()
{
    int *a;
    int n;

    ham_Nhap(a, n);
    ham_Xuat(a, n);

    if (ham_ChanMax(a, n) == 0)
    {
        cout << "\nKhong co phan tu chan!";
    }
    else
    {
        cout << "\nPhan tu chan lon nhat la: " << ham_ChanMax(a, n);
    }

    if (ham_LeMin(a, n) == 0)
    {
        cout << "\nKhong co phan tu le!";
    }
    else
    {
        cout << "\nPhan tu le nho nhat la: " << ham_LeMin(a, n);
    }

    delete a;

    system("pause");
    return 0;
}

void ham_Nhap(int *&a, int &n)
{
    cout << "\tNhap so phan tu mang: ";
    cin >> n;

    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> *(a + i);
    }
}

void ham_Xuat(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

int ham_ChanMax(int *a, int n)
{
    int Max = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            Max = *(a + i); // Lấy phần tử chẵn đầu tiên
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0 && *(a + i) > Max) // Tìm chẵn Max
        {
            Max = *(a + i);
        }
    }

    return Max;
}

int ham_LeMin(int *a, int n)
{
    int Min = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 != 0)
        {
            Min = *(a + i); // Lấy phần tử lẻ đầu tiên
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 != 0 && *(a + i) < Min) // Tìm lẻ Min
        {
            Min = *(a + i);
        }
    }

    return Min;
}