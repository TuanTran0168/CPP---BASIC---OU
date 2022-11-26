#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ham_DocTapTin(int &dong, int &cot);
void ham_MENU(int &luachon);
void ham_InHocSinhDayk(int K);
int ham_CoBaoNhieuChoTrong(int dong, int cot);
void ham_InRatenHocSinhNgoiTrong2Ben(int dong, int cot);
void ham_InRatenHocSinhNgoiKhongCoAiNgoiTrenVaDuoi(int dong, int cot);

const int MAX = 100;
int dong, cot, luachon, K, check;
ifstream docFile;
string tieude, rac;
string SoDoLop[MAX][MAX];

int main()
{
    system("cls"); // Xóa mấy cái linh tinh trên terminal của Visual Studio Code
    ham_DocTapTin(dong, cot);
    do
    {
        ham_MENU(luachon);
        if (luachon == 1)
        {
            ham_InHocSinhDayk(K);
        }
        if (luachon == 2)
        {
            cout << "\nSo cho trong la: " << ham_CoBaoNhieuChoTrong(dong, cot);
        }
        if (luachon == 3)
        {
            cout << "\nHoc sinh ngoi mot minh la: ";
            ham_InRatenHocSinhNgoiTrong2Ben(dong, cot);
        }
        if (luachon == 4)
        {
            cout << "\nHoc sinh ngoi khong co ai ngoi tren va duoi la: ";
            ham_InRatenHocSinhNgoiKhongCoAiNgoiTrenVaDuoi(dong, cot);
        }
        if (luachon == 5)
        {
            cout << "\n=============KET THUC===============\n";
            break;
        }
        cout << "\n\nBan co muon lam tiep khong?\n1.Co\n.Khong";
        cout << "\nNhap: ";
        cin >> check;
        system("cls");

    } while (check != 0);

    system("pause");
    return 0;
}

void ham_DocTapTin(int &dong, int &cot)
{
    ifstream docFile;
    docFile.open("D:\\TXT\\SoDoLop.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "\nMo thanh cong!!!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, tieude);
            docFile >> dong;
            docFile.ignore(1);
            docFile >> cot;
            for (int i = 1; i <= dong; i++)
            {
                for (int j = 1; j <= cot; j++)
                {
                    if (j == cot)
                        getline(docFile, SoDoLop[i][j]);
                    else
                        getline(docFile, SoDoLop[i][j], ',');
                }
            }
        }
        docFile.close();
    }
    else
        cout << "\nKhong mo duoc";
}

void ham_MENU(int &luachon)
{
    cout << "\n =========MENU===============\n";
    cout << "\n1. Nhap so K: In ra ten hoc sinh day K";
    cout << "\n2.Co bao nhieu cho trong trong lop";
    cout << "\n3.In ra ten hoc sinh khong co ai ngoi ben";
    cout << "\n4.In ra ten hoc sinh khong co ai ngoi truoc va sau";
    cout << "\n5.Ket thuc chuong trinh";
    cout << "\n\nNhap lua chon cua ban: ";
    cin >> luachon;
}

void ham_InHocSinhDayk(int K)
{
    cout << "\nNhap day K: ";
    cin >> K;
    for (int i = 1; i <= cot; i++)
    {
        cout << SoDoLop[K][i] << " ";
    }
}

int ham_CoBaoNhieuChoTrong(int dong, int cot)
{
    int dem = 0;
    for (int i = 1; i <= dong; i++)
    {
        for (int j = 1; j <= cot; j++)
        {
            if (SoDoLop[i][j] == "X")
            {
                dem++;
            }
        }
    }
    return dem;
}

void ham_InRatenHocSinhNgoiTrong2Ben(int dong, int cot)
{
    for (int i = 1; i <= dong; i++)
    {
        for (int j = 1; j <= cot; j++)
        {
            if ((SoDoLop[i][j - 1] == "X" && SoDoLop[i][j + 1] == "X") || ((j == 1 && SoDoLop[i][j + 1] == "X") || (j == cot && SoDoLop[i][j - 1] == "X")))
            {
                if (SoDoLop[i][j] != "X")
                {
                    cout << SoDoLop[i][j] << " ";
                }
            }
        }
    }
}

void ham_InRatenHocSinhNgoiKhongCoAiNgoiTrenVaDuoi(int dong, int cot)
{
    for (int i = 1; i <= dong; i++)
    {
        for (int j = 2; j <= cot; j++)
        {
            if (SoDoLop[i - 1][j] == "X" && SoDoLop[i + 1][j] == "X" || ((i == 1 && SoDoLop[i + 1][j] == "X") || (i == dong && SoDoLop[i - 1][j] == "X")))
            {
                if (SoDoLop[i][j] != "X")
                {
                    cout << SoDoLop[i][j] << " ";
                }
            }
        }
    }
}