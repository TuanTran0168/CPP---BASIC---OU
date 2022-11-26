#include <iostream>
#include <fstream>
#include <string>
#define MAX 4000
using namespace std;
ifstream docFile;
int SLSV = 0;
string chucaidau[MAX];
struct SV
{
    string MSSV,
        Holot,
        Ten,
        Birthday,
        Nganh,
        Que;
} tt[MAX];
void moTaptin()
{
    docFile.open("E:\\TXT\\TTsv.txt", ios::in);
    if (docFile.is_open())
    {
        while (!docFile.eof())
        {
            getline(docFile, tt[SLSV].MSSV, ',');
            getline(docFile, tt[SLSV].Holot, ',');
            getline(docFile, tt[SLSV].Ten, ',');
            getline(docFile, tt[SLSV].Birthday, ',');
            getline(docFile, tt[SLSV].Nganh, ',');
            getline(docFile, tt[SLSV].Que);
            SLSV++;
        }
        docFile.close();
    }
    else
        cout << "Khong mo duoc file\n";
}
void HoanDoi(SV &to1, SV &to2)
{
    SV temp = to1;
    to1 = to2;
    to2 = temp;
}
void Sapxepalaphabet()
{
    int i = 0;
    while (i < SLSV)
    {
        chucaidau[i] = tt[i].Ten.substr(0, 1);
        i++;
        // cout << "Lap Vo Tan";
    }
    // cout << chucaidau[0];
    for (int j = 0; j < SLSV - 1; j++)
    {
        for (int k = j + 1; k < SLSV; k++)
        {
            if (chucaidau[j] > chucaidau[k])
            {
                swap(chucaidau[j], chucaidau[k]);
                HoanDoi(tt[j], tt[k]);
            }
        }
    }
}

void xuat()
{
    int i = 0;
    while (i < SLSV)
    {
        cout << tt[i].MSSV << "," << tt[i].Holot << " " << tt[i].Ten << "," << tt[i].Birthday << "," << tt[i].Nganh << "," << tt[i].Que << endl;
        i++;
    }
}

void sapXep()
{
    for (int i = 0; i < SLSV - 1; i++)
    {
        for (int j = i + 1; j < SLSV; j++)
        {
            if (tt[i].Ten[0] > tt[j].Ten[0])
                HoanDoi(tt[i], tt[j]);
        }
    }
}

void hienThi()
{
    for (int i = 0; i < SLSV; i++)
    {
        cout << tt[i].Ten[0] << endl;
    }
}
int main()
{
    moTaptin();
    cout << "Cac sinh vien duoc sap xep theo alphabet" << endl;
    Sapxepalaphabet();
    hienThi();
    /*xuat();*/

    /*sapXep();
    hienThi();*/

    /*cout << tt[1].Ten << endl;
    cout << tt[1].Ten[0];*/

    cout << endl;
}