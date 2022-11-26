#include <iostream>
#include <string>
using namespace std;
struct SanPham
{
    char MaSP[10];
    string TenSP;
    double DonGia;
    int SLTKho;
};
SanPham *SP;
SanPham *SPkp;
int SLSP;
void nhap();
void xuat();
void SuaThongTin();
void XoaThongTin(int &ViTriXoa);
int main()
{
    int ViTriXoa;
    nhap();
    xuat();
    SuaThongTin();
    xuat();
    XoaThongTin(ViTriXoa);
    xuat();
}
void nhap()
{
    do
    {
        cout << "Moi nhap so luong san pham: ";
        cin >> SLSP;
        cin.ignore(1);
    } while (SLSP > 30);
    SP = new SanPham[SLSP];
    SPkp = SP;
    for (int i = 0; i < SLSP; i++)
    {
        cout << "Moi nhap thong tin cho san pham thu " << i << endl;
        cout << "Moi nhap ma san pham: ";
        cin.getline(SPkp->MaSP, 10, '\n');
        cout << "Moi nhap ten san pham: ";
        getline(cin, SPkp->TenSP);
        cout << "Moi nhap don gia: ";
        cin >> SPkp->DonGia;
        cout << "Moi nhap so luong ton kho: ";
        cin >> SPkp->SLTKho;
        cin.ignore(1);
        SPkp++;
    }
}
void xuat()
{
    SPkp = SP;
    for (int i = 0; i < SLSP; i++)
    {
        cout << "Thong tin san pham thu " << i << endl;
        cout << "Ma san pham: " << SPkp->MaSP << endl;
        cout << "Ten san pham: " << SPkp->TenSP << endl;
        cout << "Don gia san pham: " << SPkp->DonGia << endl;
        cout << "So luong ton kho: " << SPkp->SLTKho << endl;
        SPkp++;
    }
}
void SuaThongTin()
{
    int TT;
    SPkp = SP;
    do
    {
        cout << "Moi nhap vi tri thong tin san pham can sua: ";
        cin >> TT;
        cin.ignore(1);
    } while (TT > SLSP - 1);
    cout << "Moi ban sua thong tin san pham thu " << TT << endl;
    SPkp + TT;
    cout << "Moi nhap ma san pham: ";
    cin.getline(SPkp->MaSP, 10, '\n');
    cout << "Moi nhap ten san pham: ";
    getline(cin, SPkp->TenSP);
    cout << "Moi nhap don gia: ";
    cin >> SPkp->DonGia;
    cout << "Moi nhap so luong ton kho: ";
    cin >> SPkp->SLTKho;
}
void XoaThongTin(int &ViTriXoa)
{
    SPkp = SP;
    do
    {
        cout << "Moi nhap vi tri thong tin san pham can xoa: ";
        cin >> ViTriXoa;
    } while (ViTriXoa < 0 || ViTriXoa >= SLSP);
    SPkp + ViTriXoa;
    for (int i = ViTriXoa; i < SLSP; i++)
        SPkp = SPkp + 1;
    SLSP--;
}