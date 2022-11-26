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
                if (n % 2 != 0)
                {
                    for (int i = 2; i < n; i++)
                    {
                        if (n % i == 0)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so bat ki: ";
        cin >> n;
        if (KTraSoNgTo(n) == true)
        {
            cout << "So " << n << " La so nguyen to\n\n";
        }
        else
        {
            cout << "So " << n << " Khong phai so nguyen to\n\n";
        }

        int check;
        do
        {
            cout << "Ban co muon lam lai khong ? \n1.Co\n0.Khong " << endl;
            cout << "Nhap: ";
            cin >> check;
            cout << endl;
        } while (check != 0 && check != 1);

        if (check == 0)
        {
            cout << "KET THUC !\n";
            break;
        }
    } while (n >= 0 || n < 0);
    system("pause");
    return 0;
}