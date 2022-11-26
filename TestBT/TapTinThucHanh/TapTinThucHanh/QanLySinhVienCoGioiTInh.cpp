#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 1000;
void ham_DocTapTin(int &sl);
void ham_InRaMotSinhVien(int vitri);
void ham_InRaToanBoSinhVien(int sl);
void ham_InRaMotSinhVienVao_TapTin(int vitri);
void ham_InRaToanBoSinhVienVao_TapTin(int sl);
void ham_TimThongTinSinhVienTheoChuCaiNhapVao(int sl);
void ham_TimThongTinSinhVienTheoHo(int sl);
void ham_TimThongTinSinhVienTheoThang(int sl);
double ham_DiemTrungBinh(int vitri);
void ham_InThongTinSinhVienCoItNhatMotMonDiemDuoiSoDiemNhapVao(int sl);
void ham_TimThongTinSinhVienTheoChuCaiNhapVao_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_InThongTinSinhVienCoItNhatMotMonDiemDuoiSoDiemNhapVao_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_TimThongTinSinhVienTheoThang_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_TimThongTinSinhVienTheoNgay_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_TimThongTinSinhVienTheoNgayVaThang_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_TimThongTinSinhVienTheoHo_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_NhapThongTinSinhVien(struct SinhVien &sv);
void ham_ThemSinhVienVaoDanhSach(int &sl, SinhVien &x, int &vitri);
void ham_XoaSinhVien(int &sl, int vitri);
void ham_XoaSinhVienTheoMSSV(int &sl);
void ham_XuatThongTinSinhVienTheoSTT(int &stt);
void ham_XuatThongTinSinhVienTheoSTT_ManHinh_TapTin(int &stt, int ManHinhHayTapTin);
void ham_SapXepDanhSachSinhVienTenTangDanHoacGiamDan_Bool(int sl);
void ham_SapXepDiemTrungBinhTangHoacGiamDan_Bool(int sl);
void ham_InDanhSachSinhVienDauHoacRot_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_InThongTinSinhVienTheoMSSV_ManHinh_TapTin(int sl, int ManHinhHayTapTin);
void ham_MENU(int &luachon);
void ham_ManHinhHayTapTin(int &ManHinhHayTapTin);

struct NTN
{
    int ngay, thang, nam;
};

struct Diem
{
    double diem1, diem2, diem3;
};

struct SinhVien
{
    string mssv;
    string holot;
    string ten;
    bool nam;
    string que;
    NTN namsinh;
    Diem diemthi;
};

int sl, luachon, check;
string rac;
SinhVien DS[MAX];

int main()
{
    system("cls"); // Xóa mấy cái linh tinh trong Visual studio Code
    ham_DocTapTin(sl);
    do
    {
        ham_MENU(luachon);

        if (luachon == 1)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_InThongTinSinhVienTheoMSSV_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 2)
        {
            SinhVien x;
            int vitri, ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_ThemSinhVienVaoDanhSach(sl, x, vitri);

            if (ManHinhHayTapTin == 0)
            {
                ham_InRaToanBoSinhVien(sl);
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaToanBoSinhVienVao_TapTin(sl);
                cout << "\nGhi thanh cong!!!";
            }
        }

        if (luachon == 3)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_XoaSinhVienTheoMSSV(sl);

            if (ManHinhHayTapTin == 0)
            {
                ham_InRaToanBoSinhVien(sl);
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaToanBoSinhVienVao_TapTin(sl);
                cout << "\nGhi thanh cong!!!";
            }
        }

        if (luachon == 4)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_SapXepDanhSachSinhVienTenTangDanHoacGiamDan_Bool(sl);

            if (ManHinhHayTapTin == 0)
            {
                ham_InRaToanBoSinhVien(sl);
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaToanBoSinhVienVao_TapTin(sl);
                cout << "\nGhi thanh cong!!!";
            }
        }

        if (luachon == 5)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_SapXepDiemTrungBinhTangHoacGiamDan_Bool(sl);

            if (ManHinhHayTapTin == 0)
            {
                ham_InRaToanBoSinhVien(sl);
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaToanBoSinhVienVao_TapTin(sl);
                cout << "\nGhi thanh cong!!!";
            }
        }

        if (luachon == 6)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_InDanhSachSinhVienDauHoacRot_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 7)
        {
            int ManHinhHayTapTin, stt;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_XuatThongTinSinhVienTheoSTT_ManHinh_TapTin(stt, ManHinhHayTapTin);
        }

        if (luachon == 8)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_TimThongTinSinhVienTheoHo_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 9)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_InThongTinSinhVienCoItNhatMotMonDiemDuoiSoDiemNhapVao_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 10)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_TimThongTinSinhVienTheoChuCaiNhapVao_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 11)
        {
            int ManHinhHayTapTin;
            ham_ManHinhHayTapTin(ManHinhHayTapTin);
            ham_TimThongTinSinhVienTheoNgayVaThang_ManHinh_TapTin(sl, ManHinhHayTapTin);
        }

        if (luachon == 12)
        {
            cout << "\n\t=======================*  KET THUC  *=====================\n";
            break;
        }

        cout << "\n\nBan co muon lam tiep khong ?\n1.Co\n0.Khong";
        cout << "\nHay nhap: ";
        cin >> check;
        fflush(stdin);
        system("cls");

    } while (1);

    system("pause");
    return 0;
}

