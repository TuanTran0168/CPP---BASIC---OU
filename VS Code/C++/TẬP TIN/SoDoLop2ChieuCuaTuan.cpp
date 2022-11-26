#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAX = 100;

void ham_DocThongTinTuTapTin(int &row, int &col);
void ham_InSoDoLop(int row, int col);
void ham_InRaDayK(int &K);
void ham_InRaHangL(int &L);
int ham_SoChoTrong(int row, int col);
void ham_InRaTenSinhVienKhongCoAiNgoiCanh(int row, int col);
void ham_InRaTenSinhVienKhongCoAiNgoiTrenVaDuoi(int row, int col);
void ham_InRaTenSinhVienTheoViTri(int &Dong, int &Cot);
void ham_DoiCho2SinhVien(int &Dong1, int &Cot1, int &Dong2, int &Cot2);
void ham_TimSinhVienTheoChuNhapVao(int col, int row, string &KyTu);
//int ham_TimSinhVienTheoChuNhapVaoTEST(int col, int row, string &KyTu);
void ham_MENU(int &luachon);

int row, col, luachon, check;
string tieude;
string SoDoLop[MAX + 1][MAX + 1];

int main()
{
    system("cls"); // Xóa mấy cái linh tinh trên terminal của Visual Studio Code
    ham_DocThongTinTuTapTin(row, col);
    do
    {
        ham_InSoDoLop(row, col);
        ham_MENU(luachon);
        if (luachon == 1)
        {
            int K;
            ham_InRaDayK(K);
        }

        if (luachon == 2)
        {
            int L;
            ham_InRaHangL(L);
        }

        if (luachon == 3)
        {
            cout << "\nSo luong cho trong la: " << ham_SoChoTrong(row, col);
        }

        if (luachon == 4)
        {
            ham_InRaTenSinhVienKhongCoAiNgoiCanh(row, col);
        }

        if (luachon == 5)
        {
            ham_InRaTenSinhVienKhongCoAiNgoiTrenVaDuoi(row, col);
        }

        if (luachon == 6)
        {
            int Dong, Cot;
            ham_InRaTenSinhVienTheoViTri(Dong, Cot);
        }

        if (luachon == 7)
        {
            int Dong1, Cot1, Dong2, Cot2;
            ham_DoiCho2SinhVien(Dong1, Cot1, Dong2, Cot2);
        }

        if (luachon == 8)
        {
            string KyTu;
            ham_TimSinhVienTheoChuNhapVao(col, row, KyTu);
        }

        if (luachon == 0)
        {
            system("cls");
            cout << "\n\n\t\t==========================* KET THUC *==========================\n";
            break;
        }

        cout << "\n\nBan co muon lam tiep khong???\n1.Co\n0.Khong";
        cout << "\nNhap: ";
        cin >> check;
        system("cls");

    } while (check != 0);

    system("cls");
    cout << "\n\n\t\t==========================* KET THUC *==========================\n";

    system("pause");
    return 0;
}

void ham_DocThongTinTuTapTin(int &row, int &col)
{
    ifstream docFile;
    docFile.open("D:\\TXT\\SoDoLopNew.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!\n";
        while (docFile.eof() == false)
        {
            getline(docFile, tieude);
            docFile >> row;
            docFile.ignore(1);
            docFile >> col;
            docFile.ignore(1);

            for (int i = 1; i <= row; i++)
            {
                for (int j = 1; j <= col; j++)
                {
                    if (j == col)
                        getline(docFile, SoDoLop[i][j]);
                    else
                        getline(docFile, SoDoLop[i][j], ',');
                }
            }
        }
    }
    else
    {
        cout << "\nMo khong duoc tap tin";
    }
}

void ham_InSoDoLop(int row, int col)
{
    cout << "\t\t\tSO DO LOP\n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << SoDoLop[i][j] << "\t";
        }
        cout << endl;
    }
}

void ham_InRaDayK(int &K) //Dãy = cả 1 cột (col)
{
    do
    {
        cout << "\nNhap day thu K: ";
        cin >> K;
    } while (K < 1 || K > col);

    for (int i = 1; i <= row; i++)
    {
        if (SoDoLop[i][K] != "X")
        {
            cout << SoDoLop[i][K] << endl;
        }
    }
}

void ham_InRaHangL(int &L) //Hàng = cả 1 dòng (row)
{
    do
    {
        cout << "\nNhap dong thu L: ";
        cin >> L;
    } while (L < 1 || L > row);

    for (int j = 1; j <= col; j++)
    {
        if (SoDoLop[L][j] != "X")
        {
            cout << SoDoLop[L][j] << "\t";
        }
    }
}

int ham_SoChoTrong(int row, int col)
{
    int dem = 0;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (SoDoLop[i][j] == "X")
                dem++;
        }
    }
    return dem;
}

