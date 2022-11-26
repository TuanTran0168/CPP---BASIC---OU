#include <iostream>
using namespace std;
int main1()
{
	int Max;
    double a[100];
	cout<<"Nhap so phan tu toi da: ";
	cin>> Max;
    cout << "Nhap " << Max << " phan tu trong mang: "<< endl;
    for (int i = 1; i <= Max; i++)
    {
		cout<<"Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
    int soLonNhat = a[1];
    for (int i = 1; i <= Max; i++)
    {
        if (soLonNhat < a[i])
        {
            soLonNhat = a[i];
        }
    }
    cout << "So lon nhat la: " << soLonNhat << endl;
    double tong = 0;
    for (int i = 1; i <= Max; i++)
    {
        tong = tong + a[i];
    }
    cout<<"Tong la: " << tong << endl;
    cout<<"Gia tri trung binh la: "<< (tong * 1.0) / Max << endl;
    system("pause");
	return 0;
}