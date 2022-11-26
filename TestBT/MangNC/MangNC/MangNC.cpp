#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
void HSNgoiDayK(string soDo[4][6],int k);
void HSViTriL(string SoDo[4][6],int L);
void HSDayKViTriL(string SoDo[4][6],int k,int L);
int demChoTrong(string SoDo[4][6]);
void SoDoLop(string SoDo[4][6]);
void DoiCho(string SoDo[4][6],int k1,int L1,int k2,int L2);
void timKiem(string SoDo[4][6],char kt);
int main()
{
	int n;
	string SoDo[4][6] = {
                                  {"An", "Tam","X","Huy","Lam","Truong"},
								  {"Binh", "Tan", "Dung", "Hoa", "X", "X"},
                                  {"Can", "X", "X", "X", "Anh", "X" },
								  {"Duy", "Duong","Hung","Quyen","Uyen","Cuong"}		
						 };
	do{
	system("cls");
	cout << "Menu\n1. in danh sach cac hoc sinh ngoi o day ban k\n2. in danh sach cac hoc sinh ngoi o cho thu L cua tat ca day ban\n3. in ten hoc sinh ngoi o day k vi tri L\n4. So cho trong\n5. in so do cho ngoi\n6. doi cho\n7. in ten cung vi tri ngoi cua hoc sinh khi nhap chu cai ten dau\n8. Thoat\n";
	cout << "Ban chon: ";
	cin >> n;
	switch (n)
	{
	case 1:
		int k;
		cout << "Nhap 1 so k: ";
		cin >> k;
		cout << "Cac hoc sinh day " << k << " la: ";
		HSNgoiDayK(SoDo,k);
		break;
	case 2:
		int L;
		cout << "Nhap 1 so L: ";
		cin >> L;
		cout << "Cac hoc sinh vi tri " << L << " la: ";
		HSViTriL(SoDo,L);
		break;
	case 3:
		cout << "Nhap hai so k va L(k < 6, L < 4): ";
		cin >> k >> L;
		cout << "Hoc sinh day " << k << " vi tri " << L << " la: ";
		HSDayKViTriL(SoDo,k,L);
		break;
	case 4:
		cout << "Co " << demChoTrong(SoDo) << " cho trong\n";
		break;
	case 5:
		SoDoLop(SoDo);
		break;
	case 6:
		int k1,L1,k2,L2;
		cout << "Nhap 4 so k1,L1,k2,L2: ";
		cin >> k1 >> L1 >> k2 >> L2;
		DoiCho(SoDo,k1,L1,k2,L2);
		cout << "Doi cho thanh cong. Muon xem chon so do lop\n";
		break;
	case 7:
		char kt;
		cout << "Nhap 1 ki tu in hoa: ";
		cin >> kt;
		timKiem(SoDo,kt);
		break;
	default:
		cout << "Ban chon Thoat\n";
	}
	_getch();
	}while (n >= 1 && n <= 7);
}
void HSNgoiDayK(string SoDo[4][6],int k)
{
	for (int i = 0; i < 4; i++)
		if (SoDo[i][k] != "X")
			cout << SoDo[i][k] << '\t';
}
void HSViTriL(string SoDo[4][6],int L)
{
	for (int j = 0; j < 6; j++)
		if (SoDo[L][j] != "X")
			cout << SoDo[L][j] << '\t';
}
void HSDayKViTriL(string SoDo[4][6],int k,int L)
{
			if (SoDo[L][k] != "X")
				cout << SoDo[L][k] << '\t';
			else
				cout << "Cho trong\n";
}
int demChoTrong(string SoDo[4][6])
{
	int dem = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			if (SoDo[i][j] == "X")
				dem++;
	return dem;
}
void SoDoLop(string SoDo[4][6])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << SoDo[i][j] << '\t';
		cout << endl;
	}
}
void DoiCho(string SoDo[4][6],int k1,int L1,int k2,int L2)
{
	string tam = SoDo[k1][L1];
	SoDo[k1][L1] = SoDo[k2][L2];
	SoDo[k2][L2] = tam;
}
void timKiem(string SoDo[4][6],char kt)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
		{
			string a = SoDo[i][j];
			for (int z = 0; z < 1; z++)
				if (a[z] == kt)
				cout << "SoDo[" << i << "][" << j << "]: " << SoDo[i][j] << endl;
		}
}