void ham_DocTapTin(int &sl)
{
    sl = 1;
    ifstream docFile;
    docFile.open("D:\\TXT\\QuanLySinhVienCoGioiTinh.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n\n";
        getline(docFile, rac);
        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].mssv, ',');
            getline(docFile, DS[sl].holot, ',');
            getline(docFile, DS[sl].ten, ',');

            string gioitinh;
            getline(docFile, gioitinh, ',');
            if (gioitinh == "nam")
            {
                DS[sl].nam = true;
            }
            else if (gioitinh == "nu")
            {
                DS[sl].nam = false;
            }

            getline(docFile, DS[sl].que, ',');
            docFile >> DS[sl].namsinh.ngay;
            docFile.ignore(1);
            docFile >> DS[sl].namsinh.thang;
            docFile.ignore(1);
            docFile >> DS[sl].namsinh.nam;
            docFile.ignore(1);
            docFile >> DS[sl].diemthi.diem1;
            docFile.ignore(1);
            docFile >> DS[sl].diemthi.diem2;
            docFile.ignore(1);
            docFile >> DS[sl].diemthi.diem3;
            docFile.ignore(1);

            sl++;
        }
        docFile.close();
    }
    else
        cout << "Mo khong duoc!!!";
}

void ham_InRaMotSinhVien(int vitri)
{
    cout << "\nMa so sinh vien: " << DS[vitri].mssv;
    cout << "\nHo va Ten: " << DS[vitri].holot << " " << DS[vitri].ten;

    if (DS[vitri].nam == true)
        cout << "\nGioi tinh: Nam";
    else
        cout << "\nGioi tinh: Nu";

    cout << "\nNgay Thang Nam sinh: " << DS[vitri].namsinh.ngay << "/" << DS[vitri].namsinh.thang << "/" << DS[vitri].namsinh.nam;
    cout << "\nDiem 3 mon lan luot: " << DS[vitri].diemthi.diem1 << "-" << DS[vitri].diemthi.diem2 << "-" << DS[vitri].diemthi.diem3;
    cout << "\nDiem trung binh: " << ham_DiemTrungBinh(vitri);
}

void ham_InRaToanBoSinhVien(int sl)
{
    cout << "\n\tTOAN BO SINH VIEN";
    for (int i = 1; i < sl; i++)
    {
        ham_InRaMotSinhVien(i);
        cout << endl;
    }
}

void ham_InRaMotSinhVienVao_TapTin(int vitri)
{
    ofstream ghiFile;
    ghiFile.open("D:\\TXT\\FileDeGhi.txt", ios::app);
    if (ghiFile.is_open())
    {
        ghiFile << "\nMa so sinh vien: " << DS[vitri].mssv;
        ghiFile << "\nHo va Ten: " << DS[vitri].holot << " " << DS[vitri].ten;

        if (DS[vitri].nam == true)
            ghiFile << "\nGioi tinh: Nam";
        else
            ghiFile << "\nGioi tinh: Nu";

        ghiFile << "\nNgay Thang Nam sinh: " << DS[vitri].namsinh.ngay << "/" << DS[vitri].namsinh.thang << "/" << DS[vitri].namsinh.nam;
        ghiFile << "\nDiem 3 mon lan luot: " << DS[vitri].diemthi.diem1 << "-" << DS[vitri].diemthi.diem2 << "-" << DS[vitri].diemthi.diem3;
        ghiFile << "\nDiem trung binh: " << ham_DiemTrungBinh(vitri);
        ghiFile << endl;
    }
    ghiFile.close();
}

