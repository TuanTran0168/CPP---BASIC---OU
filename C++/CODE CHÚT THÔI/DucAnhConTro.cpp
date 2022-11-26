#include <iostream>
using namespace std;
void ham_NhapMangMotChieu(double *&a, int &n);
void ham_XuatMangMotChieu(double *a, int n);
double ham_TimMaxMin(double *a, int n, bool o);
double ham_TinhTBCong(double *a, int n);
bool ham_KtraDoiXung(double *a, int n);

int main()
{
    double *a;
    int n;
    ham_NhapMangMotChieu(a, n);
    ham_XuatMangMotChieu(a, n);

    cout << "\nMAX la: " << ham_TimMaxMin(a, n, 1);
    cout << "\nMIN la: " << ham_TimMaxMin(a, n, 0);
    cout << "\nTrung binh cong la: " << ham_TinhTBCong(a, n);

    if (ham_KtraDoiXung(a, n))
        cout << "\nMang doi xung";
    else
        cout << "\nMang khong doi xung";

    cout << endl;
    delete[] a;
    system("pause");
    return 0;
}

void ham_NhapMangMotChieu(double *&a, int &n)
{
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    cout << endl;

    a = new double[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu [" << i << "]: ";
        cin >> *(a + i);
    }
}

void ham_XuatMangMotChieu(double *a, int n)
{
    cout << "\n\tMang cua ban\n";
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

double ham_TimMaxMin(double *a, int n, bool o)
{
    double temp = *(a + 0);

    if (o == true) // MAX
    {
        for (int i = 1; i < n; i++)
        {
            if (*(a + i) > temp)
            {
                temp = *(a + i);
            }
        }
        return temp;
    }

    else if (o == false) //MIN
    {
        for (int i = 1; i < n; i++)
        {
            if (*(a + i) < temp)
            {
                temp = *(a + i);
            }
        }
        return temp;
    }
}

double ham_TinhTBCong(double *a, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += *(a + i);
    }

    return sum / n;
}

bool ham_KtraDoiXung(double *a, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(a + i) != *(a + n - i - 1))
        {
            count++;
        }
    }

    if (count == 0)
        return true;
    else
        return false;
}