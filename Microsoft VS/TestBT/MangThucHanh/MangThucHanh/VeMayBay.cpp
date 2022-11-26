#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX = 100;
void ham_VeThuongGia(string MayBay[MAX][MAX]);
void ham_Xuat(string a[MAX][MAX], int ROW, int COL);
void ham_VePhoThong(string MayBay[MAX][MAX]);
void ham_VeTietKiem(string MayBay[MAX][MAX]);
void ham_MENU(int &LoaiVe);

string MayBay[MAX][MAX] =
    {
        {"*", "*", "x", "*", "x", "x"},
        {"*", "x", "*", "x", "*", "x"},
        {"*", "*", "x", "x", "*", "x"},
        {"x", "x", "x", "*", "x", "x"},
        {"*", "x", "*", "x", "*", "*"},
        {"*", "x", "*", "*", "*", "x"},
        {"x", "*", "*", "*", "x", "x"},
        {"*", "*", "x", "*", "x", "x"},
        {"x", "*", "x", "x", "*", "*"},
        {"*", "x", "*", "x", "x", "x"},
        {"*", "*", "x", "*", "x", "*"},
        {"*", "*", "x", "x", "*", "x"},
        {"*", "*", "*", "*", "x", "*"},
};

int main()
{
    int ROW = 13;
    int COL = 6;
    int LoaiVe;

    do
    {
        system("cls");
        ham_Xuat(MayBay, ROW, COL);
        ham_MENU(LoaiVe);

        if (LoaiVe == 1)
        {
            ham_VeThuongGia(MayBay);
        }

        if (LoaiVe == 2)
        {
            ham_VePhoThong(MayBay);
        }

        if (LoaiVe == 3)
        {
            ham_VeTietKiem(MayBay);
        }

        if (LoaiVe == 4)
        {
            cout << "\n\t========================* KET THUC *========================\n";
            break;
        }

        cout << "\n\n\tNhan phim bat ki de cap nhat lai so do may bay!!\n";
        system("pause");

    } while (1);

    system("pause");
    return 0;
}

void ham_Xuat(string a[MAX][MAX], int ROW, int COL)
{
    cout << "\n\n\t\t\t==== SO DO MAY BAY ====\n\n";

    cout << " Day Ghe     ";
    for (int i = 0; i < COL; i++)
    {
        cout << setw(8) << "Ghe (" << i + 1 << ")";
    }
    cout << endl
         << endl;

    for (int i = 0; i < ROW; i++)
    {
        cout << " Hang (" << i + 1 << ")";
        for (int j = 0; j < COL; j++)
        {
            cout << setw(10) << a[i][j];
        }
        cout << endl
             << endl;
    }

    cout << "\t\t\t==== SO DO MAY BAY ====\n\n";
}

void ham_VeThuongGia(string MayBay[MAX][MAX])
{
    int hang, ghe;
    cout << "\n\tHANG THUONG GIA";
    cout << "\nBan muon ngoi vi tri nao?";
    do
    {
        cout << "\nNhap hang (1 - 2): ";
        cin >> hang;

    } while (hang < 1 || hang > 2);

    do
    {
        cout << "Nhap ghe (1 - 6): ";
        cin >> ghe;

    } while (ghe < 1 || ghe > 6);

    if (MayBay[hang - 1][ghe - 1] != "x")
    {
        MayBay[hang - 1][ghe - 1] = "x";
        cout << "\nChon vi tri thanh cong!\nGhe cua ban la hang so (" << hang << ") va ghe so (" << ghe << ")";
    }
    else
        cout << "\nGhe o hang so (" << hang << ") va ghe so (" << ghe << ") !!! DA CO NGUOI DAT CHO !!!, VUI LONG CHON GHE LAI!";
}

void ham_VePhoThong(string MayBay[MAX][MAX])
{
    int hang, ghe;
    cout << "\n\tHANG PHO THONG";
    cout << "\nBan muon ngoi vi tri nao?";
    do
    {
        cout << "\nNhap hang (3 - 7): ";
        cin >> hang;

    } while (hang < 3 || hang > 7);

    do
    {
        cout << "Nhap ghe (1 - 6): ";
        cin >> ghe;

    } while (ghe < 1 || ghe > 6);

    if (MayBay[hang - 1][ghe - 1] != "x")
    {
        MayBay[hang - 1][ghe - 1] = "x";
        cout << "\nChon vi tri thanh cong!\nGhe cua ban la hang so (" << hang << ") va ghe so (" << ghe << ")";
    }
    else
        cout << "\nGhe o hang so (" << hang << ") va ghe so (" << ghe << ") !!! DA CO NGUOI DAT CHO !!!, VUI LONG CHON GHE LAI!";
}

void ham_VeTietKiem(string MayBay[MAX][MAX])
{
    int hang, ghe;
    cout << "\n\tHANG TIET KIEM";
    cout << "\nBan muon ngoi vi tri nao?";
    do
    {
        cout << "\nNhap hang (8 - 13): ";
        cin >> hang;

    } while (hang < 8 || hang > 13);

    do
    {
        cout << "Nhap ghe (1 - 6): ";
        cin >> ghe;

    } while (ghe < 1 || ghe > 6);

    if (MayBay[hang - 1][ghe - 1] != "x")
    {
        MayBay[hang - 1][ghe - 1] = "x";
        cout << "\nChon vi tri thanh cong!\nGhe cua ban la hang so (" << hang << ") va ghe so (" << ghe << ")";
    }
    else
        cout << "\nGhe o hang so (" << hang << ") va ghe so (" << ghe << ") !!! DA CO NGUOI DAT CHO !!!, VUI LONG CHON GHE LAI!";
}

void ham_MENU(int &LoaiVe)
{
    cout << "\t=====# Dau '*' la con trong | dau 'x' la da het cho #=====\n\n ";
    cout << "\t\t\tBan muon di loai ve nao?";
    cout << "\n\t\t Chon (1) la hang thuong gia (hang 1 - 2)";
    cout << "\n\t\t Chon (2) la hang pho thong (hang 3 - 7)";
    cout << "\n\t\t Chon (3) la hang tiet kiem (hang 8 - 13)";
    cout << "\n\t\t Chon (4) neu ban muon dung lai\n";

    do
    {
        cout << "\n\t\t Nhap loai hang ghe (1 - 4): ";
        cin >> LoaiVe;

    } while (LoaiVe < 1 || LoaiVe > 4);
}