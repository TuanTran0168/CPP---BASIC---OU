#include <iostream>
#include <string>
using namespace std;
void ham_NhapMotCongDan(struct CCCD &a);
void ham_NhapNhieuCanCuoc(struct CCCD *&ptr, int &n);
void ham_NhapNhieuCanCuocString(struct CCCD *&ptr, int &n);
void ham_XuatMotCanCuoc(struct CCCD *ptr, int vitri);
void ham_XuatMotCanCuocString(struct CCCD *ptr, int vitri);
void ham_XuatNhieuCanCuoc(struct CCCD *ptr, int n);
void ham_XuatNhieuCanCuocString(struct CCCD *ptr, int n);
void ham_SapXepSoCanCuoc(struct CCCD *ptr, int n);
void ham_TimCanCuocCoCungMaNgauNhien(struct CCCD *ptr, int n);

struct CCCD
{
    int MaTinhThanh;
    int MaGioiTinh;
    int MaNamSinh;
    int SoNgauNhien;

    string MaTinhThanh1;
    string MaGioiTinh1;
    string MaNamSinh1;
    string SoNgauNhien1;
};

int main()
{
    int n;
    CCCD *ptr;
    /*ham_NhapNhieuCanCuoc(ptr, n);
	ham_XuatNhieuCanCuoc(ptr, n);*/

    ham_NhapNhieuCanCuocString(ptr, n);
    ham_XuatNhieuCanCuocString(ptr, n);

	ham_TimCanCuocCoCungMaNgauNhien(ptr, n);

    delete[] ptr;
    ptr = NULL;
    system("pause");
    return 0;
}

void ham_NhapMotCongDan(struct CCCD &a)
{
    cout << "\nNhap ma tinh thanh (3 chu so dau tien): ";
    cin >> a.MaTinhThanh;
    cout << "Nhap ma the ky va gioi tinh (1 chu so tiep theo): ";
    cin >> a.MaGioiTinh;
    cout << "Nhap ma nam sinh (2 chu so tiep theo): ";
    cin >> a.MaNamSinh;
    cout << "Nhap so ngau nhien (6 so cuoi cung): ";
    cin >> a.SoNgauNhien;
}

void ham_NhapNhieuCanCuoc(struct CCCD *&ptr, int &n)
{
    cout << "\nBan muon nhap bao nhieu can cuoc cong dan: ";
    cin >> n;

    ptr = new CCCD[n + 1]; // Cấp phát nhiều hơn 1 ô để bỏ ô số 0
    for (int i = 1; i <= n; i++)
    {
        cout << "\nNhap can cuoc cong dan thu " << i << ": \n";

        int count1;
        do
        {
            count1 = 0;
            cout << "Nhap ma tinh thanh (3 chu so dau tien): ";
            cin >> ptr[i].MaTinhThanh;

            int temp = ptr[i].MaTinhThanh;
            while (temp > 0)
            {
                temp = temp / 10;
                count1++;
            };

        } while (count1 > 3);

        int count2;
        do
        {
            count2 = 0;
            cout << "Nhap ma the ky va gioi tinh (1 chu so tiep theo): ";
            cin >> ptr[i].MaGioiTinh;

            int temp = ptr[i].MaGioiTinh;
            while (temp > 0)
            {
                temp = temp / 10;
                count2++;
            };

        } while (count2 > 1 || ptr[i].MaGioiTinh < 0 || ptr[i].MaGioiTinh > 9);

        int count3;
        do
        {
            count3 = 0;
            cout << "Nhap ma nam sinh (2 chu so tiep theo): ";
            cin >> ptr[i].MaNamSinh;

            int temp = ptr[i].MaNamSinh;
            while (temp > 0)
            {
                temp = temp / 10;
                count3++;
            };

        } while (count3 > 2);

        int count4;
        do
        {
            count4 = 0;
            cout << "Nhap so ngau nhien (6 so cuoi cung): ";
            cin >> ptr[i].SoNgauNhien;

            int temp = ptr[i].SoNgauNhien;
            while (temp > 0)
            {
                temp = temp / 10;
                count4++;
            };

        } while (count4 > 6);
    }
}

