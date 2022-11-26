#include <iostream>
#include <fstream>
#include <string>
const int MAX = 1000;
using namespace std;
void ham_DocTapTin(int &sl);
void ham_InRaMotSanPham(int vitri);
void ham_InToanBoSanPham(int sl);
void ham_InThongTinSanPhamTheoMaSP(int sl);
void ham_NhapThongTinMotSanPham(struct SANPHAM &x);
void ham_ThemVaoMotSanPham(int &sl, struct SANPHAM x, int &vitri);
void ham_XoaSanPham(int &sl, int vitri);
void ham_XoaSanPhamTheoMaSP(int &sl);
void ham_SapXepTenSanPhamTangDan(int sl);
void ham_SapXepSanPhamTheoGiaBanGiamDan(int sl);
void ham_InDanhSachSanPhamTheoKhoangGiaBanNhapVao(int sl);
void ham_InDanhSachSanPhamTheoKhoangGiaMuaNhapVao(int sl);
void ham_MENU(int &luachon);

struct SANPHAM
{
    string MaSP;
    string TenSP;
    string DVT;
    long long GiaMua;
    long long GiaBan;
};

SANPHAM DS[MAX + 1];
int sl, luachon, check;

int main()
{
    ham_DocTapTin(sl);
    do
    {
        ham_MENU(luachon);
        if (luachon == 1)
        {
            ham_InThongTinSanPhamTheoMaSP(sl);
        }

        if (luachon == 2)
        {
            SANPHAM x;
            int vitri;
            ham_ThemVaoMotSanPham(sl, x, vitri);
            ham_InToanBoSanPham(sl);
        }

        if (luachon == 3)
        {
            ham_XoaSanPhamTheoMaSP(sl);
            ham_InToanBoSanPham(sl);
        }

        if (luachon == 4)
        {
            ham_SapXepTenSanPhamTangDan(sl);
            ham_InToanBoSanPham(sl);
        }

        if (luachon == 5)
        {
            ham_SapXepSanPhamTheoGiaBanGiamDan(sl);
            ham_InToanBoSanPham(sl);
        }

        if (luachon == 6)
        {
            // Thích xài cái nào thì xài cái đó
            ham_InDanhSachSanPhamTheoKhoangGiaBanNhapVao(sl);
            //ham_InDanhSachSanPhamTheoKhoangGiaMuaNhapVao(sl);
        }

        if (luachon == 7)
        {

            cout << "\n=================* KET THUC *=================\n";
            break;
        }

        cout << "\nBan co muon lam tiep khong ?\n1.Co\n0.Khong";
        cout << "\nHay nhap: ";
        cin >> check;
        fflush(stdin);
        system("cls");

    } while (check != 0);

    system("pause");
    return 0;
}

void ham_DocTapTin(int &sl)
{
    ifstream docFile;
    sl = 1;
    docFile.open("D:\\TXT\\CodeDum2.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].MaSP, '#');
            getline(docFile, DS[sl].TenSP, '#');
            getline(docFile, DS[sl].DVT, '#');
            docFile >> DS[sl].GiaMua;
            docFile.ignore(1);
            docFile >> DS[sl].GiaBan;
            docFile.ignore(1);
            sl++;
        }
        docFile.close();
    }
    else
        cout << "\nKhong mo duoc";
}

void ham_InRaMotSanPham(int vitri)
{
    cout << "\nMa san pham: " << DS[vitri].MaSP;
    cout << "\nTen san pham: " << DS[vitri].TenSP;
    cout << "\nDon vi tinh: " << DS[vitri].DVT;
    cout << "\nGia mua: " << DS[vitri].GiaMua;
    cout << "\nGia ban: " << DS[vitri].GiaBan;
}

void ham_InToanBoSanPham(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        ham_InRaMotSanPham(i);
        cout << endl;
    }
}

