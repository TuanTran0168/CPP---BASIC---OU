#include <iostream>
#define MAX 100
using namespace std;
void ham_InPut(int a[MAX], int &n);
void ham_OutPut(int a[MAX], int n);
void ham_QuickSort(int a[MAX], int left, int right);

int main()
{
    int a[MAX];
    int n;
    ham_InPut(a, n);
	cout << "\n\tDanh sach dac chua sap xep\n";
    ham_OutPut(a, n);
    cout << "\n===========================================\n";

    ham_QuickSort(a, 0, n - 1);
	cout << "\n\tDanh sach dac da sap xep\n";
    ham_OutPut(a, n);

	cout << endl;
    system("pause");
    return 0;
}

void ham_InPut(int a[MAX], int &n)
{
     do
	{
		cout << "\nNhap so luong phan tu: ";
		cin >> n;
	} while (n < 1 || n > MAX);

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void ham_OutPut(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void ham_QuickSort(int a[MAX], int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i < j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }
    if (left < j)
        ham_QuickSort(a, left, j);
    if (i < right)
        ham_QuickSort(a, i, right);
}