#include <iostream>
using namespace std;

int main()
{
    //BAI 1
    int a, b, c;
    cout << "Nhap 3 so a b c: ";
    cin >> a >> b >> c;
    if (a > 0 && b > 0 && c > 0)
        cout << "Ca 3 so deu duong";

    //BAI 2
    int n, m;
    cout << "\nNhap n va m: ";
    cin >> n >> m;
    if (n % m == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    system("pause");
    return 0;
}
