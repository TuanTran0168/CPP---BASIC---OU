#include <iostream>
using namespace std;
int main()
{
    int Max;
    int a[100];
    cout << "Nhap so phan tu toi da: ";
    cin >> Max;
    cout << "Nhap " << Max << " phan tu trong mang: " << endl;
    for (int i = 0; i < Max; i++)
    {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
    int soLonNhat = a[0];
    for (int i = 0; i < Max; i++)
    {
        if (soLonNhat < a[i])
        {
            soLonNhat = a[i];
        }
    }
    cout << "\nSo lon nhat la: " << soLonNhat << endl;
    double tong = 0;
    for (int i = 0; i < Max; i++)
    {
        tong = tong + a[i];
    }
    cout << "\nTong la: " << tong << endl;
    cout << "\nGia tri trung binh la: " << (tong * 1.0) / Max << endl;
    system("pause");
    return 0;
}