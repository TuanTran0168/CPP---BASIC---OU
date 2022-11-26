#include <iostream>
#include <string>
using namespace std;

void ham_NhapMang(int a[], int &Maxsize);
void ham_Xuatmang(int a[], int Maxsize);
void ham_SapXepMangTangDan(int a[], int Maxsize);
void ham_SapXepMangGiamDan(int a[], int Maxsize);
bool ham_KTraSoNguyenTo(int so);
int ham_TinhGiaiThua(int so);
int ham_TinhTong(int a, int b);
bool ham_KTraSoHoanThien(int so);
int ham_TinhToHopC(int n, int k);
void ham_XuatTamGiacPascal(int h);
void ham_XuatHinhVuongRong(int h);
void ham_XuatTamGiacRong(int h);
int ham_TinhTongMang(int a[], int Maxsize);
void ham_XuatCacSoNguyenToTrongMang(int a[], int Maxsize);
void ham_XuatCacSoHoanThienTrongMang(int a[], int Maxsize);
void ham_ThemPhanTuVaoMang(int a[], int &Maxsize, int x, int k);
void ham_XoaPhanTuTrongMang(int a[], int &Maxsize, int &k);
void ham_Xoa(int a[], int &Maxsize, int &k);
void ham_XoaCacPhanTuTrung(int a[], int &Maxsize);
int ham_Dem(int a[], int Maxsize, int &x);
int ham_TimMax(int a[], int Maxsize);