void ham_NhapNhieuCanCuocString(struct CCCD *&ptr, int &n)
{
    cout << "\nBan muon nhap bao nhieu can cuoc cong dan: ";
    cin >> n;

    ptr = new CCCD[n + 1]; // Cấp phát nhiều hơn 1 ô để bỏ ô số 0
    for (int i = 1; i <= n; i++)
    {
        cout << "\nNhap can cuoc cong dan thu " << i << ": \n";

        fflush(stdin);
        cout << "\nNhap ma tinh thanh (3 chu so dau tien): ";
        getline(cin, ptr[i].MaTinhThanh1);
        cout << "Nhap ma the ky va gioi tinh (1 chu so tiep theo): ";
        getline(cin, ptr[i].MaGioiTinh1);
        cout << "Nhap ma nam sinh (2 chu so tiep theo): ";
        getline(cin, ptr[i].MaNamSinh1);
        cout << "Nhap so ngau nhien (6 so cuoi cung): ";
        getline(cin, ptr[i].SoNgauNhien1);
    }
}

void ham_XuatMotCanCuoc(struct CCCD *ptr, int vitri)
{
    cout << "Ma tinh thanh (3 chu so dau tien): " << ptr[vitri].MaTinhThanh;
    cout << "\nMa the ky va gioi tinh (1 chu so tiep theo): " << ptr[vitri].MaGioiTinh;
    cout << "\nMa nam sinh (2 chu so tiep theo): " << ptr[vitri].MaNamSinh;
    cout << "\nSo ngau nhien (6 so cuoi cung): " << ptr[vitri].SoNgauNhien;
    cout << endl;
}

void ham_XuatMotCanCuocString(struct CCCD *ptr, int vitri)
{
    cout << "Ma tinh thanh (3 chu so dau tien): " << ptr[vitri].MaTinhThanh1;
    cout << "\nMa the ky va gioi tinh (1 chu so tiep theo): " << ptr[vitri].MaGioiTinh1;
    cout << "\nMa nam sinh (2 chu so tiep theo): " << ptr[vitri].MaNamSinh1;
    cout << "\nSo ngau nhien (6 so cuoi cung): " << ptr[vitri].SoNgauNhien1;
    cout << endl;
}

void ham_XuatNhieuCanCuoc(struct CCCD *ptr, int n)
{
    cout << "\n\tDANH SACH CAN CUOC CONG DAN: ";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nCan cuoc thu " << i << ": " << ptr[i].MaTinhThanh << ptr[i].MaGioiTinh << ptr[i].MaNamSinh << ptr[i].SoNgauNhien << endl;
        ham_XuatMotCanCuoc(ptr, i);
    }
}

void ham_XuatNhieuCanCuocString(struct CCCD *ptr, int n)
{
    cout << "\n\tDANH SACH CAN CUOC CONG DAN: ";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nCan cuoc thu " << i << ": " << ptr[i].MaTinhThanh1 << ptr[i].MaGioiTinh1 << ptr[i].MaNamSinh1 << ptr[i].SoNgauNhien1 << endl;
        ham_XuatMotCanCuocString(ptr, i);
    }
}

void ham_SapXepSoCanCuoc(struct CCCD *ptr, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if(ptr[i].SoNgauNhien1 > ptr[j].SoNgauNhien1)
			{
				swap(ptr[i], ptr[j]);
			}
		}
	}
}

void ham_TimCanCuocCoCungMaNgauNhien(struct CCCD *ptr, int n)
{
	ham_SapXepSoCanCuoc(ptr, n);
	cout << "\n\tCAC CAN CUOC CONG DAN CO CUNG MA NGAU NHIEN: \n";

	for (int i = 1; i <= n; i++)
	{
		if (ptr[i].SoNgauNhien1 == ptr[i + 1].SoNgauNhien1)
		{
			ham_XuatMotCanCuocString(ptr, i);
		}
	}
}