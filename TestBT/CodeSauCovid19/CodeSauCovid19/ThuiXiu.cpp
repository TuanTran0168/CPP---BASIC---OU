#include <iostream>
using namespace std;

void veHinhVuong (int n);
void veHinhTamGiacTrai (int n);
void veHinhTamGiacPhai (int n);
void veHinhTamGiacCan (int n);

int main()
{
	int n = 5;
	
	veHinhVuong(n);
	cout << endl;

	veHinhTamGiacTrai(n);
	cout << endl;

	veHinhTamGiacPhai(n);
	cout << endl;

	veHinhTamGiacCan(n);
	cout << endl;

	system("pause");
	return 0;
}

void veHinhVuong (int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void veHinhTamGiacTrai (int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void veHinhTamGiacPhai (int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= n - i - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void veHinhTamGiacCan (int n)
{
	int i, j;
	int h = n / 2 + 1;

	for (i = 0; i < h; i++)
	{
		for (int j = 0; j < h * 2; j++)
		{
			if (j >= h - i && j <= h + i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}