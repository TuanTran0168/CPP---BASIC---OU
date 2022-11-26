#include <iostream>
#include <string>
#include <fstream>
// ĐỀ THI NĂM 2019 :)
using namespace std;
int ham_TraSoLuong();
void ham_DocFileVaoStruct(struct KhoHang *&DS, int sl);
void ham_XuatMotKhoHang(struct KhoHang a);
void ham_XuatToanBoKhoHang(struct KhoHang *DS, int sl);
void ham_SuaThongTin(struct KhoHang *&DS, int sl, int &vitri, int &fix);
void ham_XuatKhoHangTaiTrongMax(struct KhoHang *DS, int sl);
void ham_MENU(int &select);

struct KhoHang
{
    string MaKho;
    string TenKho;
    string DiaChi;
    int TaiTrong;
};

int main()
{
    int select;
    KhoHang *DS;
    int n = ham_TraSoLuong();
    ham_DocFileVaoStruct(DS, n);
    do
    {
        system("cls");
        ham_MENU(select);

        if (select == 1)
        {
            ham_XuatToanBoKhoHang(DS, n);
        }

        if (select == 2)
        {
            int vitri, fix;
            ham_SuaThongTin(DS, n, vitri, fix);
        }

        if (select == 3)
        {
            ham_XuatKhoHangTaiTrongMax(DS, n);
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

int ham_TraSoLuong()
{
    int sl = 0;
    string temp;
    ifstream docFile;
    docFile.open("D:\\TXT\\DeThi2.txt", ios::in);

    if (docFile.is_open())
    {
        while (docFile.eof() == false)
        {
            getline(docFile, temp);
            sl++;
        }
    }

    docFile.close();

    return sl;
}

void ham_DocFileVaoStruct(struct KhoHang *&DS, int sl)
{
    int i = 0;
    DS = new KhoHang[sl];
    ifstream docFile;
    docFile.open("D:\\TXT\\DeThi2.txt", ios::in);

    if (docFile.is_open())
    {
        cout << "\nMo thanh cong!!!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, DS[i].MaKho, '#');
            getline(docFile, DS[i].TenKho, '#');
            getline(docFile, DS[i].DiaChi, '#');
            docFile >> DS[i].TaiTrong;
            docFile.ignore(1);
            i++;
        }
        docFile.close();
    }
    else
        cout << "\nKhong mo duoc!!!";
}

void ham_XuatMotKhoHang(struct KhoHang a)
{
    cout << "\nMa kho: " << a.MaKho;
    cout << "\nTen kho: " << a.TenKho;
    cout << "\nDia chi: " << a.DiaChi;
    cout << "\nTai trong: " << a.TaiTrong;
    cout << endl;
}

void ham_XuatToanBoKhoHang(struct KhoHang *DS, int sl)
{
    for (int i = 0; i < sl; i++)
    {
        cout << "\n\tSan pham thu: (" << i << ") ";
        ham_XuatMotKhoHang(DS[i]);
    }
}

void ham_SuaThongTin(struct KhoHang *&DS, int sl, int &vitri, int &fix)
{
    cout << "\nBan muon xoa san pham o vi tri nao ?:\n";
    do
    {
        cout << "Nhap: ";
        cin >> vitri;

    } while (vitri < 0 || vitri >= sl);

    cout << "\n\tSan pham thu: (" << vitri << ") ";
    ham_XuatMotKhoHang(DS[vitri]);

    cout << "\nBan muon sua thong tin gi?";
    cout << "\n1.Ma kho\n2.Ten kho\n3.Dia chi\n4.Tai trong\n";
    do
    {
        cout << "Nhap: ";
        cin >> fix;

    } while (fix < 1 || fix > 4);

    fflush(stdin);

    if (fix == 1)
    {
        cout << "\nMoi ban sua ma kho: ";
        getline(cin, DS[vitri].MaKho);
    }
    else if (fix == 2)
    {
        cout << "\nMoi ban sua ten kho: ";
        getline(cin, DS[vitri].TenKho);
    }
    else if (fix == 3)
    {
        cout << "\nMoi ban sua dia chi: ";
        getline(cin, DS[vitri].DiaChi);
    }
    else if (fix == 4)
    {
        cout << "\nMoi ban sua tai trong: ";
        cin >> DS[vitri].TaiTrong;
    }

    cout << "Sua thanh cong!!!\n";

    cout << "\n\tSan pham thu: (" << vitri << ") ";
    ham_XuatMotKhoHang(DS[vitri]);
}

void ham_XuatKhoHangTaiTrongMax(struct KhoHang *DS, int sl)
{
    int MAX = DS[0].TaiTrong;

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].TaiTrong > MAX)
        {
            MAX = DS[i].TaiTrong;
        }
    }

    for (int i = 0; i < sl; i++)
    {
        if (MAX == DS[i].TaiTrong)
        {
            ham_XuatMotKhoHang(DS[i]);
        }
    }
}

void ham_MENU(int &select)
{
    cout << "\n\t===========================* MENU *===========================\n";
    cout << "\n1. Xuat thong tin nhieu kho hang";
    cout << "\n2. Chinh sua thong tin bat ki do nguoi dung yeu cau";
    cout << "\n3. hien thi thong tin kho hang co trong tai lon nhat";
    cout << "\n4. Ket thuc chuong trinh";

    cout << "\n\nBan chon cau nao?";
    do
    {
        cout << "\nNhap: ";
        cin >> select;

    } while (select < 1 || select > 4);
}