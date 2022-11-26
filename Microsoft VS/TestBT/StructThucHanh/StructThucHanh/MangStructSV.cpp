#include <iostream>
#include <cmath>
#include <string>
const int MAX = 45;
using namespace std;
void ham_NhapSinhVien(struct SinhVien DS[MAX + 1], int &n);
void ham_XuatToanBoSinhVien(struct SinhVien DS[MAX + 1], int n);
void ham_XuatSinhVienTheoSoThuTu(struct SinhVien DS[MAX + 1], int &stt, int n);
void ham_XuatToanBoCacThongTinCuaSinhVien(struct SinhVien DS[MAX + 1], int n);
double ham_TinhDiemTB(struct SinhVien DS[MAX + 1], int stt);
void ham_XepLoai(struct SinhVien DS[MAX + 1], int stt);

struct NTN // NTN = Ngày Tháng Năm
{
	int ngay, thang, nam;
};

struct SinhVien
{
	string mssv;
	string hoten;
	string diachi;
	NTN ngaysinh;
	double diemToan;
	double diemVan;
	double diemNgoaiNgu;
};

int main()
{
	SinhVien DS[MAX + 1];
	int n, stt;
	cout << "\n\t\t\t============NHAP THONG TIN SINH VIEN============\n\n";
	ham_NhapSinhVien(DS, n);
	do
	{
		system("cls");
		cout << "\n\t\t\t============XUAT THONG TIN SINH VIEN============\n\n";

		/* ****************XUẤT TOÀN BỘ THÔNG TIN SINH VIÊN ĐÃ NHẬP**********************/
		//ham_XuatToanBoCacThongTinCuaSinhVien(DS, n);

		/* ****************XUẤT THÔNG TIN SINH VIÊN ĐÃ NHẬP THEO SỐ THỨ TỰ**********************/

		ham_XuatSinhVienTheoSoThuTu(DS, stt, n);
		cout << "Diem trung binh la: " << ham_TinhDiemTB(DS, stt);
		ham_XepLoai(DS, stt);

		cout << endl;
		system("pause");

	} while (1);

	cout << endl;
	system("pause");
	return 0;
}

void ham_NhapSinhVien(struct SinhVien DS[MAX + 1], int &n)
{
	cout << "\nBan muon nhap vao bao nhieu sinh vien: ";
	cin >> n;
	fflush(stdin);
	for (int i = 1; i <= n; i++)
	{
		cout << "\n\tSINH VIEN THU " << i;
		cout << "\nNhap ma so sinh vien: ";
		getline(cin, DS[i].mssv);
		cout << "Nhap ho ten sinh vien: ";
		getline(cin, DS[i].hoten);
		cout << "Nhap dia chi sinh vien: ";
		getline(cin, DS[i].diachi);
		cout << "Nhap ngay sinh sinh vien: ";
		cin >> DS[i].ngaysinh.ngay;
		cout << "Nhap thang sinh sinh vien: ";
		cin >> DS[i].ngaysinh.thang;
		cout << "Nhap nam sinh sinh vien: ";
		cin >> DS[i].ngaysinh.nam;
		cout << "Nhap diem mon Toan: ";
		cin >> DS[i].diemToan;
		cout << "Nhap diem mon Van: ";
		cin >> DS[i].diemVan;
		cout << "Nhap diem mon Ngoai Ngu: ";
		cin >> DS[i].diemNgoaiNgu;
		fflush(stdin);
	}
}

void ham_XuatToanBoSinhVien(struct SinhVien DS[MAX + 1], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "\n\t SINH VIEN THU " << i;
		cout << "\nMa so sinh vien: " << DS[i].mssv;
		cout << "\nHo ten sinh vien: " << DS[i].hoten;
		cout << "\nDia chi sinh vien: " << DS[i].diachi;
		cout << "\nNgay Thang Nam sinh sinh vien: " << DS[i].ngaysinh.ngay << '/' << DS[i].ngaysinh.thang << '/' << DS[i].ngaysinh.nam;
		cout << "\nDiem mon Toan: " << DS[i].diemToan;
		cout << "\nDiem mon Van: " << DS[i].diemVan;
		cout << "\nDiem mon Ngoai Ngu: " << DS[i].diemNgoaiNgu;
		cout << endl;
	}
}

void ham_XuatToanBoCacThongTinCuaSinhVien(struct SinhVien DS[MAX + 1], int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << "\n\t SINH VIEN THU " << i;
		cout << "\nMa so sinh vien: " << DS[i].mssv;
		cout << "\nHo ten sinh vien: " << DS[i].hoten;
		cout << "\nDia chi sinh vien: " << DS[i].diachi;
		cout << "\nNgay Thang Nam sinh sinh vien: " << DS[i].ngaysinh.ngay << '/' << DS[i].ngaysinh.thang << '/' << DS[i].ngaysinh.nam;
		cout << "\nDiem mon Toan: " << DS[i].diemToan;
		cout << "\nDiem mon Van: " << DS[i].diemVan;
		cout << "\nDiem mon Ngoai Ngu: " << DS[i].diemNgoaiNgu;
		cout << "\nDiem trung binh: " << ham_TinhDiemTB(DS, i);
		ham_XepLoai(DS, i);
		cout << endl;
	}
}

double ham_TinhDiemTB(struct SinhVien DS[MAX + 1], int stt)
{
	return ((DS[stt].diemToan + DS[stt].diemVan) * 2 + DS[stt].diemNgoaiNgu) / 5;
}

void ham_XuatSinhVienTheoSoThuTu(struct SinhVien DS[MAX + 1], int &stt, int n)
{
	do
	{
		cout << "\n\nNhap so thu tu sinh vien ban muon xem thong tin: ";
		cin >> stt;
	} while (stt < 0 || stt > n);
	cout << "\n\t SINH VIEN THU " << stt;
	cout << "\nMa so sinh vien: " << DS[stt].mssv;
	cout << "\nHo ten sinh vien: " << DS[stt].hoten;
	cout << "\nDia chi sinh vien: " << DS[stt].diachi;
	cout << "\nNgay Thang Nam sinh sinh vien: " << DS[stt].ngaysinh.ngay << '/' << DS[stt].ngaysinh.thang << '/' << DS[stt].ngaysinh.nam;
	cout << "\nDiem mon Toan: " << DS[stt].diemToan;
	cout << "\nDiem mon Van: " << DS[stt].diemVan;
	cout << "\nDiem mon Ngoai Ngu: " << DS[stt].diemNgoaiNgu;
	cout << endl;
}

void ham_XepLoai(struct SinhVien DS[MAX + 1], int stt)
{
	if (ham_TinhDiemTB(DS, stt) >= 8)
	{
		cout << "\nXep loai Gioi";
	}
	else if (ham_TinhDiemTB(DS, stt) >= 6.5)
	{
		cout << "\nXep loai Kha";
	}
	else if (ham_TinhDiemTB(DS, stt) >= 5)
	{
		cout << "\nXep loai Trung Binh";
	}
	else
	{
		cout << "\nXep loai Duoi Trung Binh";
	}
}
