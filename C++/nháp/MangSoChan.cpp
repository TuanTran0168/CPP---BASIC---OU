#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    int a[100];
    cout << "Nhap so phan tu toi da: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }  
    cout << "Cac phan tu trong mang co gia tri la so chan: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}