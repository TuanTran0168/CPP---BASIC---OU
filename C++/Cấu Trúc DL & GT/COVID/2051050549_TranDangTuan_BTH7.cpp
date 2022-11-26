#include <iostream>
#include <string>
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
void themMotSinhVienvaoCuoi(list &l, SinhVien sv);
void xuatMotSinhVien(SinhVien sv);
void xuatDanhSachSinhVien(list l);
Node *timKiem(list l, string maSoSV);
void hieuChinhThongTin(SinhVien &sv);
void xemThongTin(list l, string maSoSV);
void sapXepDTBGiamDan(list l);
int demSoSinhVienTren5Diem(list l);
int xoaDau(list &l);
int xoaCuoi(list &l);
int doDaiDanhSach(list l);
Node *timNodeCuoi(list l);
int xoaSinhVien(list &l, string mssv);

int main()
{
    int n;
    int chon;
    int viTri, x;
    list listSV;

    do
    {
        system("cls");
        cout << "\n\t ========== MENU ==========";
        cout << "\n1. Khoi tao danh sach";
        cout << "\n2. Nhap danh sach sinh vien";
        cout << "\n3. Xuat danh sach sinh vien";
        cout << "\n4. Chinh thong tin 1 sinh vien";
        cout << "\n5. Them sinh vien";
        cout << "\n6. Xoa sinh vien";
        cout << "\n7. Tim sinh vien theo MSSV";
        cout << "\n8. Sap xep danh sach theo diem trung binh giam dan";
        cout << "\n9. Dem so luong sinh vien co DTB tu 2 tro len";
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
            khoiTao(listSV);
            cout << "\nKhoi tao thanh cong!!!";
        }

        else if (chon == 2)
        {
            int flag = 0;
            do
            {
                Node *sinhVien = nhapMotSinhVien();
                themMotSinhVienvaoCuoi(listSV, sinhVien->infor);

                cout << "\nCo muon nhap nua khong? \n1. Co\n0.Khong\nChon di: ";
                cin >> flag;
            } while (flag);
        }

        else if (chon == 3)
        {
            xuatDanhSachSinhVien(listSV);
        }

        else if (chon == 4)
        {
            string mssv;
            cout << "\nNhap ma so sinh vien de sua thong tin: ";
            cin >> mssv;
            Node *SinhVien = timKiem(listSV, mssv);
            hieuChinhThongTin(SinhVien->infor);
        }

        else if (chon == 5)
        {
            cout << "\nThem thong tin sinh vien vao cuoi danh sach";

            Node *sv = nhapMotSinhVien();
            themMotSinhVienvaoCuoi(listSV, sv->infor);
        }

        else if (chon == 6)
        {
            string mssv;
            cout << "\nNhap ma so sinh vien de xoa sinh vien: ";
            cin >> mssv;
            xoaSinhVien(listSV, mssv);
        }

        else if (chon == 7)
        {
            string mssv;
            cout << "\nNhap ma so sinh vien ban muon xem: ";
            cin >> mssv;

            xemThongTin(listSV, mssv);
        }

        else if (chon == 8)
        {
            sapXepDTBGiamDan(listSV);
        }

        else if (chon == 9)
        {
            cout << "\nCo " << demSoSinhVienTren5Diem(listSV) << " sinh vien tren 5 diem";
        }

        cout << endl;
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
    Node *p = new Node;
    cin.ignore();
    cout << "\nNhap ma so sinh vien: ";
    getline(cin, p->infor.maSoSinhVien);
    cout << "Nhap ho va ten: ";
    getline(cin, p->infor.hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, p->infor.gioiTinh);
    cout << "Nhap dia chi: ";
    getline(cin, p->infor.diaChi);
    cout << "Nhap nam sinh: ";
    cin >> p->infor.namSinh;
    cout << "Nhap diem trung binh: ";
    cin >> p->infor.diemTrungBinh;

    return p;
}

void themMotSinhVienvaoCuoi(list &l, SinhVien sv)
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
            q = q->link;
        q->link = p;
    }
}

void xuatMotSinhVien(SinhVien sv)
{
    cout << "\nMa so sinh vien: " << sv.maSoSinhVien;
    cout << "\nHo va ten: " << sv.hoTen;
    cout << "\nGioi tinh: " << sv.gioiTinh;
    cout << "\nDia chi: " << sv.diaChi;
    cout << "\nNam sinh: " << sv.namSinh;
    cout << "\nDiem trung binh: " << sv.diemTrungBinh;
    cout << "\n\n==================================================\n";
}

void xuatDanhSachSinhVien(list l)
{
    Node *p = l.first;
    while (p != NULL)
    {
        xuatMotSinhVien(p->infor);
        p = p->link;
    }
}

Node *timKiem(list l, string maSoSV)
{
    Node *p = l.first;
    while (p != NULL && p->infor.maSoSinhVien != maSoSV)
        p = p->link;

    return p;
}

void hieuChinhThongTin(SinhVien &sv)
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

void xemThongTin(list l, string maSoSV)
{
    Node *p = l.first;
    while (p != NULL)
    {
        if (p->infor.maSoSinhVien == maSoSV)
        {
            xuatMotSinhVien(p->infor);
            break;
        }
        p = p->link;
    }
}

void sapXepDTBGiamDan(list l)
{
    for (Node *i = l.first; i != NULL; i = i->link)
    {
        for (Node *j = l.first; j != NULL; j = j->link)
        {
            if (i->infor.diemTrungBinh > j->infor.diemTrungBinh)
            {
                swap(i->infor, j->infor);
            }
        }
    }
}

int demSoSinhVienTren5Diem(list l)
{
    int count = 0;
    Node *p = l.first;
    while (p != NULL)
    {
        if (p->infor.diemTrungBinh >= 5)
            count++;
        p = p->link;
    }
    return count;
}

int xoaDau(list &l)
{
    Node *p = l.first;
    if (l.first != NULL)
    {
        l.first = l.first->link;
        delete p;
        return 1;
    }
    return 0;
}

int xoaCuoi(list &l)
{
    if (l.first != NULL)
    {
        Node *p = l.first;
        Node *q = NULL;

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

int doDaiDanhSach(list l)
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

Node *timNodeCuoi(list l)
{
    Node *p = l.first;
    while (p->link != NULL)
        p = p->link;

    return p;
}

int xoaSinhVien(list &l, string mssv)
{
    Node *p = l.first;
    if (l.first != NULL)
    {
        Node *last = timNodeCuoi(l);
        if (mssv == l.first->infor.maSoSinhVien)
        {
            xoaDau(l);
            return 1;
        }
        else if (mssv == last->infor.maSoSinhVien)
        {
            xoaCuoi(l);
            return 1;
        }
        else
        {
            Node *xoa = timKiem(l, mssv);
            Node *q = l.first;
            Node *p = xoa->link;
            while (q->link != xoa)
            {
                q = q->link;
            }

            q->link = p;
            delete xoa;
            return 1;
        }
    }

    return 0;
}

