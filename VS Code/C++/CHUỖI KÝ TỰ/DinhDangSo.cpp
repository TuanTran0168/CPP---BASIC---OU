#include <iostream>
#include <string>
using namespace std;
void ham_ThemDauCham(string s, int vitri);
void ham_ThemDauChamChar(char s[], int vitri);

int main()
{
    string s;
    string s1;
    cout << "Nhap cai gi di: ";
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            s1 += s[i];
        }
    }
    cout << s1 << endl;

    //int tong = 0;
    //int num = 0;
    //for (int i = 0; i < s1.length(); i++)
    //{
    //	num = num * 10 + (s1[i] - '0');
    //	tong = tong + (s1[i] - '0');
    //}

    //cout << "Tong la: " << tong << endl;
    //cout << num;

    static char s2[100];
    for (int i = 0; i < s1.length(); i++)
    {
        s2[i] = s1[i];
    }

    for (int i = strlen(s2) - 3; i > 0; i -= 3)
    {
        ham_ThemDauChamChar(s2, i);
    }

    cout << s2;

    system("pause");
    return 0;
}

void ham_ThemDauCham(string s, int vitri)
{
    for (int i = s.length(); i >= vitri; i--)
    {
        s[i + 1] = s[i];
    }
    s[vitri] = '.';
}

void ham_ThemDauChamChar(char s[], int vitri)
{
    for (int i = strlen(s); i >= vitri; i--)
    {
        s[i + 1] = s[i];
    }
    s[vitri] = '.';
}