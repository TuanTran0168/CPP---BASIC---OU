#include <iostream>
using namespace std;
void ham_NhapMang(int a[], int &Maxsize);
void ham_XuatMang(int a[], int Maxsize);
void ham_XoaPhanTuTrongMang(int a[], int &Maxsize, int &k);
void ham_ThemPhanTuTrongMang(int a[], int &Maxsize, int &x, int &k);
void ham_Xoa(int a[], int &Maxsize, int &k);
void ham_XoaTrung(int a[], int &Maxsize);
int ham_Dem(int a[], int Maxsize, int &x);
int ham_TimMax(int a[], int Maxsize);
int main()
{
	int a[1000];
	int Maxsize;
	int x;
	ham_NhapMang(a, Maxsize);
	//ham_ThemPhanTuTrongMang(a, Maxsize, x, k);
	//ham_XoaPhanTuTrongMang(a, Maxsize, k);
	//ham_XoaTrung(a, Maxsize);
	//cout<<"Gia tri "<< x << " Xuat hien: "<<ham_Dem(a, Maxsize,x) <<" lan\n";
	//cout<<"Gia tri lon nhat la: " <<ham_TimMax(a, Maxsize);
	//ham_XuatMang(a, Maxsize);
	system("pause");
	return 0;
}

void ham_NhapMang(int a[], int &Maxsize)
{
	cout<<"Nhap do lon: ";
	cin>>Maxsize;
	for(int i = 0; i < Maxsize; i++)
	{
		cout<<"Nhap phan tu thu "<< i + 1 <<": ";
		cin>> a[i];
	}
}

void ham_XuatMang(int a[], int Maxsize)
{
	for(int i = 0; i < Maxsize; i++)
	{
		cout<< a[i] << " ";
	}
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

void ham_ThemPhanTuTrongMang(int a[], int &Maxsize, int &x, int &k)
{
	cout<<"Nhap gia tri ban muon them: ";
	cin>> x;
	cout<<"Nhap vi tri ban muon them: ";
	cin>>k;
	for(int i = Maxsize; i >= k - 1; i--)
	{
		a[i + 1] = a[i];
	}
	a[k - 1] = x;
	Maxsize++;
}

void ham_Xoa(int a[], int &Maxsize, int &k)
{
	for(int i = k; i < Maxsize; i++)
	{
		a[i - 1] = a[i];
	}
	Maxsize--;
}

void ham_XoaTrung(int a[], int &Maxsize)
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
	cout<<"Nhap gia tri ban muon tim: ";
	cin>>x;
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

