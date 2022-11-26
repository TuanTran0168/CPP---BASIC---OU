#include <iostream>
using namespace std;
bool ham_KTraSoHoanThien(int n)
{
    int tong = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            tong = tong + i;
        }
    }
    if (tong == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap n: ";
        cin >> n;
        if (ham_KTraSoHoanThien(n))
        {
            cout << n << " La so hoan thien\n\n";
        }
        else
        {
            cout << n << " Khong phai so hoan thien\n\n";
        }
    } while (n >= 0);
}