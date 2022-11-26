#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 1000;
void ham_DocTapTin(int &sl);
void ham_InThongTinMotSinhVien(int vitri);
void ham_InToanBoDanhSachSinhVien(int sl);
void ham_TimSinhVienTheoMSSV(int sl);
void ham_NhapThongTinMotSinhVien(struct SinhVien &sv);
void ham_ThemSinhVienVaoDanhSach(int &sl, struct SinhVien x, int &vitri);
void ham_XoaSinhVienTrongDanhSach(int &sl, int &vitri);
void ham_SapXepDanhSachSinhVienTheoTenTangDan(int sl);
void ham_InDanhSachSinhVienDauHoacRot(int sl);
void ham_XoaSinhVien(int &sl, int vitri);
void ham_XoaSinhVienTheoMSSV(int &sl);
double ham_DTB(int vitri);
void ham_SapXepDanhSachSinhVienTrungBinhGiamDan(int sl);
void ham_MENU(int &luachon);

struct Diem
{
    double Diem1;
    double Diem2;
};
struct SinhVien
{
    string MSSV;
    string Holot;
    string Ten;
    Diem DiemMonHoc;
};

int sl, luachon, check;
SinhVien DS[MAX + 1];

int main()
{
    system("cls");
    ham_DocTapTin(sl);
    do
    {
        ham_MENU(luachon);
        if (luachon == 1)
        {
            ham_TimSinhVienTheoMSSV(sl);
        }

        if (luachon == 2)
        {
            SinhVien x;
            int vitri;
            ham_ThemSinhVienVaoDanhSach(sl, x, vitri);
            ham_InToanBoDanhSachSinhVien(sl);
        }

        if (luachon == 3)
        {
            ham_XoaSinhVienTheoMSSV(sl);
            ham_InToanBoDanhSachSinhVien(sl);
        }

        if (luachon == 4)
        {
            ham_SapXepDanhSachSinhVienTheoTenTangDan(sl);
            ham_InToanBoDanhSachSinhVien(sl);
        }

        if (luachon == 5)
        {
            ham_SapXepDanhSachSinhVienTrungBinhGiamDan(sl);
            ham_InToanBoDanhSachSinhVien(sl);
        }

        if (luachon == 6)
        {
            ham_InDanhSachSinhVienDauHoacRot(sl);
        }

        if (luachon == 7)
        {

            cout << "\n=================* KET THUC *=================\n";
            break;
        }

        cout << "\n\nBan co muon lam tiep khong ?\n1.Co\n0.Khong";
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
    docFile.open("D:\\TXT\\CodeDum1.txt", ios::in); // Chỗ này về tự đổi về địa chỉ tập tin trên máy của bạn
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n\n";
        sl = 1;
        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].MSSV, '-');
            getline(docFile, DS[sl].Holot, '-');
            getline(docFile, DS[sl].Ten, '-');
            docFile >> DS[sl].DiemMonHoc.Diem1;
            docFile.ignore(1);
            docFile >> DS[sl].DiemMonHoc.Diem2;
            docFile.ignore(1);
            sl++;
        }
    }
    else
        cout << "\nKhong mo duoc tap tin";
}

void ham_InThongTinMotSinhVien(int vitri)
{
    cout << "\nMSSV: " << DS[vitri].MSSV;
    cout << "\nHo va Ten: " << DS[vitri].Holot << " " << DS[vitri].Ten;
    cout << "\nDiem mon 1: " << DS[vitri].DiemMonHoc.Diem1;
    cout << "\nDiem mon 2: " << DS[vitri].DiemMonHoc.Diem2;
    cout << "\nDiem trung binh: " << (DS[vitri].DiemMonHoc.Diem1 + DS[vitri].DiemMonHoc.Diem2) / 2;
}

void ham_InToanBoDanhSachSinhVien(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        ham_InThongTinMotSinhVien(i);
        cout << endl;
    }
}

