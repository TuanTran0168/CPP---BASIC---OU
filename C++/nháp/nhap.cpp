#include <iostream>
using namespace std;

int SoHangThuN(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return (n * n * SoHangThuN(3 - (n - 1)) + SoHangThuN(n - 1));
	}
}

int main()
{
	const int n = 20;
	long long x[n];
	x[0] = 1;
	for (int i = 1; i < n; i++)
	{
		x[i] = 0;
		for (int j = 0; j < i; j++)
			x[i] += (i - j) * (i - j) * x[j];
	}
	for (int i = 0; i < n; i++)
		cout << "x[" << i + 1 << "] = " << x[i] << endl;

	system("pause");
	return 0;
}

void ham_ThemPhanTuVaoMang(int a[], int &Maxsize, int x, int k)

{
	cout << "Nhap gia tri muon them: ";
	cin >> x;
	cout << "Nhap vi tri ban muon them: ";
	cin >> k;
	for (int i = Maxsize - 1; i >= k - 1; i--)
	{
		a[i + 1] = a[i];
	}

	a[k - 1] = x;
	Maxsize++;
}
void ham_XuatMang(int a[], int Maxsize)
{
	for (int i = 0; i < Maxsize; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void ham_NhapMang(int a[], int &Maxsize)
{
	do
	{
		cout << "Nhap do lon cua mang: ";
		cin >> Maxsize;
		if (Maxsize <= 0 || Maxsize > 1000)
		{
			cout << "Do lon cua mang khong hop le\t";
			system("pause");
		}
	} while (Maxsize <= 0 || Maxsize > 1000);
	for (int i = 0; i < Maxsize; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
	cout << endl;
}
