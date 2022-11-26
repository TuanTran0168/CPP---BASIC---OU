#include <iostream>
using namespace std;
int tinhGiaiThua(int n)
{
    int KQ = 1;
    for (int i = 1; i <= n; i++)
    {
        KQ = KQ * i;
    }
    return KQ;
}
double tinhToHop(int n, int k) // tổ hợp C n chập k
{
    return tinhGiaiThua(n) / (tinhGiaiThua(k) * tinhGiaiThua(n - k));
}
void xuatTamGiacPascal(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= (2 * h - 1); j++)
        {
            if ((j >= h - i + 1) && (j <= h + i - 1))
            {
                cout << tinhToHop(i, j);
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int h;
    cout << "Nhap chieu cao tam giac Pascal: ";
    cin >> h;
    xuatTamGiacPascal(h);
    return 0;
}