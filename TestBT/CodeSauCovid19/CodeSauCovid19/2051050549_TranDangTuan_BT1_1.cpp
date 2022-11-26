#include <iostream>
using namespace std;
#define MAX 5
// const int MAX = 5;

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int them(int a[], int &n, int viTri, int giaTri);
int xoa(int a[], int &n, int viTri);
int timKiem(int a[], int n, int viTri);
int timKiemCuoi(int a[], int n, int viTri);
int demSoPhanTu(int a[], int n, int giaTri);
void timVaXoaHet(int a[], int &n, int giaTri);

int main1()
{
	int a[MAX];
	int n, chon;
	int viTri, giaTri;
	int kQ;

	do
	{
		system("cls");
		cout << "1. Nhap danh sach\n";
		cout << "2. Xuat danh sach\n";
		cout << "3. Them mot phan tu tai vi tri i\n";
		cout << "4. Tim kiem phan tu trong danh sach va tra ve vi tri cuoi cung\n";
		cout << "5. Tim va xoa het cac phan tu giong nhau duoc tim thay\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Moi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "\nNhap so luong phan tu can su dung: ";
			cin >> n;
			nhapMang(a, n);
			break;

		case 2:
			xuatMang(a, n);
			break;

		case 3:
			cout << "\nNhap vi tri them: ";
			cin >> viTri;
			cout << "\nNhap gia tri them: ";
			cin >> giaTri;

			kQ = them(a, n, viTri, giaTri);
			if (kQ == 1)
			{
				cout << "\nThem thanh cong!!!";
				cout << "\n Mang sau khi them: ";
				xuatMang(a, n);
			}
			else
				cout << "\nThem khong thanh cong!!!";
			break;

		case 4:
			cout << "\nNhap gia tri can tim: ";
			cin >> giaTri;

			kQ = timKiemCuoi(a, n, giaTri);
			if (kQ == -1)
				cout << "\nKhong tim thay!!!";
			else
				cout << "\nTim thay phan tu " << giaTri << " tai vi tri " << kQ;
			break;

		case 5:
			cout << "\nNhap phan tu muon xoa: ";
			cin >> giaTri;
			timVaXoaHet(a, n, giaTri);
			cout << "\nMang sau khi xoa: ";
			xuatMang(a, n);
			break;

		case 0:
			cout << "Chuong trinh ket thuc";
			break;
		default:
			cout << "Chuc nang khong ton tai!!!";
		}

		cout << endl;
		system("pause");
	} while (chon != 0);

	cout << endl;
	system("pause");
	return 0;
}

void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

int them(int a[], int &n, int viTri, int giaTri)
{
	if (n < MAX && viTri < n + 1 && viTri >= 0)
	{
		for (int i = n - 1; i >= viTri; i--)
		{
			a[i + 1] = a[i];
		}

		a[viTri] = giaTri;
		n++;

		return 1;
	}

	return 0;
}
int xoa(int a[], int &n, int viTri)
{
	if (n > 0 && viTri >= 0 && viTri < n)
	{
		for (int i = viTri; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
		return 1;
	}

	return 0;
}

int timKiem(int a[], int n, int giaTri)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == giaTri)
			return i;
	}
	return -1;
}

int timKiemCuoi(int a[], int n, int giaTri)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] == giaTri)
			return i;
	}
	return -1;
}

int demSoPhanTu(int a[], int n, int giaTri)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == giaTri)
			count++;
	}

	return count;
}

void timVaXoaHet(int a[], int &n, int giaTri)
{
	int soLuong = demSoPhanTu(a, n, giaTri);

	while (soLuong > 0)
	{
		int viTri = timKiem(a, n, giaTri);
		xoa(a, n, viTri);
		soLuong--;
	}
}