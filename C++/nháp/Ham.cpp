#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ham_DoiChu(string Data, string TimKiem, string ThayThe);

int main()
{
    ifstream docFile;
    string Adress;
    cout << "Nhap dia chi tap tin: ";
    getline(cin, Adress); // D:\\TXT\\DoiChu.txt  D:\\TXT\\MoHo.txt	D:\\TXT\\NhuNhungPhutBanDau.txt
    string Data = " ";
    string TimKiem, ThayThe;

    docFile.open(Adress, ios::in);
    if (docFile.is_open())
    {
        cout << "Doc File thanh cong!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, Data);
            //ham_DoiChu(Data, TimKiem, ThayThe);
            cout << Data << endl;
        }

        docFile.close();
    }
    else
    {
        cout << "Khong tim duoc File";
    }

    cout << "\nBan muon doi chu nao: ";
    getline(cin, TimKiem);
    cout << "Nhap chu ma ban muon doi: ";
    getline(cin, ThayThe);
    cout << endl;

    docFile.open(Adress, ios::in);
    while (docFile.eof() == false)
    {
        getline(docFile, Data);
        ham_DoiChu(Data, TimKiem, ThayThe);
    }
    docFile.close();

    cout << endl;
    system("pause");
    return 0;
}

void ham_DoiChu(string Data, string TimKiem, string ThayThe)
{
    int begin = 0;
    int sl = 0;
    for (int i = 0; i < TimKiem.length(); i++)
    {
        sl++;
    }

    for (int i = 0; i < Data.length(); i++) // Tìm được sau đó đổi chữ luôn rồi tìm tiếp
    {
        begin = Data.find(TimKiem, 0);
        if (begin >= 0)
        {
            /*cout << Data << endl;
              cout << begin << endl;
			  cout << Data.length() << endl;*/
            Data.replace(begin, sl, ThayThe);
        }
    }
    cout << Data << endl;
}