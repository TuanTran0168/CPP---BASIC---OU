#include <iostream>
using namespace std;
// ==================== Tìm phần tử xuất hiện nhiều lần nhất ===========================
void ham_Nhap(int *&a, int &n);
void ham_Xuat(int *a, int n);
int ham_SoLanXuatHien_NhieuNhat(int *a, int n);
int ham_DemSoLanPhanTuXuatHien(int *a, int n, int vitri);
void ham_XuatPhanTuXuatHienNhieuNhat(int *a, int n);

// ==================== Kiểm tra ma trận có đối xứng qua đường chéo chính ma trận vuông  ===========================
void ham_NhapMang2Chieu(int **&a, int &Row, int &Col);
void ham_XuatMang2Chieu(int **a, int Row, int Col);
void ham_GiaiPhong(int **&a, int Row);
bool ham_KiemTraDoiXungTrenDuongCheoChinh(int **a, int Row, int Col);

int main()
{
    int **a;
    int Row, Col;

	ham_NhapMang2Chieu(a, Row, Col);
	ham_XuatMang2Chieu(a, Row, Col);

	cout << "\n" << *(*(a + 0) + 1);
	cout << "\n" << *(*(a + 1) + 0);
	cout << "\n" << *(*(a + 0) + 2);
	cout << "\n" << *(*(a + 2) + 0);
	cout << "\n" << *(*(a + 1) + 2);
	cout << "\n" << *(*(a + 2) + 1);

	if (ham_KiemTraDoiXungTrenDuongCheoChinh(a, Row, Col) == true)
	{
		cout << "\nMa tran doi xung!";
	}
	else
		cout << "\nMa tran khong doi xung!";

	ham_GiaiPhong(a, Row);
    system("pause");
    return 0;
}

// ==================== Tìm phần tử xuất hiện nhiều lần nhất ===========================

void ham_Nhap(int *&a, int &n)
{
    cout << "\tNhap so phan tu mang: ";
    cin >> n;
    cout << endl;

    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> *(a + i);
    }
}

void ham_Xuat(int *a, int n)
{
    cout << "\n\tXuat Mang\n";
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

int ham_SoLanXuatHien_NhieuNhat(int *a, int n) // Đếm số lần xuất hiện nhiều nhất
{
    int SoLanXuatHienNhieuNhat = 1;

    for (int i = 0; i < n; i++)
    {
        int count = 1; // Bắt đầu bằng 1 vì phần tử xuất hiện tối thiểu 1 lần
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) == *(a + j))
            {
                count++;
            }
        }

        if (count > SoLanXuatHienNhieuNhat)
        {
            SoLanXuatHienNhieuNhat = count;
        }
    }

    return SoLanXuatHienNhieuNhat;
}

int ham_DemSoLanPhanTuXuatHien(int *a, int n, int vitri) // Đếm số lần xuất hiện của từng phần tử trong mảng
{
    int count = 0;

    for (int i = vitri; i < n; i++)
    {
        if (*(a + vitri) == *(a + i))
        {
            count++;
        }
    }

    return count;
}

void ham_XuatPhanTuXuatHienNhieuNhat(int *a, int n)
{
    if (ham_SoLanXuatHien_NhieuNhat(a, n) > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (ham_DemSoLanPhanTuXuatHien(a, n, i) == ham_SoLanXuatHien_NhieuNhat(a, n))
            {
                cout << "\nPhan tu xuat hien nhieu nhat la: " << *(a + i);
            }
        }
        cout << "\nSo lan xuat hien la: " << ham_SoLanXuatHien_NhieuNhat(a, n) << endl;
    }
    else if (ham_SoLanXuatHien_NhieuNhat(a, n))
    {
        cout << "\nMoi phan tu xuat hien 1 lan!\n";
    }
}

// ==================== Kiểm tra ma trận có đối xứng qua đường chéo chính ma trận vuông  ===========================

void ham_NhapMang2Chieu(int **&a, int &Row, int &Col)
{
	cout << "Nhap so dong: ";
	cin >> Row;
	cout << "Nhap so cot: ";
	cin >> Col;

	a = new int *[Row];
	for (int i = 0; i < Row; i++)
	{
		*(a + i) = new int [Col];
	}

	for (int i = 0; i < Row; i++)
	{
		cout << "Nhap (" << Col << ") phan tu cho dong (" << i << ") \n";
		for (int j = 0; j < Col; j++)
		{
			cin >> *(*(a + i) + j);
		}
	}
}

void ham_XuatMang2Chieu(int **a, int Row, int Col)
{
	cout << "\n\tXuat Mang\n";

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
}

void ham_GiaiPhong(int **&a, int Row)
{
	for (int i = 0; i < Row; i++)
	{
		delete[] a[i];
	}

	delete a;
	a = NULL;
}

bool ham_KiemTraDoiXungTrenDuongCheoChinh(int **a, int Row, int Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			//if (*(a + (i * Col + j)) != *(a + (j * Col + i)))
			if (*(*(a + i) + j) != (*(*(a + j) + i)))
			//if (a[i][j] != a[j][i])
			{
				return false;
			}
		}
	}

	return true;
}