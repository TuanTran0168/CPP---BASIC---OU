#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct SINHVIEN
{
    string maSoSinhVien;
    string hoTen;
    string gioiTinh;
    string diaChi;
    int namSinh;
    double diemTrungBinh;
};
typedef struct SINHVIEN SinhVien;

struct NODE
{
    SinhVien infor;
    struct NODE *link;
};
typedef struct NODE Node;

struct LIST
{
    Node *first;
};
typedef struct LIST list;

void khoiTao(list &l);
Node *nhapMotSinhVien();
void themMotSinhVienVaoCuoiDanhSach(list &l, SinhVien sv);
void docSinhVienTuTapTin(list &l);
void hienThiMotSinhVien(SinhVien sv);
void hienThiDanhSachSinhVien(list l);
Node *timKiem(list l, string maSoSinhVien);
void dieuChinhThongTin(SinhVien &sv);
int xoaDau(list &l);
int xoaCuoi(list &l);
Node *timNodeCuoi(list l);
int xoaSinhVien(list &l, string maSoSinhVien);
void sapXepTheoDiemGiamDan(list l);
int demSoSinhVienDiemTren5(list l);
int demSoLuongSinhVien(list l);
void xuatDanhSachSinhVienVaoTapTin(list l);

int main()
{
    list listSinhVien;
    int chon;
    bool checkKhoiTao = false;
    do
    {
        system("cls");
        cout << "\n\t ========== MENU ==========";
        cout << "\n1. Khoi tao danh sach";
        cout << "\n2. Doc thong tin cac sinh vien tu tap tin vao danh sach";
        cout << "\n3. Xuat danh sach sinh vien";
        cout << "\n4. Nhap tung sinh vien vao danh sach";
        cout << "\n5. Chinh thong tin 1 sinh vien";
        cout << "\n6. Them sinh vien";
        cout << "\n7. Xoa sinh vien";
        cout << "\n8. Tim sinh vien theo MSSV";
        cout << "\n9. Sap xep danh sach theo diem trung binh giam dan";
        cout << "\n10. Dem so luong sinh vien co DTB tu 5 tro len";
        cout << "\n11. Dem so luong sinh vien trong danh sach";
        cout << "\n12. Xuat toan bo danh sach sinh vien vao tap tin";
        cout << "\n\t ==========================";
        cout << "\n0. Thoat";
        cout << "\n\t ==========================";
        cout << "\nNhap cai gi di: ";
        cin >> chon;

        if (chon == 0)
        {
            cout << "\n\t ===== DA THOAT =====";
        }

        else if (chon == 1)
        {
            khoiTao(listSinhVien);
            checkKhoiTao = true;
            cout << "\nKhoi tao thanh cong!!!";
        }

        else if (checkKhoiTao)
        {
            if (chon == 2)
            {
                docSinhVienTuTapTin(listSinhVien);
            }

            else if (chon == 3)
            {
                hienThiDanhSachSinhVien(listSinhVien);
            }

            else if (chon == 4)
            {
                int flag;

                do
                {
                    themMotSinhVienVaoCuoiDanhSach(listSinhVien, nhapMotSinhVien()->infor);
                    cout << "\nCo muon nhap nua khong: \n1. Co\n0. Khong\nNhap: ";
                    cin >> flag;

                } while (flag);
            }

            else if (chon == 5)
            {
                string mssv;
                cout << "\nNhap ma so sinh vien de dieu chinh: ";
                cin >> mssv;
                Node *sv = timKiem(listSinhVien, mssv);
                if (sv != NULL)
                {
                    cout << "\n\tDa tim thay!!!";
                    hienThiMotSinhVien(sv->infor);
                    cout << "\n\tHay chinh sua cac thong tin" << endl;
                    dieuChinhThongTin(sv->infor);
                }
                else
                    cout << "\nKhong tim thay sinh vien co ma so sinh vien: " << mssv;
            }

            else if (chon == 6)
            {
                themMotSinhVienVaoCuoiDanhSach(listSinhVien, nhapMotSinhVien()->infor);
            }

            else if (chon == 7)
            {
                string mssv;
                cout << "\nNhap ma so sinh vien de xoa: ";
                cin >> mssv;
                cout << "\nThong tin sinh vien ma ban chon xoa";
                Node *sv = timKiem(listSinhVien, mssv);
                hienThiMotSinhVien(sv->infor);
                int kQ = xoaSinhVien(listSinhVien, mssv);

                if (kQ == 1)
                    cout << "\nXoa thanh cong!!!";
                else
                    cout << "\nXoa khong thanh cong!!!";
            }

            else if (chon == 8)
            {
                string mssv;
                cout << "\nNhap ma so sinh vien de tim: ";
                cin >> mssv;
                Node *sv = timKiem(listSinhVien, mssv);

                if (sv != NULL)
                    hienThiMotSinhVien(sv->infor);
                else
                    cout << "\nKhong tim thay!!!";
            }

            else if (chon == 9)
            {
                sapXepTheoDiemGiamDan(listSinhVien);
                cout << "\nThuc hien thanh cong!!!";
            }

            else if (chon == 10)
            {
                cout << "\nSo luong sinh vien tren 5 diem la: " << demSoSinhVienDiemTren5(listSinhVien);
            }

            else if (chon == 11)
            {
                cout << "\nSo luong sinh vien trong danh sach la: " << demSoLuongSinhVien(listSinhVien);
            }

            else if (chon == 12)
            {
                xuatDanhSachSinhVienVaoTapTin(listSinhVien);
                cout << "\nThuc hien thanh cong!!!";
            }
        }
        else
            cout << "\nHay khoi tao danh sach!!!";

        cout << endl
             << endl;
        system("pause");

    } while (chon > 0);
    system("pause");
    return 0;
}

