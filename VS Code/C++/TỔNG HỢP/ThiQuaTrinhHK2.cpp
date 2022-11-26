#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
const int MAX = 200;
using namespace std;
void ham_DocTapTin(int &sl);
void ham_InRaMotSinhVien(int vitri);
void ham_InRaToanBoSinhVien(int sl);
void ham_InRaSinhVienTheoTinhThanh(int sl);
void ham_InRaSinhVienTheoDangTen(int sl);
void ham_InRaSinhVienTheoDangTen1(int sl);
void ham_MENU(int &luachon);

struct SinhVien
{
    string mssv;
    string holot;
    string ten;
    string quequan;
};

int sl, luachon, check;
string tieude;
SinhVien DS[MAX];

int main()
{
    ham_DocTapTin(sl);
    do
    {
        ham_MENU(luachon);

        if (luachon == 1)
        {
            ham_InRaToanBoSinhVien(sl);
        }

        if (luachon == 2)
        {
            ham_InRaSinhVienTheoTinhThanh(sl);
        }

        if (luachon == 3)
        {
            //ham_InRaSinhVienTheoDangTen(sl);
            ham_InRaSinhVienTheoDangTen1(sl);
        }

        if (luachon == 4)
        {
            cout << "\n\t=========================* KET THUC *=========================\n";
            break;
        }

        cout << "\nBan co muon lam tiep khong?\n1. Co\n0.Khong\n";
        cout << "\nNhap: ";
        cin >> check;
        system("cls");

    } while (check != 0);

    system("pause");
    return 0;
}

void ham_DocTapTin(int &sl)
{
    sl = 1;
    ifstream docFile;
    docFile.open("D:\\TXT\\ThiQuaTrinhHK2.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n";
        getline(docFile, tieude);
        while (docFile.eof() == false)
        {
            // Tập tin của thầy là dấu ;
            getline(docFile, DS[sl].mssv, ',');
            getline(docFile, DS[sl].holot, ',');
            getline(docFile, DS[sl].ten, ',');
            getline(docFile, DS[sl].quequan);
            sl++;
        }
        docFile.close();
    }
    else
    {
        cout << "\nKhong mo duoc!!!";
    }
}

void ham_InRaMotSinhVien(int vitri)
{
    cout << "\nMSSV: " << DS[vitri].mssv;
    cout << "\nHo va Ten: " << DS[vitri].holot << " " << DS[vitri].ten;
    cout << "\nQue quan: " << DS[vitri].quequan;
    cout << endl;
}

void ham_InRaToanBoSinhVien(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        ham_InRaMotSinhVien(i);
    }
}

void ham_InRaSinhVienTheoTinhThanh(int sl)
{
    string T;
    int dem = 0;
    cout << "\nNhap tinh thanh: ";
    fflush(stdin);
    getline(cin, T);

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].quequan == T)
        {
            ham_InRaMotSinhVien(i);
            dem++;
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay!\n";
    }
}

void ham_InRaSinhVienTheoDangTen(int sl)
{
    string Name;
    int dem = 0;
    cout << "\nNhap khuon dang ten: ";
    fflush(stdin);
    getline(cin, Name);

    for (int i = 1; i < sl; i++)
    {
        int KQ = DS[i].ten.find(Name, 0);
        {
            if (KQ >= 0)
            {
                ham_InRaMotSinhVien(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay!\n";
    }
}

void ham_InRaSinhVienTheoDangTen1(int sl)
{
    string Name;
    int dem = 0;
    int demsl = 0;
    cout << "\nNhap khuon dang ten: ";
    fflush(stdin);
    getline(cin, Name);

    for (int i = 0; i < Name.length(); i++)
    {
        demsl++;
    }

    for (int i = 1; i < sl; i++)
    {
        string S = DS[i].ten.substr(0, demsl);
        {
            if (S == Name)
            {
                ham_InRaMotSinhVien(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay!\n";
    }
}

void ham_MENU(int &luachon)
{
    cout << "\n\t=========================* MENU *=========================\n";
    cout << "\n1. In ra toan bo cac sinh vien trong danh sach";
    cout << "\n2. Nhap ten tinh thanh T, In ra tat ca sinh vien co que la T";
    cout << "\n3. Nhap khuon dang ten, In ra tat ca sinh vien co ten dang nhu da nhap";
    cout << "\n4. KET THUC\n";
    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> luachon;

    } while (luachon < 1 || luachon > 4);
}