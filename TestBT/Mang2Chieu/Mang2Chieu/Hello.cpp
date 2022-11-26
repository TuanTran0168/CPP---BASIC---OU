#include <iostream>
using namespace std;
#define MAX 100

void ham_NhapMang(double a[MAX][MAX], int &col, int &row);
void ham_XuatMang(double a[MAX][MAX], int col, int row);
double ham_Tich1Dong(double a[MAX][MAX], int row, int dong);
double ham_Tich1Cot(double a[MAX][MAX], int col, int cot);
void ham_SapXepTangDan(double a[][100], int col, int row);
void ham_SapXepGiamDan(double a[][100], int col, int row);
double ham_TinhTong(double a[][100], int col, int row);

int main()
{
	double a[MAX][MAX];
	int col, row, dong, cot;
	ham_NhapMang(a, col, row);
	ham_XuatMang(a, col, row);
	cout << "\nNhap dong ban muon nhan: ";
	cin >> dong;
	cout << "Tich tren dong thu " << dong << " la: " << ham_Tich1Dong(a, row, dong);

	cout << "\n\nNhap cot ban muon nhan: ";
	cin >> cot;
	cout << "Tich tren cot thu " << cot << " la: " << ham_Tich1Cot(a, row, cot);
	cout << endl;

	system("pause");
	return 0;
}

void ham_NhapMang(double a[MAX][MAX], int &col, int &row)
{
	cout << "Nhap so dong: ";
	cin >> col;
	cout << "Nhap so cot: ";
	cin >> row;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout << "Nhap phan tu o vi tri [" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}

void ham_XuatMang(double a[MAX][MAX], int col, int row)
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

void ham_SapXepGiamDan(double a[][100], int col, int row)
{
  for(int i = 0; i < col; i++)
  {
    for(int j = 0; j < row; j++)
    {
      for(int m = 0; m < col; m++)
      {
        for(int n = 0; n < row; n++)
        {
          if(a[i][j] > a[m][n])
          {
            double temp = a[i][j];
             a[i][j] = a[m][n];
             a[m][n] = temp;
          }
        }
      }
    }
  }
}

void ham_SapXepTangDan(double a[][100], int col, int row)
{
  for(int i = 0; i < col; i++)
  {
    for(int j = 0; j < row; j++)
    {
      for(int m = 0; m < col; m++)
      {
        for(int n = 0; n < row; n++)
        {
          if(a[i][j] < a[m][n])
          {
            double temp = a[i][j];
             a[i][j] = a[m][n];
             a[m][n] = temp;
          }
        }
      }
    }
  }
}

double ham_TinhTong(double a[][100], int col, int row)
{
  double sum = 0;
  for(int i = 0; i < col; i++)
  {
    for(int j = 0; j < row; j++)
    {
      sum = sum + a[i][j];
    }
  }
  return sum;
}