int main()
{
	int choose;
	cout << "\n\n\t\t\t\t\t========MENU========\n";
	cout << "\nCau 1: Nhap vao mot so bat ki, cho biet so do co phai So Nguyen To hay khong ?";
	cout << "\nCau 2: Nhap vao mot so nguyen duong, cho biet so do co phai So Hoan Thien hay khong ?";
	cout << "\nCau 3: Nhap vao mot so nguyen duong, tinh Giai Thua";
	cout << "\nCau 4: Nhap vao mot chieu cao la so nguyen duong, Xuat Hinh Vuong Rong";
	cout << "\nCau 5: Nhap vao mot chieu cao la so nguyen duong, Xuat hinh Tam Giac Rong";
	cout << "\nCau 6: Nhap vao mot chieu cao la so nguyen duong, Xuat Tam Giac Pascal";
	cout << "\nCau 7: Nhap cac phan tu trong mang tu ban phim la so nguyen, Tinh Tong cac phan tu do";
	cout << "\nCau 8: Nhap cac phan tu trong mang tu ban phim la so nguyen, Xuat cac So Nguyen To trong mang";
	cout << "\nCau 9: Nhap cac phan tu trong mang tu ban phim la so nguyen, Xuat cac So Hoan Thien trong mang";
	cout << "\nCau 10: Nhap cac phan tu trong mang tu ban phim la so nguyen, Sap Xep cac phan tu trong mang Tang Dan";
	cout << "\nCau 11:Nhap cac phan tu trong mang tu ban phim la so nguyen, Sap Xep cac phan tu trong mang Giam Dan";
	cout << "\nCau 12:Nhap cac phan tu trong mang tu ban phim la so nguyen, Them cac phan tu vao mang";
	cout << "\nCau 13:Nhap cac phan tu trong mang tu ban phim la so nguyen, Xoa cac phan tu trong mang";
	cout << "\nCau 14:Nhap cac phan tu trong mang tu ban phim la so nguyen, Xoa cac phan tu trung nhau trong mang";
	cout << "\nCau 15:Nhap cac phan tu trong mang tu ban phim la so nguyen, Dem so lan cac phan tu giong nhau xuat hien trong mang";
	cout << "\nCau 16:Nhap cac phan tu trong mang tu ban phim la so nguyen, Tim gia tri lon nhat trong mang";


	cout << "\n\n\t\t\t\t=======NHAP SO 0 DE DUNG LAI=======\n";
	do
	{
		cout << "\n\nBan muon lam cau may (chon tu 1 - 16)";
		cout << "\nNhap: ";
		cin >> choose;
		if (choose == 1)
		{
			cout << "\nCau 1: \n";
			int so;
			cout << "Nhap so bat ki: ";
			cin >> so;
			if (ham_KTraSoNguyenTo(so) == true)
			{
				cout << "So " << so << " la so nguyen to \n";
			}
			else
			{
				cout << "So " << so << " khong phai la so nguyen to \n";
			}
		}

		if (choose == 2)
		{
			cout << "\nCau 2: \n";
			int so;
			do
			{
				cout << "Nhap so nguyen duong: ";
				cin >> so;
				if (so <= 0)
				{
					cout << "Khong dung yeu cau de bai, moi nhap lai!\n";
					system("pause");
				}
				else
				{
					if (ham_KTraSoHoanThien(so) == true)
					{
						cout << "So " << so << " la so hoan thien \n";
					}
					else
					{
						cout << "So " << so << " khong phai la so hoan thien \n";
					}
				}
			} while (so <= 0);
		}

		if (choose == 3)
		{
			cout << "\nCau 3: \n";
			int so;
			do
			{
				cout << "Nhap so nguyen duong: ";
				cin >> so;
				if (so <= 0)
				{
					cout << "Khong dung yeu cau de bai, moi nhap lai!\n";
					system("pause");
				}
				else
				{
					cout << so << "! =" << ham_TinhGiaiThua(so);
				}
			} while (so <= 0);
		}

		if (choose == 4)
		{
			cout << "\nCau 4: \n";
			int so;
			do
			{
				cout << "Nhap chieu cao hinh vuong la so nguyen duong: ";
				cin >> so;
				if (so <= 0)
				{
					cout << "Khong dung yeu cau de bai, moi nhap lai!\n";
					system("pause");
				}
				else
				{
					ham_XuatHinhVuongRong(so);
				}
			} while (so <= 0);
		}

		if (choose == 5)
		{
			cout << "\nCau 5: \n";
			int so;
			do
			{
				cout << "Nhap chieu cao tam giac la so nguyen duong: ";
				cin >> so;
				if (so <= 0)
				{
					cout << "Khong dung yeu cau de bai, moi nhap lai!\n";
					system("pause");
				}
				else
				{
					ham_XuatTamGiacRong(so);
				}
			} while (so <= 0);
		}

		if (choose == 6)
		{
			cout << "\nCau 6: \n";
			int so;
			do
			{
				cout << "Nhap chieu cao tam giac Pascal la so nguyen duong: ";
				cin >> so;
				if (so <= 0)
				{
					cout << "Khong dung yeu cau de bai, moi nhap lai!\n";
					system("pause");
				}
				else
				{
					ham_XuatTamGiacPascal(so);
				}
			} while (so <= 0);
		}

		if (choose == 7)
		{
			cout << "\nCau 7: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout << "Tong cac phan tu trong mang la: " << ham_TinhTongMang(a, Maxsize);
		}

		if (choose == 8)
		{
			cout << "\nCau 8: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout << "Cac so nguyen to la: ";
			ham_XuatCacSoNguyenToTrongMang(a, Maxsize);
		}

		if (choose == 9)
		{
			cout << "\nCau 9: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout << "Cac so hoan thien la: ";
			ham_XuatCacSoHoanThienTrongMang(a, Maxsize);
		}

		if (choose == 10)
		{
			cout << "\nCau 10: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout << "Cac phan tu duoc sap xep tang dan: ";
			ham_SapXepMangTangDan(a, Maxsize);
			ham_Xuatmang(a, Maxsize);
		}

		if (choose == 11)
		{
			cout << "\nCau 11: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout << "Cac phan tu duoc sap xep giam dan: ";
			ham_SapXepMangGiamDan(a, Maxsize);
			ham_Xuatmang(a, Maxsize);
		}

		if (choose == 12)
		{
			cout << "\nCau 12: \n";
			int a[1000];
			int Maxsize;
			int x;
			int k;
			ham_NhapMang(a, Maxsize);
			ham_ThemPhanTuVaoMang(a, Maxsize, x, k);
			ham_Xuatmang(a, Maxsize);
		}

		if (choose == 13)
		{
			cout << "\nCau 13: \n";
			int a[1000];
			int Maxsize;
			int k;
			ham_NhapMang(a, Maxsize);
			ham_XoaPhanTuTrongMang(a, Maxsize, k);
			ham_Xuatmang(a, Maxsize);
		}

		
		if (choose == 14)
		{
			cout << "\nCau 14: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			ham_XoaCacPhanTuTrung(a, Maxsize);
			cout<<"Mang sau khi duoc xoa cac phan tu trung: ";
			ham_Xuatmang(a, Maxsize);
		}

		if (choose == 15)
		{
			cout << "\nCau 15: \n";
			int a[1000];
			int Maxsize;
			int x;
			ham_NhapMang(a, Maxsize);
			cout<<"Nhap gia tri ban muon tim: ";
			cin>>x;
			ham_Dem(a, Maxsize, x);
			cout<<"Phan tu "<< x <<" xuat hien " <<ham_Dem(a, Maxsize, x)<<" lan";
		}

		if (choose == 16)
		{
			cout << "\nCau 16: \n";
			int a[1000];
			int Maxsize;
			ham_NhapMang(a, Maxsize);
			cout<<"Gia tri lon nhat trong mang la "<<ham_TimMax(a, Maxsize);
		}

		if (choose == 0)
		{
			cout << "\n\t\t\t\t\t====KET THUC====\n\n";
			break;
		}

	} while (choose != 0);

	system("pause");
	return 0;
}