void khoiTao(list &l)
{
    l.first = NULL;
}

Node *nhapMotSinhVien()
{
    Node *sv = new Node;
    cin.ignore();
    cout << "\nNhap ma so sinh vien: ";
    getline(cin, sv->infor.maSoSinhVien);
    cout << "Nhap ho va ten: ";
    getline(cin, sv->infor.hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, sv->infor.gioiTinh);
    cout << "Nhap dia chi: ";
    getline(cin, sv->infor.diaChi);
    cout << "Nhap nam sinh: ";
    cin >> sv->infor.namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> sv->infor.diemTrungBinh;

    return sv;
}

void themMotSinhVienVaoCuoiDanhSach(list &l, SinhVien sv)
{
    Node *p = new Node;
    p->infor = sv;
    p->link = NULL;

    if (l.first == NULL)
        l.first = p;
    else
    {
        Node *q = l.first;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = p;
    }
}

void docSinhVienTuTapTin(list &l)
{
    ifstream docFile;
    docFile.open("SinhVienBTH7.txt", ios::in);
    if (docFile.is_open())
    {
        while (!docFile.eof())
        {
            SinhVien sv;

            getline(docFile, sv.maSoSinhVien, ',');
            getline(docFile, sv.hoTen, ',');
            getline(docFile, sv.gioiTinh, ',');
            getline(docFile, sv.diaChi, ',');
            docFile >> sv.namSinh;
            docFile.ignore(1);
            docFile >> sv.diemTrungBinh;
            docFile.ignore(1);

            themMotSinhVienVaoCuoiDanhSach(l, sv);
        }
        cout << "\nThuc hien thanh cong!!!";
        docFile.close();
    }
    else
        cout << "\nKhong mo duoc!!!";
}

void hienThiMotSinhVien(SinhVien sv)
{
    cout << "\nMa so sinh vien: " << sv.maSoSinhVien;
    cout << "\nHo va ten: " << sv.hoTen;
    cout << "\nGioi tinh: " << sv.gioiTinh;
    cout << "\nDia chi: " << sv.diaChi;
    cout << "\nNam sinh: " << sv.namSinh;
    cout << "\nDiem trung binh: " << sv.diemTrungBinh;
    cout << "\n\n=================================\n";
}

