#include <iostream>
#include<string>
#include <fstream>
using namespace std;
const int MAX = 1000;
void ham_DocTapTin(int &sl);
void ham_InThongTinMotSinhVien(int sl);
void ham_TimSinhVienTheoMSSV(int sl);
void ham_NhapThongTinMotSinhVien(struct SinhVien &sv);
void ham_ThemSinhVienVaoDanhSach(int &sl, struct SinhVien x, int &vitri);
void ham_XoaSinhVienTrongDanhSach(int &sl, int &vitri);

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

int sl;
SinhVien DS[MAX + 1];

int main()
{
	int vitri;
	SinhVien x;
	ham_DocTapTin(sl);
	//ham_InThongTinMotSinhVien(5);
	//ham_TimSinhVienTheoMSSV(sl);
	//ham_ThemSinhVienVaoDanhSach(sl, x, vitri);
	ham_XoaSinhVienTrongDanhSach(

	for(int i = 1; i < sl; i++)
	{
		ham_InThongTinMotSinhVien(i);
		cout << endl;
	}

	system("pause");
	return 0;
}

void ham_DocTapTin(int &sl)
{
	ifstream docFile;
	docFile.open("D:\\TXT\\file.txt", ios::in);	// Chỗ này về tự đổi về địa chỉ tập tin trên máy của bạn
	if(docFile.is_open())
	{
		cout << "Mo thanh cong!!!\n\n";
		sl = 1;
		while(docFile.eof() == false)
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

void ham_InThongTinMotSinhVien(int sl)
{
	cout << "\nMSSV: " << DS[sl].MSSV;
	cout << "\nHo va Ten: " << DS[sl].Holot << " " << DS[sl].Ten;
	cout << "\nDiem mon 1: " << DS[sl].DiemMonHoc.Diem1;
	cout << "\nDiem mon 2: " << DS[sl].DiemMonHoc.Diem2;
	cout << "\nDiem trung binh: " << (DS[sl].DiemMonHoc.Diem1 + DS[sl].DiemMonHoc.Diem2) / 2;
}

void ham_TimSinhVienTheoMSSV(int sl)
{
	string MaSoSV;
	cout << "\nNhap MSSV: ";
	cin >> MaSoSV;
	int dem = 0;
	for(int i = 1; i < sl; i++)
	{
		if(MaSoSV == DS[i].MSSV)
		{
			ham_InThongTinMotSinhVien(i);
			dem++;
		}
	}

	if(dem == 0)
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

		for(int i = 1; i < sl; i++)
		{
			if(sv.MSSV == DS[i].MSSV)
			{
				dem++;
			}
		}

		if(dem > 0)
		{
			cout << "MSSV da ton tai, vui long nhap lai\n";
		}

	}while(dem > 0);

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
	cout << "\nNhap thong tin sinh vien tai vi tri thu " << vitri;
	ham_NhapThongTinMotSinhVien(x);

	for(int i = sl - 1; i >= vitri; i--)
	{
		DS[i + 1] = DS[i];
	}
	DS[vitri] = x;
	sl++;
}

void ham_XoaSinhVienTrongDanhSach(int &sl, int &vitri)
{
	cout << "Nhap vi tri ban muon xoa mot sinh vien: ";
	cin >> vitri;

	for(int i = vitri; i < sl; i++)
	{
		DS[i] = DS[i + 1];
		sl--;
	}
}