void ham_InThongTinSanPhamTheoMaSP(int sl)
{
    string MSP;
    int dem = 0;
    cout << "\nNhap ma SP: ";
    cin >> MSP;

    for (int i = 1; i < sl; i++)
    {
        if (MSP == DS[i].MaSP)
        {
            ham_InRaMotSanPham(i);
            dem++;
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay san pham\n";
    }
}

void ham_NhapThongTinMotSanPham(struct SANPHAM &x)
{
    int dem;
    do
    {
        dem = 0;
        fflush(stdin);
        cout << "\nNhap ma SP: ";
        getline(cin, x.MaSP);

        for (int i = 1; i < sl; i++)
        {
            if (x.MaSP == DS[i].MaSP)
            {
                dem++;
            }
        }

        if (dem > 0)
        {
            cout << "\nMa SP da ton tai, vui long nhap lai";
        }
    } while (dem > 0);

    cout << "Nhap ten SP: ";
    getline(cin, x.TenSP);
    cout << "Nhap don vi tinh: ";
    getline(cin, x.DVT);
    cout << "Nhap gia mua: ";
    cin >> x.GiaMua;
    cout << "Nhap gia ban: ";
    cin >> x.GiaBan;
}

void ham_ThemVaoMotSanPham(int &sl, struct SANPHAM x, int &vitri)
{
    cout << "\nNhap vi tri ban muon them mot san pham: ";
    cin >> vitri;
    cout << "\nNhap thong tin san pham tai vi tri thu " << vitri;
    ham_NhapThongTinMotSanPham(x);

    for (int i = sl; i >= vitri; i--)
    {
        DS[i + 1] = DS[i];
    }
    DS[vitri] = x;
    sl++;
}

void ham_XoaSanPham(int &sl, int vitri)
{
    for (int i = vitri; i < sl; i++)
    {
        DS[i] = DS[i + 1];
    }
    sl--;
}

void ham_XoaSanPhamTheoMaSP(int &sl)
{
    string MaSP;
    cout << "\nNhap ma SP ban muon xoa: ";
    cin >> MaSP;

    for (int i = 1; i < sl; i++)
    {
        if (MaSP == DS[i].MaSP)
        {
            ham_XoaSanPham(sl, i);
        }
    }
}

void ham_SapXepTenSanPhamTangDan(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].TenSP[0] > DS[j].TenSP[0])
            {
                SANPHAM temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_SapXepSanPhamTheoGiaBanGiamDan(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].GiaBan < DS[j].GiaBan)
            {
                SANPHAM temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

// Chỗ này không biết được khoảng giá bán hay mua nên làm 2 cái giá bán với mua, thích cái nào xài cái đó

void ham_InDanhSachSanPhamTheoKhoangGiaBanNhapVao(int sl)
{
    long long begin, finish;
    cout << "\nNhap khoang gia";
    cout << "\nNhap gia bat dau: ";
    cin >> begin;
    cout << "\nNhap gia ket thuc: ";
    cin >> finish;

    for (int i = 0; i < sl; i++)
    {
        if (DS[i].GiaBan >= begin && DS[i].GiaBan <= finish)
        {
            ham_InRaMotSanPham(i);
            cout << endl;
        }
    }
}

void ham_InDanhSachSanPhamTheoKhoangGiaMuaNhapVao(int sl)
{
    long long begin, finish;
    cout << "\nNhap khoang gia";
    cout << "\nNhap gia bat dau: ";
    cin >> begin;
    cout << "\nNhap gia ket thuc: ";
    cin >> finish;

    for (int i = 0; i < sl; i++)
    {
        if (DS[i].GiaMua >= begin && DS[i].GiaMua <= finish)
        {
            ham_InRaMotSanPham(i);
            cout << endl;
        }
    }
}

void ham_MENU(int &luachon)
{
    cout << "\n=======================MENU CHON LUA=====================\n";
    cout << "\n1.In thong tin san  pham theo ma SP";
    cout << "\n2.Them vao danh sach 1 san pham";
    cout << "\n3.Xoa san pham theo ma SP";
    cout << "\n4.In danh sach san pham ten tang dan";
    cout << "\n5.In danh sach san pham co gia ban giam dan";
    cout << "\n6.In danh sach san pham theo mot khoang gia nhap vao";
    cout << "\n7.Ket Thuc\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> luachon;

    } while (luachon < 1 || luachon > 7);
}