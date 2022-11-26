#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void ham_Xoa(string a, int vitri);
void ham_XoaCacPhanTuTrung(string a);

void ham_XoaChar(char a[], int vitri);
void ham_XoaCacPhanTuTrungChar(char a[]);
void ham_XoaCacPhanTuTrungChar1(char a[]);

void ham_Xuat(string a, int n);

int main()
{
    string a;
    char b[1000];
    cout << "Nhap cai gi di: ";
    getline(cin, a);
    int n = a.length();
    ham_XoaCacPhanTuTrung(a);

    gets(b);
    ham_XoaCacPhanTuTrungChar(b);
    cout << "\nChuoi 1: " << b;

    ham_XoaCacPhanTuTrungChar1(b);
    cout << "\nChuoi 2: " << b;

    system("pause");
    return 0;
}

void ham_Xoa(string a, int vitri)
{
    int n = a.length();
    for (int i = vitri; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = '\0';
}

void ham_XoaCacPhanTuTrung(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = i + 1; j < a.length(); j++)
        {
            if (a[i] == ' ' && a[j] == ' ')
            {
                ham_Xoa(a, j);
                i--;
            }
        }
    }
}

void ham_XoaChar(char a[], int vitri)
{
    for (int i = vitri; i < strlen(a) - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[strlen(a) - 1] = '\0';
}

void ham_XoaCacPhanTuTrungChar(char a[])
{
    for (int i = 0; i < strlen(a); i++)
    {
        for (int j = i + 1; j < strlen(a); j++)
        {
            if (a[i] == ' ' && a[j] == ' ')
            {
                ham_XoaChar(a, j);
                i--;
            }
        }
    }
}

void ham_XoaCacPhanTuTrungChar1(char a[])
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == ' ')
        {
            ham_XoaChar(a, i);
            i--;
        }
    }
}

void ham_Xuat(string a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
    cout << endl;
}