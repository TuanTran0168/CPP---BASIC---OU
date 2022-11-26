#include <iostream>
#include <fstream>
#include <string>
//ĐỀ THI NĂM 2019
using namespace std;
void ham_NhapMotPhongBan(struct PhongBan &a);
void ham_XuatMotPhongBan(struct PhongBan a);
void ham_NhapNhieuPhongBan(struct PhongBan *&DS, int &n);
void ham_XuatNhieuPhongBan(struct PhongBan *DS, int n);
int ham_ViTriPhongCoSoNhanVienMax(struct PhongBan *DS, int n);
void ham_XuatThongTinPhongHon100NV(struct PhongBan *DS, int n);
void ham_GhiThongTinFILE(struct PhongBan *DS, int n);
void ham_MENU(int &select);

struct PhongBan
{
    string MaPhong;
    string TenPhong;
    int SoLuongNV;
};

int main()
{
    PhongBan *DS;
    int n, select;

    ham_NhapNhieuPhongBan(DS, n);

    do
    {
        system("cls");
        ham_XuatNhieuPhongBan(DS, n);
        ham_MENU(select);

        if (select == 1)
        {
            cout << "\nVi tri phong co so luong nhan vien lon nhat la: " << ham_ViTriPhongCoSoNhanVienMax(DS, n);
        }

        if (select == 2)
        {
            ham_XuatThongTinPhongHon100NV(DS, n);
        }

        if (select == 3)
        {
            ham_GhiThongTinFILE(DS, n);
        }

        if (select == 4)
        {
            cout << "\n\t===========================* END *===========================\n";
            break;
        }

        cout << "\nNhan phim bat ki de tiep tuc!!!\n";
        system("pause");

    } while (1);

    delete[] DS;
    system("pause");
    return 0;
}

void ham_NhapMotPhongBan(struct PhongBan &a)
{
    fflush(stdin);
    cout << "\nNhap ma phong: ";
    getline(cin, a.MaPhong);
    cout << "Nhap ten phong: ";
    getline(cin, a.TenPhong);
    cout << "Nhap so luong nhan vien: ";
    cin >> a.SoLuongNV;
}

void ham_XuatMotPhongBan(struct PhongBan a)
{
    cout << "\nMa phong: " << a.MaPhong;
    cout << "\nTen phong: " << a.TenPhong;
    cout << "\nSo luong nhan vien: " << a.SoLuongNV;
    cout << endl;
}

void ham_NhapNhieuPhongBan(struct PhongBan *&DS, int &n)
{
    cout << "Nhap so phong ban: ";
    cin >> n;
    DS = new PhongBan[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNhap phong ban thu (" << i << "): ";
        ham_NhapMotPhongBan(DS[i]);
    }
}

void ham_XuatNhieuPhongBan(struct PhongBan *DS, int n)
{
    cout << "\n\t\tDANH SACH CAC PHONG BAN!\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tPhong ban thu (" << i << "): ";
        ham_XuatMotPhongBan(DS[i]);
    }
}

int ham_ViTriPhongCoSoNhanVienMax(struct PhongBan *DS, int n)
{
    int MAX = DS[0].SoLuongNV;
    int vitri = 0;

    for (int i = 0; i < n; i++)
    {
        if (DS[i].SoLuongNV > MAX)
        {
            MAX = DS[i].SoLuongNV;
            vitri = i;
        }
    }

    return vitri;
}

void ham_XuatThongTinPhongHon100NV(struct PhongBan *DS, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (DS[i].SoLuongNV > 100)
        {
            ham_XuatMotPhongBan(DS[i]);
            count++;
        }
    }

    if (count == 0)
    {
        cout << "\nKhong co phong ban nao co hon 100 nhan vien!!!\n";
    }
}

void ham_GhiThongTinFILE(struct PhongBan *DS, int n)
{
    ofstream ghiFile;
    ghiFile.open("D:\\TXT\\De3OUT.txt", ios::out);

    if (ghiFile.is_open())
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (DS[i].SoLuongNV > 100)
            {
                ghiFile << DS[i].MaPhong << "@" << DS[i].TenPhong << "@" << DS[i].SoLuongNV << endl;
                count++;
            }
        }

        if (count == 0)
        {
            ghiFile << "Khong co phong ban nao co hon 100 nhan vien!!!\n";
        }
    }

    ghiFile.close();

    cout << "\nGhi thanh cong!!!";
}

void ham_MENU(int &select)
{
    cout << "\n\t===========================* MENU *===========================\n";
    cout << "\n1. Tra ve vi tri phong co so nhan vien lon nhat";
    cout << "\n2. Hien thi thong tin phong ban co so nhan vien > 100";
    cout << "\n3. Ghi thong tin phong ban vao FILE co so nhan vien > 100 va moi thong tin cach nhau dau '@'";
    cout << "\n4. Ket thuc chuong trinh";

    cout << "\n\nBan chon cau nao?";
    do
    {
        cout << "\nNhap: ";
        cin >> select;

    } while (select < 1 || select > 4);
}