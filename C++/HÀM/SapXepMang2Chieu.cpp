#include <iostream>
using namespace std;

void ham_NhapMang(double a[][100], int &row, int &col);
void ham_XuatMang(double a[][100], int row, int col);
double ham_TinhTong(double a[][100], int row, int col);
void ham_SapXepTangDan(double a[][100], int row, int col);
void ham_SapXepGiamDan(double a[][100], int row, int col);

int main()
{
    double a[1000][100];
    int row, col;
    ham_NhapMang(a, row, col);
    ham_SapXepTangDan(a, row, col);
    ham_XuatMang(a, row, col);
    //cout << "Tong cac phan tu la: " << ham_TinhTong(a, row, col);
}

void ham_NhapMang(double a[][100], int &row, int &col)
{
  cout << "\nNhap so dong: ";
  cin >> row;
  cout << "Nhap so cot: ";
  cin >> col;
  cout << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cout << "Nhap phan tu o vi tri "
         << "a[" << i << "][" << j << "]: ";
      cin >> a[i][j];
    }
    cout << endl;
  }
}

void ham_XuatMang(double a[][100], int row, int col)
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

double ham_TinhTong(double a[][100], int row, int col)
{
  double sum = 0;
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      sum = sum + a[i][j];
    }
  }
  return sum;
}

void ham_SapXepGiamDan(double a[][100], int row, int col)
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      for(int m = 0; m < row; m++)
      {
        for(int n = 0; n < col; n++)
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

void ham_SapXepTangDan(double a[][100], int row, int col)
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < col; j++)
    {
      for(int m = 0; m < row; m++)
      {
        for(int n = 0; n < col; n++)
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