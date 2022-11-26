#include <iostream>
#define MAX 100
using namespace std;
void ham_NhapDS(int a[MAX], int &n);
void ham_XuatDS(int a[MAX], int n);
int ham_TimKiem(int a[MAX], int n, int x);
void ham_Them(int a[MAX], int &n, int &vitri, int &x);
void ham_Xoa(int a[MAX], int &n, int &vitri);
void ham_TimVaXoa(int a[MAX], int &n, int x);
void ham_MENU(int &luachon);

int main()
{
    int a[MAX];
    int n, x, vitri, luachon;
    do
    {
        system("cls");
        ham_MENU(luachon);

        if (luachon == 1)
        {
            ham_NhapDS(a, n);
        }
        else if (luachon == 2)
        {
            ham_XuatDS(a, n);
        }
        else if (luachon == 3)
        {
            cout << "\nNhap gia tri can tim: ";
            cin >> x;

            if (ham_TimKiem(a, n, x) != -1)
            {
                cout << "\nVi tri phan tu ban muon tim la: " << ham_TimKiem(a, n, x);
            }
            else
                cout << "\nKhong tim thay!";
        }
        else if (luachon == 4)
        {
            ham_Them(a, n, vitri, x);
        }
        else if (luachon == 5)
        {
            ham_Xoa(a, n, vitri);
        }
        else if (luachon == 6)
        {
            ham_TimVaXoa(a, n, x);
        }
        else
        {
            cout << "\n=====KET THUC CHUONG TRINH====\n";
        }

        system("pause");

    } while (luachon != 7);

    system("pause");
    return 0;
}

void ham_NhapDS(int a[MAX], int &n)
{
    cout << "\nNhap so luong phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void ham_XuatDS(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int ham_TimKiem(int a[MAX], int n, int x)	// Độ phức tạp O(n)
{
    int vitri = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            vitri = i;
            break;
        }
    }

    if (vitri == 0)
        return -1;
    else
        return vitri;
}

void ham_Them(int a[MAX], int &n, int &vitri, int &x)
{
    cout << "\nNhap vi tri them: ";
    cin >> vitri;
    cout << "Nhap gia tri them: ";
    cin >> x;

    if (vitri >= 0 && vitri < n)
    {
        for (int i = n - 1; i >= vitri; i--)
        {
            a[i + 1] = a[i];
        }

        a[vitri] = x;
        n++;
    }
    else
        return;
}

void ham_Xoa(int a[MAX], int &n, int &vitri)	// Độ phức tạp O(n)
{
    cout << "\nNhap vi tri xoa: ";
    cin >> vitri;

    if (vitri >= 0 && vitri < n)
    {
        for (int i = vitri; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
    else
        return;
}

void ham_TimVaXoa(int a[MAX], int &n, int x)	// Độ phức tạp O(n^2)
{
    int dem = 0;
    cout << "\nNhap gia tri xoa: ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            dem++;
        }
    }

    if (dem == 0)
        cout << "\nKhong tim thay!";
    else
        n--;
}

void ham_MENU(int &luachon)
{
    cout << "\n===== MENU CHON LUA ====\n";
    cout << "\n1.Nhap mang";
    cout << "\n2.Xuat mang";
    cout << "\n3.Tim phan tu";
    cout << "\n4.Them phan tu";
    cout << "\n5.Xoa phan tu";
    cout << "\n6.Tim va xoa phan tu do";
    cout << "\n7.Ket thuc";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> luachon;

    } while (luachon < 1 && luachon > 7);
}