#include<iostream>
using namespace std;
#include<string> // khai báo thư viện chuỗi bên C++

// =================== KHAI BÁO CẤU TRÚC SINH VIÊN ===================
struct sinhvien
{
	string hoten;
	string mssv;
	float diem;
	
		
};

//==========================================================

// hàm nhập thông tin sinh viên
void Nhap_Thong_Tin_1_Thang_Sinh_Vien(struct sinhvien &sv)
{
	// nhập họ tên cho sinh viên
	fflush(stdin); // xóa bộ đệm
	cout << "\nNhap ho ten sinh vien: ";
	getline(cin, sv.hoten);

	// nhập mã số sinh viên
	fflush(stdin); // xóa bộ đệm
	cout << "\nNhap ma so sinh vien: ";
	getline(cin, sv.mssv);

	// nhập điểm cho sinh viên
	cout << "\nNhap diem sinh vien: ";
	cin >> sv.diem;
}

// hàm xuất thông tin sinh viên
void Xuat_Thong_Tin_1_Thang_Sinh_Vien(struct sinhvien sv)
{
	// xuất họ tên sinh viên
	cout << "\nHo ten sinh vien: " << sv.hoten;

	// xuất mã số sinh viên
	cout << "\nMa so sinh vien: " << sv.mssv;

	// xuất điểm sinh viên
	cout << "\nDiem sinh vien: " << sv.diem;
}

int main()
{
	struct sinhvien x; // khai báo ra 1 thằng sinh viên x
	struct sinhvien y; // khai báo ra 1 thằng sinh vien y
	cout << "\n\n\t\t NHAP THONG TIN SINH VIEN x\n";
	Nhap_Thong_Tin_1_Thang_Sinh_Vien(x);
	cout << "\n\n\t\t NHAP THONG TIN SINH VIEN y\n";
	Nhap_Thong_Tin_1_Thang_Sinh_Vien(y);

	cout << "\n\n\t\t THONG TIN SINH VIEN x \n";
	Xuat_Thong_Tin_1_Thang_Sinh_Vien(x);
	cout << "\n\n\t\t THONG TIN SINH VIEN y\n";
	Xuat_Thong_Tin_1_Thang_Sinh_Vien(y);


	system("pause");
	return 0;
}