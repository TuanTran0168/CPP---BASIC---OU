#include <iostream>
using namespace std;
void ham_GanXoanOc(int a[100][100], int n);
void ham_Xuat(int a[100][100], int Dong, int Cot);

int main()
{
    int a[100][100];
    int n = 3;

    ham_GanXoanOc(a, n);
    ham_Xuat(a, n, n);

    system("pause");
    return 0;
}

void ham_GanXoanOc(int a[100][100], int n)
{
    int MaxDong, MaxCot, MinDong, MinCot;
    MaxDong = MaxCot = n - 1;
    MinDong = MinCot = 0;
    int Value = 1;

    while (Value <= n * n)
    {
        for (int i = MinCot; i <= MaxCot; i++)
        {
            a[MaxDong][i] = Value++;
        }
        MaxDong--;

        for (int i = MaxDong; i >= MinDong; i--)
        {
            a[i][MaxCot] = Value++;
        }
        MaxCot--;

        for (int i = MaxCot; i >= MinCot; i--)
        {
            a[MinDong][i] = Value++;
        }
        MinDong++;

        for (int i = MinDong; i <= MaxDong; i++)
        {
            a[i][MinCot] = Value++;
        }
        MinCot++;
    }
}

void ham_Xuat(int a[100][100], int Dong, int Cot)
{
    for (int i = 0; i < Dong; i++)
    {
        for (int j = 0; j < Cot; j++)
        {
            cout << *(*(a + i) + j) << " ";
        }
        cout << endl;
    }
}