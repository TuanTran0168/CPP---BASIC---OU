#include <iostream>
using namespace std;

void ham_NhapMang(double a[][100], int &col, int &row);
void ham_XuatMang(double a[][100], int col, int row);

int main()
{
	double a[1000][100];
	int row, col;
	cout << "\n\n\t\tNHAP MANG";
	cout << endl;
	ham_NhapMang(a, col, row);
	cout << "\n\n\tXUAT MANG";
	cout << endl;
	ham_XuatMang(a, col, row);
	system("pause");
	return 0;
}

void ham_NhapMang(double a[][100], int &col, int &row)
{
	cout << "\nNhap dong: ";
	cin >> col;
	cout << "Nhap cot: ";
	cin >> row;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << "Nhap phan tu o vi tri "
				 << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void ham_XuatMang(double a[][100], int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