void ham_InRaToanBoSinhVienVao_TapTin(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        ham_InRaMotSinhVienVao_TapTin(i);
    }
}

void ham_TimThongTinSinhVienTheoChuCaiNhapVao(int sl)
{
    string TimKiem;
    int dem = 0;
    cout << "\nNhap chu cai hoac ten sinh vien: ";
    getline(cin, TimKiem);

    for (int i = 1; i < sl; i++)
    {
        int KQ = DS[i].ten.find(TimKiem, 0);
        if (KQ >= 0)
        {
            ham_InRaMotSinhVien(i);
            cout << endl;
            dem++;
        }
    }

    if (dem == 0)
        cout << "\nKhong co sinh vien nao co ten: " << TimKiem;
}

void ham_TimThongTinSinhVienTheoHo(int sl)
{
    string TimKiem;
    int dem = 0;
    int dem1 = 0;
    cout << "\nNhap ho cua sinh vien: ";
    getline(cin, TimKiem);

    for (int i = 0; i < TimKiem.length(); i++)
    {
        dem++;
    }

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].holot.substr(0, dem) == TimKiem)
        {
            ham_InRaMotSinhVien(i);
            cout << endl;
            dem1++;
        }
    }
    if (dem1 == 0)
        cout << "\nKhong co sinh vien nao co ho: " << TimKiem;
}

void ham_TimThongTinSinhVienTheoThang(int sl)
{
    int Ngay;
    do
    {
        cout << "\nNhap ngay: ";
        cin >> Ngay;

    } while (Ngay < 1 || Ngay > 31);

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].namsinh.ngay == Ngay)
        {
            ham_InRaMotSinhVien(i);
            cout << endl;
        }
    }
}

double ham_DiemTrungBinh(int vitri)
{
    return (DS[vitri].diemthi.diem1 + DS[vitri].diemthi.diem2 + DS[vitri].diemthi.diem3) / 3;
}

void ham_InThongTinSinhVienCoItNhatMotMonDiemDuoiSoDiemNhapVao(int sl)
{
    double Diem;
    cout << "\nNhap diem: ";
    cin >> Diem;
    cout << "\nNhung sinh vien co it nhat mot mon co diem duoi " << Diem << " la: \n";

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].diemthi.diem1 <= Diem || DS[i].diemthi.diem2 <= Diem || DS[i].diemthi.diem3 <= Diem)
        {
            ham_InRaMotSinhVien(i);
            cout << endl;
        }
    }
}

