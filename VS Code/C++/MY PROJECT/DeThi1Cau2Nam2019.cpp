#include <iostream>
#include <fstream>
#include <string>
// ĐỀ THI NĂM 2019 :)
using namespace std;
void ham_NhapMotCuonSach(struct SACH &a);
void ham_NhapNhieuCuonSach(struct SACH *&a, int n);
void ham_XuatMotCuonSach(struct SACH a);
void ham_XuatNhieuCuonSach(struct SACH *DS, int n);
void ham_SapXepSachTheoNamTangDan(struct SACH *DS, int n);
int ham_DemSoSachCoNamXuatBan2019(struct SACH *DS, int n);
void ham_DocFileVaoStruct(struct SACH *&DS, int &sl);
void ham_MENU(int &select);

struct SACH
{
    string MaSach;
    string TenSach;
    int NamXuatBan;
};

int select, sl, n, check;

int main()
{
    do
    {
        system("cls");
        ham_MENU(select);

        if (select == 1)
        {
            cout << "\nBan muon nhap bao nhieu cuon sach: ";
            cin >> n;
            SACH *DS = new SACH[n];
            ham_NhapNhieuCuonSach(DS, n);

            ham_SapXepSachTheoNamTangDan(DS, n);
            ham_XuatNhieuCuonSach(DS, n);

            delete[] DS;
        }

        else if (select == 2)
        {
            cout << "\nBan muon nhap bao nhieu cuon sach: ";
            cin >> n;
            SACH *DS = new SACH[n];
            ham_NhapNhieuCuonSach(DS, n);

            cout << "\nSo sach xuat ban nam 2019 la: " << ham_DemSoSachCoNamXuatBan2019(DS, n);

            delete[] DS;
        }

        else if (select == 3)
        {
            SACH *DS1;
            ham_DocFileVaoStruct(DS1, sl);
            ham_XuatNhieuCuonSach(DS1, sl);

            delete[] DS1;
        }

        else if (select == 4)
        {
            cout << "\n\t===========================* END *===========================\n";
            break;
        }

        cout << "\n\tBam phim bat ki de tiep tuc!\n";
        system("pause");

    } while (1);

    system("pause");
    return 0;
}

void ham_NhapMotCuonSach(struct SACH &a)
{
    fflush(stdin);
    cout << "\nNhap ma sach: ";
    getline(cin, a.MaSach);
    cout << "Nhap ten sach: ";
    getline(cin, a.TenSach);
    cout << "Nhap nam xuat ban: ";
    cin >> a.NamXuatBan;
}

void ham_NhapNhieuCuonSach(struct SACH *&DS, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNhap cuon sach thu (" << i << "): ";
        ham_NhapMotCuonSach(DS[i]);
    }
}

void ham_XuatMotCuonSach(struct SACH a)
{
    cout << "\nMa sach: " << a.MaSach;
    cout << "\nTen sach: " << a.TenSach;
    cout << "\nNam xuat ban: " << a.NamXuatBan;
    cout << endl;
}

void ham_XuatNhieuCuonSach(struct SACH *DS, int n)
{
    cout << "\n\tDANH SACH CAC CUON SACH\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\n\tCuon sach thu (" << i << "): ";
        ham_XuatMotCuonSach(DS[i]);
    }
}

void ham_SapXepSachTheoNamTangDan(struct SACH *DS, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (DS[i].NamXuatBan > DS[j].NamXuatBan)
            {
                SACH temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

int ham_DemSoSachCoNamXuatBan2019(struct SACH *DS, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (DS[i].NamXuatBan == 2019)
        {
            count++;
        }
    }

    return count;
}

void ham_DocFileVaoStruct(struct SACH *&DS, int &sl)
{
    sl = 0;
    DS = new SACH[20];
    ifstream docFile;
    docFile.open("D:\\TXT\\DeThi1.txt", ios::in);

    if (docFile.is_open())
    {
        cout << "\nMo thanh cong!!!";

        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].MaSach, '#');
            getline(docFile, DS[sl].TenSach, '#');
            docFile >> DS[sl].NamXuatBan;
            docFile.ignore(1);
            sl++;
        }

        docFile.close();
    }
    else
        cout << "\nKhong mo duoc!!!";
}

void ham_MENU(int &select)
{
    cout << "\n\t===========================* MENU *===========================\n";
    cout << "\n1. Sap xep sach theo nam xuat ban tang dan";
    cout << "\n2. Dem so sach co nam xuat ban 2019";
    cout << "\n3. Doc du lieu tu File vao struct";
    cout << "\n4. Ket thuc chuong trinh";

    cout << "\n\nBan chon cau nao?";
    do
    {
        cout << "\nNhap: ";
        cin >> select;

    } while (select < 1 || select > 4);
}