void ham_InRaTenSinhVienKhongCoAiNgoiCanh(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if ((SoDoLop[i][j - 1] == "X" && SoDoLop[i][j + 1] == "X") || (j == 1 && SoDoLop[i][j + 1] == "X") || (j == col && SoDoLop[i][j - 1] == "X"))
            {
                if (SoDoLop[i][j] != "X")
                {
                    cout << SoDoLop[i][j] << "\t";
                }
            }
        }
    }
}

void ham_InRaTenSinhVienKhongCoAiNgoiTrenVaDuoi(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if ((SoDoLop[i - 1][j] == "X" && SoDoLop[i + 1][j] == "X") || (i == 1 && SoDoLop[i + 1][j] == "X") || (i == row && SoDoLop[i - 1][j] == "X"))
            {
                if (SoDoLop[i][j] != "X")
                {
                    cout << SoDoLop[i][j] << "\t";
                }
            }
        }
    }
}

void ham_InRaTenSinhVienTheoViTri(int &Dong, int &Cot)
{
    do
    {
        cout << "\nNhap dong: ";
        cin >> Dong;
    } while (Dong < 1 || Dong > col);

    do
    {
        cout << "Nhap cot: ";
        cin >> Cot;
    } while (Cot < 1 || Cot > row);

    if (SoDoLop[Dong][Cot] != "X")
    {
        cout << "Ban ngoi o vi tri [" << Dong << "][" << Cot << "] la: " << SoDoLop[Dong][Cot];
    }
    else
        cout << "\nCho ngoi con trong\n";
}

void ham_DoiCho2SinhVien(int &Dong1, int &Cot1, int &Dong2, int &Cot2)
{
    cout << "\nNhap vi tri hoc sinh 1: ";
    do
    {
        cout << "\nNhap dong: ";
        cin >> Dong1;
        cout << "Nhap cot: ";
        cin >> Cot1;

    } while (Dong1 < 1 || Dong1 > col || Cot1 < 1 || Cot1 > col);

    cout << "\nNhap vi tri hoc sinh 2: ";
    do
    {
        cout << "\nNhap dong: ";
        cin >> Dong2;
        cout << "Nhap cot: ";
        cin >> Cot2;

    } while (Dong2 < 1 || Dong2 > col || Cot2 < 1 || Cot2 > col);

    string temp = SoDoLop[Dong1][Cot1];
    SoDoLop[Dong1][Cot1] = SoDoLop[Dong2][Cot2];
    SoDoLop[Dong2][Cot2] = temp;

    cout << "\n\tSo do lop sau khi doi cho " << SoDoLop[Dong1][Cot1] << " va " << SoDoLop[Dong2][Cot2] << "\n\n";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout << SoDoLop[i][j] << "\t";
        }
        cout << endl;
    }
}

void ham_TimSinhVienTheoChuNhapVao(int col, int row, string &KyTu)
{
    cout << "Nhap ky tu: ";
    cin >> KyTu;
    cout << "Nhung ban trong ten co ky tu: " << KyTu << " la: ";
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            int KQ = SoDoLop[i][j].find(KyTu, 0);
            if (KQ >= 0)
            {
                cout << SoDoLop[i][j] << "\t";
            }
        }
    }
}

//int ham_TimSinhVienTheoChuNhapVaoTEST(int col, int row, string &KyTu)
//{
//	int dem = 0;
//	cout << "Nhap ky tu: ";
//	cin >> KyTu;
//	for (int i = 1; i <= row; i++)
//	{
//		for (int j = 1; j <= col; j++)
//		{
//			int KQ = SoDoLop[i][j].find(KyTu, 0);
//			if(KQ >= 0)
//			{
//				cout << SoDoLop[i][j] << " ";
//				dem++;
//			}
//		}
//	}
//	return dem;
//}

void ham_MENU(int &luachon)
{
    cout << "\n\t\t==========================* MENU LUA CHON *==========================\n";
    cout << "\n1.In ra toan bo sinh vien ngoi o day ban K nhap tu ban phim";
    cout << "\n2.In ra toan bo sinh vien ngoi o hang L nhap tu ban phim";
    cout << "\n3.In ra so luong cho trong";
    cout << "\n4.In ra toan bo ten sinh vien khong co ai ngoi canh";
    cout << "\n5.In ra toan bo ten sinh vien khong co ai ngoi tren va duoi";
    cout << "\n6.Nhap vi tri dong va cot, sau do in ra ten sinh vien ngoi vi tri do";
    cout << "\n7.Doi cho 2 sinh vien ma ban muon bang cach nhap vi tri";
    cout << "\n8.Nhap ky tu, sau do in ra toan bo sinh vien co ten bang ky tu nhap vao";
    cout << "\n0.KET THUC CHUONG TRINH";
    cout << endl;
    do
    {
        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;
    } while (luachon < 0 || luachon > 8);
}