#include <iostream>
using namespace std;
bool KTraSoNgTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        if (n == 2)
        {
            return true;
        }
        else
        {
            if (n % 2 == 0)
            {
                return false;
            }
            else
            {
                for (int i = 2; i < n; i++)
                {
                    if (n % i == 0)
                        return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Nhap so: ";
    cin >> n;
    if (KTraSoNgTo(n) == true)
    {
        cout << "La so nguyen to";
    }
    else
    {
        cout << "Khong phai so nguyen to";
    }
}

