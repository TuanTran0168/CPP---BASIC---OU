#include <iostream>
using namespace std;
int ham_DemSoLuongChuSo(int n);
int ham_DaoNguocSo(int n);
void ham_DocChuSo(int ChuSo);
void ham_DocSo(int n);

int main()
{
    int n;
    do
    {
        cout << "\nNhap n: ";
        cin >> n;
        ham_DocSo(n);
    } while (1);

    cout << endl;
    system("pause");
    return 0;
}

int ham_DemSoLuongChuSo(int n)
{
    int dem = 0;
    while (n > 0)
    {
        n = n / 10;
        dem++;
    }
    return dem;
}

int ham_DaoNguocSo(int n)
{
    int daonguoc = 0;
    while (n > 0)
    {
        daonguoc = (daonguoc * 10) + (n % 10);
        n = n / 10;
    }
    return daonguoc;
}

void ham_DocChuSo(int ChuSo)
{
    if (ChuSo == 0)
    {
        cout << " Khong ";
    }
    else if (ChuSo == 1)
    {
        cout << " Mot ";
    }
    else if (ChuSo == 2)
    {
        cout << " Hai ";
    }
    else if (ChuSo == 3)
    {
        cout << " Ba ";
    }
    else if (ChuSo == 4)
    {
        cout << " Bon ";
    }
    else if (ChuSo == 5)
    {
        cout << " Nam ";
    }
    else if (ChuSo == 6)
    {
        cout << " Sau ";
    }
    else if (ChuSo == 7)
    {
        cout << " Bay ";
    }
    else if (ChuSo == 8)
    {
        cout << " Tam ";
    }
    else if (ChuSo == 9)
    {
        cout << " Chin ";
    }
}

void ham_DocSo(int n)
{
    int SoDaoNguoc = ham_DaoNguocSo(n);
    int slcs = ham_DemSoLuongChuSo(SoDaoNguoc);
    while (SoDaoNguoc != 0)
    {
        ham_DocChuSo(SoDaoNguoc % 10);
        if (slcs == 12)
        {
            cout << "Tram";
        }
        if (slcs == 11)
        {
            cout << "Muoi";
        }
        if (slcs == 10)
        {
            cout << "Ti";
        }
        /*******************************************************/
        if (slcs == 9)
        {
            cout << "Tram";
        }
        if (slcs == 8)
        {
            cout << "Muoi";
        }
        if (slcs == 7)
        {
            cout << "Trieu";
        }
        /*********************************************************/
        if (slcs == 6)
        {
            cout << "Tram";
        }
        if (slcs == 5)
        {
            cout << "Muoi";
        }
        if (slcs == 4)
        {
            cout << "Ngan";
        }
        /*********************************************************/
        if (slcs == 3)
        {
            cout << "Tram";
        }
        if (slcs == 2)
        {
            cout << "Muoi";
        }
        slcs--;
        SoDaoNguoc = SoDaoNguoc / 10;
    }
}
