#include <iostream>
using namespace std;
void ham_XuatMang(int a[4][5]);
int ham_TinhTong(int a[4][5]);
int ham_TongtrenDong(int a[4][5], int K);
int ham_TongtrenCot(int a[4][5], int L);
void ham_InCacSoNhoHonI(int a[4][5], int I);
bool KTraSoNgTo(int n);
void ham_InMangSoNguyenTo(int a[4][5]);
int DemSoNgTo(int a[4][5]);
void ham_SapXepCacPhanTuTheoHang(int a[4][5], int b[5][4]);
void ham_XuatPhanTuTheoHang(int b[5][4]);

int b[5][4];
int a[4][5] = {
				{1, 2, 3, 4, 5},
				{2, 4, 6, 8, 10},
				{1, 3, 5, 7, 9},
				{4, 6, 3, 1, 9}
			  };


int main()
{
	do
	{
		system("cls");
		cout << "\n\t\t\t\t=== MENU CHON LUA ===\n";
		cout <<"\n\tMANG a\n\n";
		ham_XuatMang(a);
		cout << "\n 1- In ra tong cac gia tri trong mang nay.";
		cout << "\n 2- Nhap so nguyen K: In ra tong cac so o hang K.";
		cout << "\n 3- Nhap so nguyen L: In ra tong cac so o cot L.";
		cout << "\n 4- Nhap so nguyen I: In ra cac so trong mang co gia tri < I cung vi tri cua no.";
		cout << "\n 5- In ra cac so nguyen to trong mang (cung voi vi tri cua no) va cho biet mang co bao nhieu so nguyen to.";
		cout << "\n 6- In ra man hinh cac phan tu trong mang (theo thu tu hang).";
		cout << "\n 7- Ket Thuc chuong trinh.";

		int luachon;
		do
		{
			cout << "\n\n Moi ban chon tu 1 toi 7";
			cout << "\n Nhap: ";
			cin >> luachon;
		}while(luachon < 1 || luachon > 7);

		if(luachon == 1)
		{
			cout << "\n Tinh tong";
			cout << "\n Tong cua mang la: " << ham_TinhTong(a);
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 2)
		{
			int K;
			cout << "\n Tinh tong tren dong.";
			do
			{
				cout << "\n Chon cot so (1 - 4): ";
				cin >> K;
			}while(K < 1 || K > 4);

			cout << " Tong tren dong thu " << K << " la = " << ham_TongtrenDong(a, K);
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 3)
		{
			int L;
			cout << "\n Tinh tong tren cot.";
			do
			{
				cout << "\n Chon cot so (1 - 5): ";
				cin >> L;
			}while(L < 1 || L > 5);

			cout << " Tong tren cot thu " << L << " la = " << ham_TongtrenCot(a, L);
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 4)
		{
			int I;
			cout << "\n Xuat Mang co gia tri nho hon I.";
			do
			{
				cout << "\n Nhap gia tri I: ";
				cin >> I;
			}while(I < 0);

			cout << "\n Mang a: \n\n";
			ham_InCacSoNhoHonI(a, I);
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 5)
		{
			cout << "\n In ra cac so nguyen to co trong mang.";
			cout << "\n Mang a: \n\n";
			ham_InMangSoNguyenTo(a);
			cout << " Co " << DemSoNgTo(a) << " so nguyen to trong mang";
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 6)
		{
			cout << "\n In cac phan tu trong mang ( theo thu tu hang ).";
			cout << "\n Mang a: \n\n";
			ham_SapXepCacPhanTuTheoHang(a, b);
			ham_XuatPhanTuTheoHang(b);
			cout << "\n An phim bat ki de tiep tuc\n\n";
			system("pause");
		}

		if(luachon == 7)
		{
			cout << "\n\t\t === KET THUC ===\n\n";
			break;
		}

	}while(1);

	system("pause");
	return 0;
}

void ham_XuatMang(int a[4][5])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int ham_TinhTong(int a[4][5])
{
	int tong = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			tong = tong + a[i][j];
		}
	}
	return tong;
}

int ham_TongtrenDong(int a[4][5], int K)
{
	int tong = 0;
	for(int j = 0; j < 5; j++)
	{
		tong = tong + a[K - 1][j];
	}
	return tong;
}

int ham_TongtrenCot(int a[4][5], int L)
{
	int tong = 0;
	for(int i = 0; i < 4; i++)
	{
		tong = tong + a[i][L - 1];
	}
	return tong;
}

void ham_InCacSoNhoHonI(int a[4][5], int I)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(a[i][j] < I)
			{
				cout << a[i][j] << " ";
			}
			else
			{
				cout << "X ";
			}
		}
		cout << endl;
	}
}

bool KTraSoNgTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        if (n == 2)
        {
            return true;
        }
        else
        {
            if (n % 2 == 0)
            {
                return false;
            }
            else
            {
                if (n % 2 != 0)
                {
                    for (int i = 2; i < n; i++)
                    {
                        if (n % i == 0)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

void ham_InMangSoNguyenTo(int a[4][5])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(KTraSoNgTo(a[i][j]) == true)
			{
				cout << a[i][j] << " ";
			}
			else
			{
				cout << "X ";
			}
			
		}
		cout << endl;
	}
}

int DemSoNgTo(int a[4][5])
{
	int SoLuong = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(KTraSoNgTo(a[i][j]))
			{
				SoLuong++;
			}
		}
	}
	return SoLuong;
}

void ham_SapXepCacPhanTuTheoHang(int a[4][5], int b[5][4])
{
	for(int j = 0; j < 4; j++)
	{
		for(int i = 0; i < 5; i++)
		{
			b[i][j] = a[j][i];
		}
	}
}

void ham_XuatPhanTuTheoHang(int b[5][4])
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}