#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int a[100][100];
	int tong, i;
	int m = 3;
	int n = 5;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap a[" << i << "[" << j << "]: ";
			cin >> a[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++)
	{
		for (int k = i; k < m; k++)
		{
			for (int j = 0; j < n; j++)
			{
				tong[i] = tong[i] + a[k][j];
			}
		}
	}
	int a = tong[i];
	cout << "Tong la: " << a;
	system("pause");
	return 0;
}