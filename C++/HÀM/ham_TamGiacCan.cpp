#include <iostream>
using namespace std;
void TamGiacCan(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= (2 * h - 1); j++)
        {
            if ((j >= h - i + 1) && (j <= h + i - 1))
            {
                cout << "*";
            }
            //else
            //{
             //   cout << " ";
           // }
        }
        cout << endl;
    }
}
int main()
{
    int h;
    cout << "\nnhap chieu cao: ";
    cin >> h;
    TamGiacCan(h);
    system("pause");
    return 0;
}