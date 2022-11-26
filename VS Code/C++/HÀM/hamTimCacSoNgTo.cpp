#include <iostream>
using namespace std;
bool KTraSoNgTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else // n > 2
    {
        if (n == 2) // neu n la so 2 thi la so nguyen to
        {
            return true;
        }
        else // nguoc lai neu n khac 2
        {
            if (n % 2 == 0) // neu n la so chan
            {
                return false;
            }
            else // neu n la so le
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
    int n1 = 0, n2 = 0;
    cout << "Tim so nguyen to tu n1 toi n2 nhap tu ban phim \n";
    while (n1 <= 0)
    {
        cout << "Nhap so N1 > 0 : ";
        cin >> n1;
    }
    while (n2 <= n1)
    {
        cout << "Nhap so N2 > " << n1 << " : ";
        cin >> n2;
    }

    for (int i = n1; i <= n2; i++)
    {
        if (KTraSoNgTo(i))
        {
            cout << i << " ";
        }
    }
}