void hienThiDanhSachSinhVien(list l)
{
    Node *p = l.first;
    cout << "\n\n=================================\n";
    while (p != NULL)
    {
        hienThiMotSinhVien(p->infor);
        p = p->link;
    }
}

Node *timKiem(list l, string maSoSinhVien)
{
    Node *p = l.first;

    if (p != NULL)
    {
        while (p != NULL && p->infor.maSoSinhVien != maSoSinhVien)
            p = p->link;
        return p;
    }
}

void dieuChinhThongTin(SinhVien &sv)
{
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, sv.gioiTinh);
    cout << "Nhap dia chi: ";
    getline(cin, sv.diaChi);
    cout << "Nhap nam sinh: ";
    cin >> sv.namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> sv.diemTrungBinh;
}

int xoaDau(list &l)
{
    Node *p = l.first;
    if (p != NULL)
    {
        l.first = l.first->link;
        delete p;
        return 1;
    }
    return 0;
}

int xoaCuoi(list &l)
{
    Node *p = l.first;
    Node *q = NULL;
    ;
    if (p != NULL)
    {
        while (p->link != NULL)
        {
            q = p;
            p = p->link;
        }

        if (p == l.first)
            l.first = l.first->link;
        else
            q->link = NULL;

        delete p;
        return 1;
    }
    return 0;
}

Node *timNodeCuoi(list l)
{
    Node *last = l.first;
    while (last->link != NULL)
        last = last->link;
    return last;
}

int xoaSinhVien(list &l, string maSoSinhVien)
{
    if (l.first != NULL)
    {
        Node *last = timNodeCuoi(l);
        if (l.first->infor.maSoSinhVien == maSoSinhVien)
        {
            xoaDau(l);
            return 1;
        }
        else if (last->infor.maSoSinhVien == maSoSinhVien)
        {
            xoaCuoi(l);
            return 1;
        }
        else
        {
            Node *xoa = timKiem(l, maSoSinhVien);
            Node *p = xoa->link;
            Node *q = l.first;
            while (q->link != xoa)
                q = q->link;

            q->link = p;
            delete xoa;
            return 1;
        }
    }

    return 0;
}

void sapXepTheoDiemGiamDan(list l)
{
    for (Node *i = l.first; i->link != NULL; i = i->link)
    {
        for (Node *j = i->link; j != NULL; j = j->link)
        {
            if (i->infor.diemTrungBinh < j->infor.diemTrungBinh)
                swap(i->infor, j->infor);
        }
    }
}

int demSoSinhVienDiemTren5(list l)
{
    int count = 0;
    Node *p = l.first;
    while (p != NULL)
    {
        if (p->infor.diemTrungBinh > 5)
            count++;
        p = p->link;
    }

    return count;
}

int demSoLuongSinhVien(list l)
{
    int count = 0;
    Node *p = l.first;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }

    return count;
}

void xuatDanhSachSinhVienVaoTapTin(list l)
{
    ofstream ghiFile;
    ghiFile.open("OutputSinhVienBTH7.txt", ios::out);

    if (ghiFile.is_open())
    {
        Node *p = l.first;
        while (p != NULL)
        {
            ghiFile << "\nMa so sinh vien: " << p->infor.maSoSinhVien;
            ghiFile << "\nHo va ten: " << p->infor.hoTen;
            ghiFile << "\nGioi tinh: " << p->infor.gioiTinh;
            ghiFile << "\nDia chi: " << p->infor.diaChi;
            ghiFile << "\nNam sinh: " << p->infor.namSinh;
            ghiFile << "\nDiem trung binh: " << p->infor.diemTrungBinh;
            ghiFile << "\n\n=================================\n";
            p = p->link;
        }

        ghiFile.close();
    }
    else
        cout << "\nKhong mo duoc!!!";
}
