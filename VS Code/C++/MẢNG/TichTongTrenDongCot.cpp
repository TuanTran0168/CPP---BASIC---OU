#include <iostream>
using namespace std;
#define MAX 100
void ham_NhapMang(double a[MAX][MAX], int &row, int &col);
void ham_XuatMang(double a[MAX][MAX], int row, int col);
double ham_Tich1Dong(double a[MAX][MAX], int row, int dong);
double ham_Tich1Cot(double a[MAX][MAX], int col, int cot);

int main()
{
	double a[MAX][MAX];
	int col, row, dong, cot;
	ham_NhapMang(a, row, col);
	ham_XuatMang(a, row, col);
	cout << "\nNhap dong ban muon nhan: ";
	cin >> dong;
	cout << "Tich tren dong thu " << dong << " la: " << ham_Tich1Dong(a, row, dong);

	cout << "\n\nNhap cot ban muon nhan: ";
	cin >> cot;
	cout << "Tich tren cot thu " << cot << " la: " << ham_Tich1Cot(a, col, cot);
	cout << endl;

	system("pause");
	return 0;
}

void ham_NhapMang(double a[MAX][MAX], int &row, int &col)
{
	cout << "Nhap so dong: ";
	cin >> col;
	cout << "Nhap so cot: ";
	cin >> row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Nhap phan tu o vi tri [" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void ham_XuatMang(double a[MAX][MAX], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

double ham_Tich1Dong(double a[MAX][MAX], int row, int dong)
{
	double tich = 1;
	for (int j = 0; j < row; j++)
	{
		tich = tich * a[dong][j];
	}
	return tich;
}

double ham_Tich1Cot(double a[MAX][MAX], int col, int cot)
{
	double tich = 1;
	for (int i = 0; i < col; i++)
	{
		tich = tich * a[i][cot];
	}
	return tich;
}
