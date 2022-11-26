#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 100;
const int maxHang = 10;
const int maxCot = 7;
int SLSV = 0;
struct SV
{
    string MSSV;
    string hoLot;
    string ten;
    string date;
    string nganh;
    string que;
};

SV *DSSV;
string **SoDo;
void cpd1Chieu();
void cpd2Chieu();
void nhap();
void xuat();
void testMotXiu();

int main()
{
    cpd1Chieu();
    cpd2Chieu();

    nhap();
    xuat();
    testMotXiu();
}
void cpd1Chieu()
{
    DSSV = new SV[MAX];

    /*for (int i = 0; i < MAX; i++)
        DSSV[i].ten = "Phu Man";

    for (int i = 0; i < MAX; i++)
        cout << DSSV[i].ten << "\n";*/
}
void cpd2Chieu()
{
    SoDo = new string *[maxHang];
    for (int i = 0; i < maxHang; i++)
        SoDo[i] = new string[maxCot];

    /* SoDo[5][2] = "99";
     SoDo[2][5] = "99";
     SoDo[9][6] = "99";*/

    /*for (int i = 0; i < maxHang; i++)
    {
        for (int j = 0; j < maxCot; j++)
        {
            SoDo[i][j] = "1";
        }
    }*/
}
void nhap()
{
    ifstream DocFile;
    DocFile.open("E:\\MicrosoftVisualStudio2022\\CodeCuaTuan\\HelloCPP\\SoDoLop.txt", ios::in);
    if (DocFile.is_open())
    {
        while (!DocFile.eof())
        {
            int day, o;
            DocFile >> day; // cột
            DocFile.ignore(1);
            DocFile >> o; // dòng
            DocFile.ignore(1);

            cout << o << " " << day << endl;

            getline(DocFile, DSSV[SLSV].MSSV, ',');
            SoDo[o - 1][day - 1] = DSSV[SLSV].MSSV;
            /*SoDo[1][2] = DSSV[1].MSSV;*/
            getline(DocFile, DSSV[SLSV].hoLot, ',');
            getline(DocFile, DSSV[SLSV].ten, ',');
            getline(DocFile, DSSV[SLSV].date, ',');
            getline(DocFile, DSSV[SLSV].nganh, ',');
            getline(DocFile, DSSV[SLSV].que);
            SLSV++;
        }
        DocFile.close();
    }
    else
        cout << "Khong mo duoc file\n";
}

void xuat()
{
    for (int i = 0; i < SLSV; i++)
    {
        cout << "THONG TIN SINH VIEN THU " << i + 1 << endl;
        cout << "MSSV: " << DSSV[i].MSSV << endl;
        cout << "Ho ten: " << DSSV[i].hoLot << " " << DSSV[i].ten << endl;
        cout << "Ngay sinh: " << DSSV[i].date << endl;
        cout << "Nganh: " << DSSV[i].nganh << endl;
        cout << "Que quan: " << DSSV[i].que << endl;
        cout << "-----------------------------------------------------------------------\n";
    }
    cout << "IN SO DO LOP\n";
    for (int i = 0; i < maxHang; i++)
    {
        for (int j = 0; j < maxCot; j++)
        {
            cout << SoDo[i][j] << "   ";
        }
        cout << endl;
    }
}

void testMotXiu()
{
    cout << "\nTEST\n";
    for (int i = 0; i < SLSV; i++)
        cout << DSSV[i].MSSV << " ok" << endl;
}