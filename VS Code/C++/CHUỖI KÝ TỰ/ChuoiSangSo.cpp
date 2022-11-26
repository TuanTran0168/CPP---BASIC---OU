#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Nhap chuoi so: ";
    cin >> s;

    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        num = num * 10 + (s[i] - 48);
    }

    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] - 48 << endl;
    }

    cout << num;
    system("pause");
    return 0;
}