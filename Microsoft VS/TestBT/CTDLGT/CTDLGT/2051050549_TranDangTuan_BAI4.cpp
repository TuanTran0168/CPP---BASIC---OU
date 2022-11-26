#include <iostream>
#define MAX 100
using namespace std;
void ham_InPut(int a[MAX], int &n);
void ham_OutPut(int a[MAX], int n);
void ham_Search(int a[MAX], int n, int x);

int main()
{
    int a[MAX];
    int n;

    ham_InPut(a, n);
    ham_OutPut(a, n);
    cout << "\n========================\n";
    int x;
    cout << "\nNhap x: ";
    cin >> x;
    ham_Search(a, n, x);

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

void ham_Search(int a[MAX], int n, int x)
{
    int b[MAX];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            b[count++] = i;
    }

    if (count == 0)
        cout << "\nKhong xuat hien!!!";
    else
    {
        cout << "\nPhan tu (" << x << ") xuat hien (" << count << ") lan va o cac vi tri: ";

        for (int i = 0; i < count; i++)
        {
            cout << b[i] << " ";
        }
    }
}