#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void ham_CapPhatMangNgauNhien(int *&a, int n);
void ham_XuatMang(int *a, int n);
int ham_GTNN(int *a, int n);
void ham_DemSoAm(int *a, int n);

int main1()
{
	int *a;
	srand(time(NULL));
	int n = rand() % 20 + 1;
	cout << "n = " << n;

	ham_CapPhatMangNgauNhien(a, n);
	ham_XuatMang(a, n);

	cout << "\nGTNN la: " << ham_GTNN(a, n);
	ham_DemSoAm(a, n);

	cout << endl;
	delete[] a;
	system("pause");
	return 0;
}

void ham_CapPhatMangNgauNhien(int *&a, int n)
{
	a = new int [n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		*(a + i) = rand();
	}
}

void ham_XuatMang(int *a, int n)
{
	cout << "\n\tMANG CUA BAN!\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}

int ham_GTNN(int *a, int n)
{
	if ( n == 1)
	{
		return a[n - 1];
	}
	else
	{
		if ( a[n - 1] < ham_GTNN(a, n - 1))
		{
			return a[n - 1];
		}
		else if (a[n - 1] > ham_GTNN(a, n - 1))
		{
			return ham_GTNN(a, n - 1);
		}
	}
}

void ham_DemSoAm(int *a, int n)
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (*(a + i) < 0)
		{
			cout << *(a + i);
			count++;
		}
	}

	if (count == 0)
	{
		cout << "\nKhong co so am!";
	}
}