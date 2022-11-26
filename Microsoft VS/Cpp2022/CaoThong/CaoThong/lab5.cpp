#include <iostream>
#include <string>
using namespace std;

int cau3_a(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i * i;
	}
	return sum;
}

int cau3_b(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += 1 / i;
	}
	return sum;
}

int cau3_c(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i += 2)
	{
		sum += 1 / (2 * n - 1);
	}
	return sum;
}

void cau11_a(int n)
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

void cau11_b(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void cau12_a(int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == n || i == j)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void cau12_b (int n)
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

void cau12_c (int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void cau12_d (int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j >= i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void cau12_e (int n)
{
	int i, j;
	int h = n / 2 + 1;

	for (i = 0; i <= h; i++)
	{
		for (int j = 0; j <= h * 2; j++)
		{
			if (j >= h - i && j <= h + i)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	cau12_e(4);
	system("pause");
	return 0;
}