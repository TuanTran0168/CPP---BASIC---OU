#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void ham_DocTapTin(string &Data);
void ham_DoiChu(string &Data, string TimKiem, string ThayDoi);
void ham_DoiChuVaInRaManHinh(string Data);

string Data;
int sl;
int main()
{
    ham_DocTapTin(Data); // D:\TXT\DoiChu.txt
    //ham_DoiChu(Data);
    ham_DoiChuVaInRaManHinh(Data);

    system("pause");
    return 0;
}

void ham_DocTapTin(string &Data)
{
    ifstream docFile;
    /*string AdressDoc;
	cout << "Nhap dia chi tap tin ban muon doc: ";
	fflush(stdin);
	cin >> AdressDoc;*/

    docFile.open("D:\\TXT\\DoiChu.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, Data);
            cout << Data << endl;
        }
    }
    else
        cout << "\nKhong mo duoc File";
    docFile.close();
}

void ham_DoiChu(string &Data, string TimKiem, string ThayDoi)
{
    int dem = 0, KQ;
    for (int i = 0; i < TimKiem.length(); i++)
    {
        dem++;
    }
    for (int i = 0; i < Data.length(); i++)
    {
        KQ = Data.find(TimKiem, 0);
        if (KQ >= 0)
        {
            Data.replace(KQ, dem, ThayDoi);
        }
    }
}

void ham_DoiChuVaInRaManHinh(string Data)
{
    ifstream docFile;
    docFile.open("D:\\TXT\\DoiChu.txt", ios::in);
    if (docFile.is_open())
    {
        string TimKiem, ThayDoi;
        cout << "\nNhap chu ban muon doi: ";
        getline(cin, TimKiem);
        cout << "\nBan muon doi chu " << TimKiem << " thanh chu nao: ";
        fflush(stdin);
        getline(cin, ThayDoi);
        while (docFile.eof() == false)
        {
            getline(docFile, Data);
            ham_DoiChu(Data, TimKiem, ThayDoi);
            cout << Data << endl;
        }
    }
    else
        cout << "\nKhong mo duoc File";
    docFile.close();
}