void ham_NhapMang(int a[], int &Maxsize)
{
	cout << "Nhap so luong phan tu cua mang: ";
	cin >> Maxsize;
	for (int i = 0; i < Maxsize; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
	cout << endl;
}

void ham_Xuatmang(int a[], int Maxsize)
{
	for (int i = 0; i < Maxsize; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void ham_SapXepMangTangDan(int a[], int Maxsize)
{
	int Min;
	for (int i = 0; i < Maxsize - 1; i++)
	{
		for (int j = i + 1; j < Maxsize; j++)
		{
			if (a[i] > a[j])
			{
				Min = a[i];
				a[i] = a[j];
				a[j] = Min;
			}
		}
	}
}

void ham_SapXepMangGiamDan(int a[], int Maxsize)
{
	int Max;
	for (int i = 0; i < Maxsize - 1; i++)
	{
		for (int j = i + 1; j < Maxsize; j++)
		{
			if (a[i] < a[j])
			{
				Max = a[i];
				a[i] = a[j];
				a[j] = Max;
			}
		}
	}
}

bool ham_KTraSoNguyenTo(int so)
{
	if (so < 2)
	{
		return false;
	}
	else if (so == 2)
	{
		return true;
	}
	else
	{
		for (int i = 2; i < so; i++)
		{
			if (so % i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int ham_TinhGiaiThua(int so)
{
	int KQ = 1;
	for (int i = 1; i <= so; i++)
	{
		KQ = KQ * i;
	}
	return KQ;
}

int ham_TinhTong(int a, int b)
{
	return a + b;
}

bool ham_KTraSoHoanThien(int so)
{
	int KQ = 0;
	for (int i = 1; i <= so / 2; i++)
	{
		if (so % i == 0)
		{
			KQ = KQ + i;
		}
	}
	if (KQ == so)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ham_TinhToHopC(int n, int k)
{
	return ham_TinhGiaiThua(n) / (ham_TinhGiaiThua(k) * ham_TinhGiaiThua(n - k));
}

void ham_XuatTamGiacPascal(int h)
{
	for (int i = 0; i <= h; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << ham_TinhToHopC(i, j) << " ";
		}
		cout << endl;
	}
}

void ham_XuatHinhVuongRong(int h)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			if (i == 1 || j == 1 || j == h || i == h)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void ham_XuatTamGiacRong(int h)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || i == j || i == h)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

int ham_TinhTongMang(int a[], int Maxsize)
{
	int KQ = 0;
	for (int i = 0; i < Maxsize; i++)
	{
		KQ = KQ + a[i];
	}
	return KQ;
}

void ham_XuatCacSoNguyenToTrongMang(int a[], int Maxsize)
{
	for (int i = 0; i < Maxsize; i++)
	{
		if (ham_KTraSoNguyenTo(a[i]) == true)
		{
			cout << a[i] << " ";
		}
	}
}

void ham_XuatCacSoHoanThienTrongMang(int a[], int Maxsize)
{
	for (int i = 0; i < Maxsize; i++)
	{
		if (ham_KTraSoHoanThien(a[i]) == true)
		{
			cout << a[i] << " ";
		}
	}
}

void ham_ThemPhanTuVaoMang(int a[], int &Maxsize, int x, int k)
{
	cout << "Nhap gia tri muon them: ";
	cin >> x;
	cout << "Nhap vi tri ban muon them: ";
	cin >> k;
	for (int i = Maxsize; i >= k - 1; i--)
	{
		a[i + 1] = a[i];
	}

	a[k - 1] = x;
	Maxsize++;
}

void ham_XoaPhanTuTrongMang(int a[], int &Maxsize, int &k)
{
	cout<<"Nhap vi tri can xoa: ";
	cin>>k;
	for(int i = k; i < Maxsize; i++)
	{
		a[i - 1] = a[i];
	}
	Maxsize--;
}

void ham_Xoa(int a[], int &Maxsize, int &k)
{
	for(int i = k; i < Maxsize; i++)
	{
		a[i - 1] = a[i];
	}
	Maxsize--;
}

void ham_XoaCacPhanTuTrung(int a[], int &Maxsize)
{
	for(int i = 0; i < Maxsize; i++)
	{
		for(int j = i + 1; j < Maxsize; j++)
		{
			if(a[i] == a[j])
			{
				ham_Xoa(a, Maxsize, j);
				i--;
			}
		}
	}
}

int ham_Dem(int a[], int Maxsize, int &x)
{
	int dem = 0;
	for(int i = 0; i < Maxsize; i++)
	{
		if(x == a[i])
		{
			dem++;
		}
	}
	return dem;
}

int ham_TimMax(int a[], int Maxsize)
{
	int Max = a[0];
	for(int i = 1; i < Maxsize; i++)
	{
		if(Max < a[i])
		{
			Max = a[i];
		}
	}
	return Max;
}
