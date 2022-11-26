#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream docFILE;
    ofstream ghiFILE;
    cout << "\nNhap dia chi tap tin: "; //	D:\\TXT\\BTH4.txt   D:\\TXT\\MoHo.txt	D:\\TXT\\NhuNhungPhutBanDau.txt
    string Adress = " ";
    getline(cin, Adress);
    string Data = " ";
    int SoNguyenAm = 0;

    docFILE.open(Adress, ios::in);
    if (docFILE.is_open())
    {
        cout << "\nDoc FILE thanh cong\n\n";
        while (!docFILE.eof())
        {
            getline(docFILE, Data);
            cout << Data << endl;
            for (int i = 0; i < Data.length(); i++)
            {
                if (Data[i] == 'u' || Data[i] == 'e' || Data[i] == 'o' || Data[i] == 'a' || Data[i] == 'i' || Data[i] == 'U' || Data[i] == 'E' || Data[i] == 'O' || Data[i] == 'A' || Data[i] == 'I')
                {
                    SoNguyenAm++;
                    cout << SoNguyenAm << endl;
                }
            }
        }
        docFILE.close();
        cout << "\nSo nguyen am la: " << SoNguyenAm;
    }
    else
    {
        cout << "\nKhong tim duoc FILE";
    }

    cout << endl;
    system("pause");
    return 0;
}