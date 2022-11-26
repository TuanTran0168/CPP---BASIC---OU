#include <iostream>
#include <ctime>
#define MAX 100
using namespace std;
void nhapDS(int a[], int n);
void duyetDS(int a[], int n);
void khoiTao(int a[], int &n);
void SELECTION_SORT(int a[], int n);
void INSERTION_SORT(int a[], int n);
void BUBBLE_SORT(int a[], int n);
void INTERCHANGE_SORT(int a[], int n);
void QUICK_SORT(int a[], int left, int right);
void taoHeapMax(int a[], int i, int n);
void HEAP_SORT(int a[], int n);
int TIM_KIEM_TUAN_TU(int a[], int n, int x);
int TIM_KIEM_NHI_PHAN(int a[], int n, int x);

int main()
{
    int chon, kQ, x;
    int a[MAX];
	 /*int a[MAX] = {40, 60, 15, 50, 90, 20, 10, 70};*/
    int n;

    do
    {
        system("cls");
        cout << "-----BTH 2, CHUONG 3, XEP THU TU - TIM KIEM-----\n";
        cout << "1. Khoi tao danh sach ngau nhien " << endl;
        cout << "2. Nhap danh sach " << endl;
        cout << "3. Xuat danh sach " << endl;
        cout << "4. Xep thu tu danh sach bang SELECTION SORT" << endl;
        cout << "5. Xep thu tu danh sach bang INSERTION SORT" << endl;
        cout << "6. Xep thu tu danh sach bang BUBBLE SORT" << endl;
        cout << "7. Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
        cout << "8. Xep thu tu danh sach bang QUICK SORT" << endl;
        cout << "9. Xep thu tu danh sach bang HEAP SORT" << endl;
        cout << "10. Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
        cout << "11. Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
        cout << "12. Thoat" << endl;
        cout << "----------------\n";
        cout << "\nNhap cai gi di: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            khoiTao(a, n);
            break;

        case 2:
            nhapDS(a, n);
            break;

        case 3:
            duyetDS(a, n);
            break;

        case 4:
            SELECTION_SORT(a, n);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 5:
            INSERTION_SORT(a, n);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 6:
            BUBBLE_SORT(a, n);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 7:
            INTERCHANGE_SORT(a, n);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 8:
            QUICK_SORT(a, 0, n - 1);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 9:
            HEAP_SORT(a, n);
            cout << "\nDa sap xep xong!!!\n";
            duyetDS(a, n);
            break;

        case 10:
            cout << "\nNhap x: ";
            cin >> x;
            kQ = TIM_KIEM_TUAN_TU(a, n, x);
            if (kQ == -1)
                cout << "\nKhong tim thay phan tu " << x << "!";
            else
                cout << "\nTim thay phan tu " << x << " tai vi tri " << kQ;
            break;

        case 11:
            cout << "\nNhap x: ";
            cin >> x;
            kQ = TIM_KIEM_NHI_PHAN(a, n, x);
            if (kQ == -1)
                cout << "\nKhong tim thay phan tu " << x << "!";
            else
                cout << "\nTim thay phan tu " << x << " tai vi tri " << kQ;
            break;

        case 12:
            cout << "Chuong trinh ket thuc";
            break;
        default:
            cout << "Chuc nang khong ton tai!!!";
        }

        cout << endl;
        system("pause");
    } while (chon != 12);

    system("pause");
    return 0;
}

void nhapDS(int a[], int n)
{
    cout << "\nNhap so phan tu cua danh sach: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void duyetDS(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void khoiTao(int a[], int &n)
{
    srand(time(0));
    cout << "\nNhap so phan tu cua danh sach: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }
    cout << "\nDanh sach da tao ngau nhien la :";
    duyetDS(a, n);
}

void SELECTION_SORT(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int viTriMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[viTriMin])
                viTriMin = j;
        }
        swap(a[i], a[viTriMin]);
    }
}

void INSERTION_SORT(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void BUBBLE_SORT(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
        }
    }
}

void INTERCHANGE_SORT(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

void QUICK_SORT(int a[], int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if (left < j)
            QUICK_SORT(a, left, j);
        if (i < right)
            QUICK_SORT(a, i, right);
    }
}

void taoHeapMax(int a[], int i, int n)
{
    int j = 2 * i + 1;
    if (j >= n)
        return;
    if (j + 1 < n)
	{
        if (a[j] < a[j + 1])
            j = j + 1;
	}
    
	if (a[i] < a[j])
    {
        swap(a[i], a[j]);
        taoHeapMax(a, j, n);
    }
}

void HEAP_SORT(int a[], int n)
{
    int i = n / 2;
    while (i >= 0)
    {
        taoHeapMax(a, i, n - 1);
        i--;
    }

    int right = n - 1;
    while (right > 0)
    {
        swap(a[0], a[right]);
        right--;
        if (right > 0)
            taoHeapMax(a, 0, right);
    }
}

int TIM_KIEM_TUAN_TU(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int TIM_KIEM_NHI_PHAN(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}