void ham_TimThongTinSinhVienTheoChuCaiNhapVao_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    string TimKiem;
    int dem = 0;
    cout << "\nNhap chu cai hoac ten sinh vien: ";
    fflush(stdin);
    getline(cin, TimKiem);

    for (int i = 1; i < sl; i++)
    {
        int KQ = DS[i].ten.find(TimKiem, 0);
        if (KQ >= 0)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong co sinh vien nao co ten: " << TimKiem;
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_InThongTinSinhVienCoItNhatMotMonDiemDuoiSoDiemNhapVao_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    double Diem, dem = 0;
    cout << "\nNhap diem: ";
    cin >> Diem;

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].diemthi.diem1 <= Diem || DS[i].diemthi.diem2 <= Diem || DS[i].diemthi.diem3 <= Diem)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_TimThongTinSinhVienTheoThang_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    int Thang, dem = 0;
    do
    {
        cout << "\nNhap thang: ";
        cin >> Thang;

    } while (Thang < 1 || Thang > 12);

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].namsinh.thang == Thang)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_TimThongTinSinhVienTheoNgay_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    int Ngay, dem = 0;
    do
    {
        cout << "\nNhap ngay: ";
        cin >> Ngay;

    } while (Ngay < 1 || Ngay > 31);

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].namsinh.ngay == Ngay)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_TimThongTinSinhVienTheoNgayVaThang_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    int Ngay, Thang, dem = 0;
    do
    {
        cout << "\nNhap ngay: ";
        cin >> Ngay;

    } while (Ngay < 1 || Ngay > 31);

    do
    {
        cout << "Nhap thang: ";
        cin >> Thang;
    } while (Thang < 1 || Thang > 12);

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].namsinh.ngay == Ngay && DS[i].namsinh.thang == Thang)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_TimThongTinSinhVienTheoHo_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    string TimKiem;
    int demsl = 0;
    int dem = 0;
    cout << "\nNhap ho cua sinh vien: ";
    fflush(stdin);
    getline(cin, TimKiem);

    for (int i = 0; i < TimKiem.length(); i++)
    {
        demsl++;
    }

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].holot.substr(0, demsl) == TimKiem)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }
    if (dem == 0)
    {
        cout << "\nKhong co sinh vien nao co ho: " << TimKiem;
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_NhapThongTinSinhVien(struct SinhVien &sv)
{
    int dem;
    do
    {
        dem = 0;
        cout << "\nNhap MSSV: ";
        fflush(stdin);
        getline(cin, sv.mssv);

        for (int i = 1; i < sl; i++)
        {
            if (sv.mssv == DS[i].mssv)
            {
                dem++;
            }
        }
        if (dem > 0)
        {
            cout << "\nDa ton tai MSSV, vui long nhap lai!\n";
        }

    } while (dem > 0);

    cout << "Nhap ho lot: ";
    getline(cin, sv.holot);
    cout << "Nhap ten: ";
    getline(cin, sv.ten);
    cout << "Nhap gioi tinh (1. Nam / 0.Nu): ";
    cin >> sv.nam;
    fflush(stdin);
    cout << "Nhap que quan: ";
    getline(cin, sv.que);
    cout << "Nhap ngay - thang - nam sinh cach nhau dau enter: ";
    cin >> sv.namsinh.ngay >> sv.namsinh.thang >> sv.namsinh.nam;
    cout << "Nhap diem thi 3 mon cach nhau dau enter: ";
    cin >> sv.diemthi.diem1 >> sv.diemthi.diem2 >> sv.diemthi.diem3;
}

void ham_ThemSinhVienVaoDanhSach(int &sl, SinhVien &x, int &vitri)
{
    cout << "\nNhap vi tri ban muon them: ";
    cin >> vitri;
    cout << "\nNhap thong tin sinh vien ban muon them vao vi tri so " << vitri;
    ham_NhapThongTinSinhVien(x);

    for (int i = sl; i >= vitri; i--)
    {
        DS[i + 1] = DS[i];
    }
    sl++;
    DS[vitri] = x;
}

void ham_XoaSinhVien(int &sl, int vitri)
{
    for (int i = vitri; i < sl; i++)
    {
        DS[i] = DS[i + 1];
    }
    sl--;
}

void ham_XoaSinhVienTheoMSSV(int &sl)
{
    string MSSV;
    int dem = 0;
    cout << "\nNhap MSSV: ";
    fflush(stdin);
    getline(cin, MSSV);

    for (int i = 1; i < sl; i++)
    {
        if (MSSV == DS[i].mssv)
        {
            ham_XoaSinhVien(sl, i);
            dem++;
        }
    }

    if (dem == 0)
        cout << "\nKhong ton tai MSSV";
}

void ham_XuatThongTinSinhVienTheoSTT(int &stt)
{
    cout << "\nNhap so thu tu: ";
    cin >> stt;
    ham_InRaMotSinhVien(stt);
}

void ham_XuatThongTinSinhVienTheoSTT_ManHinh_TapTin(int &stt, int ManHinhHayTapTin)
{
    int dem = 0;
    cout << "\nNhap so thu tu: ";
    cin >> stt;

    if (ManHinhHayTapTin == 0)
    {
        ham_InRaMotSinhVien(stt);
        dem++;
    }
    else if (ManHinhHayTapTin == 1)
    {
        ham_InRaMotSinhVienVao_TapTin(stt);
        dem++;
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_SapXepDanhSachSinhVienTenTangDanHoacGiamDan_Bool(int sl)
{
    bool TangHoacGiam;
    cout << "\nBan muon sap xep ten tang hay giam? ";
    cout << "\n0. Giam\n1. Tang";
    do
    {
        cout << "\nNhap: ";
        cin >> TangHoacGiam;

    } while (TangHoacGiam < 0 || TangHoacGiam > 1);

    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].ten[0] > DS[j].ten[0] == TangHoacGiam)
            {
                //swap(DS[i], DS[j]);
                SinhVien temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_SapXepDiemTrungBinhTangHoacGiamDan_Bool(int sl)
{
    bool TangHoacGiam;
    cout << "\nBan muon sap xep DTB tang hay giam? ";
    cout << "\n0. Giam\n1. Tang";
    do
    {
        cout << "\nNhap: ";
        cin >> TangHoacGiam;

    } while (TangHoacGiam < 0 || TangHoacGiam > 1);

    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (ham_DiemTrungBinh(i) > ham_DiemTrungBinh(j) == TangHoacGiam)
            {
                //swap(DS[i], DS[j]);
                SinhVien temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_InDanhSachSinhVienDauHoacRot_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    int dem = 0;
    int DauHayRot;
    cout << "\nBan muon xem thong tin co diem trung binh dau hay rot??";
    cout << "\n0. Rot\n1. Dau";
    do
    {
        cout << "\nNhap: ";
        cin >> DauHayRot;

    } while (DauHayRot < 0 || DauHayRot > 1);

    if (DauHayRot == 1)
    {
        for (int i = 1; i < sl; i++)
        {
            if (ham_DiemTrungBinh(i) >= 5)
            {
                if (ManHinhHayTapTin == 0)
                {
                    ham_InRaMotSinhVien(i);
                    cout << endl;
                    dem++;
                }
                else if (ManHinhHayTapTin == 1)
                {
                    ham_InRaMotSinhVienVao_TapTin(i);
                    dem++;
                }
            }
        }
    }
    else if (DauHayRot == 0)
    {
        for (int i = 1; i < sl; i++)
        {
            if (ham_DiemTrungBinh(i) < 5)
            {
                if (ManHinhHayTapTin == 0)
                {
                    ham_InRaMotSinhVien(i);
                    cout << endl;
                    dem++;
                }
                else if (ManHinhHayTapTin == 1)
                {
                    ham_InRaMotSinhVienVao_TapTin(i);
                    dem++;
                }
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay!";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_InThongTinSinhVienTheoMSSV_ManHinh_TapTin(int sl, int ManHinhHayTapTin)
{
    string MSSV;
    int dem = 0;
    fflush(stdin);
    cout << "\nNhap MSSV: ";
    getline(cin, MSSV);

    for (int i = 1; i < sl; i++)
    {
        if (MSSV == DS[i].mssv)
        {
            if (ManHinhHayTapTin == 0)
            {
                ham_InRaMotSinhVien(i);
                cout << endl;
                dem++;
            }
            else if (ManHinhHayTapTin == 1)
            {
                ham_InRaMotSinhVienVao_TapTin(i);
                dem++;
            }
        }
    }

    if (dem == 0)
    {
        cout << "\nKhong tim thay";
    }
    else if (ManHinhHayTapTin == 1)
    {
        cout << "\nGhi thanh cong!!!";
    }
}

void ham_MENU(int &luachon)
{
    cout << "\n\t=======================* MENU CHON LUA *=====================\n";
    cout << "\n1.In thong tin sinh vien theo MSSV";
    cout << "\n2.Them vao danh sach 1 sinh vien";
    cout << "\n3.Xoa sinh vien theo MSSV";
    cout << "\n4.In danh sach sinh vien ten tang hoac dan";
    cout << "\n5.In danh sach sinh vien diem trung binh tang hoac giam dan";
    cout << "\n6.In danh sach sinh vien dau (DTB >=5) hoac rot (DTB < 5)";
    cout << "\n7.In thong tin sinh vien theo STT";
    cout << "\n8.In thong tin sinh vien theo ho";
    cout << "\n9.In thong tin sinh vien co it nhat 1 mon co diem duoi so diem nhap vao";
    cout << "\n10.In thong tin sinh vien theo chu cai nhap vao";
    cout << "\n11.In thong tin sinh vien theo thang";
    cout << "\n12.Ket Thuc\n";
    cout << "\n\t===========================================================\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> luachon;

    } while (luachon < 1 || luachon > 12);
}

void ham_ManHinhHayTapTin(int &ManHinhHayTapTin)
{
    cout << "\nBan muon in vao man hinh hay tap tin: ";
    cout << "\n0.Man hinh\n1.Tap Tin\n";
    do
    {
        cout << "Nhap: ";
        cin >> ManHinhHayTapTin;

    } while (ManHinhHayTapTin < 0 || ManHinhHayTapTin > 1);
}