void ham_TimSinhVienTheoMSSV(int sl)
{
    string MaSoSV;
    cout << "\nNhap MSSV: ";
    cin >> MaSoSV;
    int dem = 0;
    for (int i = 1; i < sl; i++)
    {
        if (MaSoSV == DS[i].MSSV)
        {
            ham_InThongTinMotSinhVien(i);
            dem++;
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay sinh vien";
    }
}

void ham_NhapThongTinMotSinhVien(struct SinhVien &sv)
{
    int dem;
    do
    {
        dem = 0;
        cout << "\nNhap MSSV: ";
        cin >> sv.MSSV;

        for (int i = 1; i < sl; i++)
        {
            if (sv.MSSV == DS[i].MSSV)
            {
                dem++;
            }
        }

        if (dem > 0)
        {
            cout << "MSSV da ton tai, vui long nhap lai\n";
        }

    } while (dem > 0);

    cout << "Nhap ho lot: ";
    fflush(stdin);
    getline(cin, sv.Holot);
    cout << "Nhap ten: ";
    getline(cin, sv.Ten);
    cout << "Nhap diem mon 1: ";
    cin >> sv.DiemMonHoc.Diem1;
    cout << "Nhap diem mon 2: ";
    cin >> sv.DiemMonHoc.Diem2;
}

void ham_ThemSinhVienVaoDanhSach(int &sl, struct SinhVien x, int &vitri)
{
    cout << "Nhap vi tri ban muon them mot sinh vien: ";
    cin >> vitri;
    cout << "Nhap thong tin sinh vien tai vi tri thu " << vitri << endl;
    ham_NhapThongTinMotSinhVien(x);

    for (int i = sl - 1; i >= vitri; i--)
    {
        DS[i + 1] = DS[i];
    }
    DS[vitri] = x;
    sl++;
}

void ham_XoaSinhVienTrongDanhSach(int &sl, int &vitri) // Làm lộn :))) Khuyến mãi :)))
{
    cout << "Nhap vi tri ban muon xoa mot sinh vien: ";
    cin >> vitri;

    for (int i = vitri; i < sl; i++)
    {
        DS[i] = DS[i + 1];
    }
    sl--;
}

void ham_XoaSinhVien(int &sl, int vitri)
{
    for (int i = vitri; i < sl; i++)
    {
        DS[i] = DS[i + 1];
    }
    sl--;
}

void ham_XoaSinhVienTheoMSSV(int &sl) // Này mới đúng :))
{
    string MaSoSV;
    cout << "\nNhap MSSV: ";
    cin >> MaSoSV;

    for (int i = 1; i < sl; i++)
    {
        if (MaSoSV == DS[i].MSSV)
        {
            ham_XoaSinhVien(sl, i);
        }
    }
}

void ham_SapXepDanhSachSinhVienTheoTenTangDan(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].Ten[0] > DS[j].Ten[0])
            {
                SinhVien temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_InDanhSachSinhVienDauHoacRot(int sl)
{
    double DTB;
    cout << "\nDanh sach sinh vien dau (DTB >= 5) la: \n";
    for (int i = 1; i < sl; i++)
    {
        DTB = (DS[i].DiemMonHoc.Diem1 + DS[i].DiemMonHoc.Diem2) / 2;
        if (DTB >= 5)
        {
            ham_InThongTinMotSinhVien(i);
            cout << endl;
        }
    }
    cout << "\n\t==============================================================================\n";
    cout << "\nDanh sach sinh vien rot (DTB < 5) la: \n";
    for (int i = 1; i < sl; i++)
    {
        DTB = (DS[i].DiemMonHoc.Diem1 + DS[i].DiemMonHoc.Diem2) / 2;
        if (DTB < 5)
        {
            ham_InThongTinMotSinhVien(i);
            cout << endl;
        }
    }
}

double ham_DTB(int vitri)
{
    return (DS[vitri].DiemMonHoc.Diem1 + DS[vitri].DiemMonHoc.Diem2) / 2;
}

void ham_SapXepDanhSachSinhVienTrungBinhGiamDan(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (ham_DTB(i) < ham_DTB(j))
            {
                SinhVien temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_MENU(int &luachon)
{
    cout << "\n=======================MENU CHON LUA=====================\n";
    cout << "\n1.In thong tin sinh vien theo MSSV";
    cout << "\n2.Them vao danh sach 1 sinh vien";
    cout << "\n3.Xoa sinh vien theo MSSV";
    cout << "\n4.In danh sach sinh vien ten tang dan";
    cout << "\n5.In danh sach sinh vien diem trung binh giam dan";
    cout << "\n6.In danh sach sinh vien dau (DTB >=5) hoac rot (DTB < 5)";
    cout << "\n7.Ket Thuc\n";

    cout << "\nBan muon lam cau may: ";
    cin >> luachon;
}