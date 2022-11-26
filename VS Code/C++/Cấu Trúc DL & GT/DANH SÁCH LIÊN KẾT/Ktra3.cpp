#include <iostream>
#define MAX 100
using namespace std;
void ham_InPut(int a[MAX], int &n);
void ham_OutPut(int a[MAX], int n);
void ham_QuickSort_Update(int a[MAX], int left, int right);

int Gan = 0, SoSanh = 0, PhepToan = 0;
int main()
{
    int a[MAX];
    int n;
    ham_InPut(a, n);
    cout << "\n\tDanh sach dac chua sap xep\n";
    ham_OutPut(a, n);
    cout << "\n===========================================\n";

    ham_QuickSort_Update(a, 0, n - 1);
    cout << "\n\tDanh sach dac da sap xep\n";
    ham_OutPut(a, n);

    cout << "\nSo luong phep Gan la: " << Gan;
    cout << "\nSo luong phep So Sanh la: " << SoSanh;
    cout << "\nSo luong phep Toan la: " << PhepToan;

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

void ham_QuickSort_Update(int a[MAX], int left, int right)
{
    int x = a[(left + right) / 2];
    PhepToan++;

    int i = left;
    int j = right;

    Gan += 3;

    SoSanh++;
    while (i < j)
    {
        SoSanh++;
        while (a[i] < x)
        {
            i++;
            PhepToan++;
            Gan++;

            SoSanh++;
        }

        SoSanh++;
        while (a[j] > x)
        {
            j--;
            PhepToan++;
            Gan++;

            SoSanh++;
        }

        SoSanh++;
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            Gan += 3;

            i++;
            j--;
            PhepToan += 2;
            Gan += 2;
        }

        SoSanh++;
    }

    SoSanh++;
    if (left < j)
    {
        ham_QuickSort_Update(a, left, j);
    }

    SoSanh++;
    if (i < right)
    {
        ham_QuickSort_Update(a, i, right);
    }
}