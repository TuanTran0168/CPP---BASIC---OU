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
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << tinhToHop(i, j) << " ";
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
}