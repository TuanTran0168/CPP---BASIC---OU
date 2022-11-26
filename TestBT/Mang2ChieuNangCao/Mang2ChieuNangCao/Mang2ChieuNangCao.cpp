#include <iostream> 
#include <string>
using namespace std;
void ham_InDayBanK(string SoDo[4][6], int K);
void ham_InDayBanL(string SoDo[4][6], int L);
void ham_InViTriKVaL(string SoDo[4][6], int K, int L);
int ham_ViTriTrong(string SoDo[4][6]);
void ham_InRaSoDo(string SoDo[4][6]);
void ham_TraoDoi(string SoDo[4][6], int K1, int L1, int K2, int L2);
void ham_InTenTheoKyTu(string SoDo[4][6], char KyTu);

string SoDo[5][6] = {

                                  {"An", "Tam","X","Huy","Lam","Truong"},

                                  {"Binh", "Tan", "Dung", "Hoa", "X", "X"},

                                  {"Can", "X", "X", "X", "Anh", "X" },

                                  {"Duy", "Duong","Hung","Quyen","Cuong","Danh"}

                    };

int main()
{
	do
	{
		system("cls");
		cout << "\n\t\t\t\t\t=== MENU CHON LUA ===\n";
		cout <<"\n\t\tSo Do Lop\n\n";
		ham_InRaSoDo(SoDo);
		cout << "\n 1- Nhap 1 so K, in ra danh sach hoc sinh ngoi o day ban K.";
		cout << "\n 2- Nhap 1 so L, in ra danh sach hoc sinh ngoi o cho thu L cua tat ca day ban.";
		cout << "\n 3- Nhap 2 so K va L, in ra ten hoc sinh ngoi o day K vi tri L.";
		cout << "\n 4- Cho biet co bao nhieu cho ngoi con trong.";
		cout << "\n 5- In ra so do cho ngoi len man hinh.";
		cout << "\n 6- Nhap 4 so K1, L1, K2, L2 sau do trao doi hoc sinh tai day K1 vi tri L1 voi hoc sinh ngoi day K2 vi tri L2.";
		cout << "\n 7- Nhap 1 ky tu, sau do in ra ten cung vi tri cho ngoi cua tat ca hoc sinh co ten bat dau tu ky tu nhap vao.";
		cout << "\n 8- Ket thuc chuong trinh.\n";

		int luachon;
		do
		{
			cout << "\n\n Moi ban chon tu 1 toi 8";
			cout << "\n Nhap: ";
			cin >> luachon;
		}while(luachon < 1 || luachon > 8); 

		if(luachon == 1)
		{
			int K;
			cout << "\n 1- Nhap 1 so K, in ra danh sach hoc sinh ngoi o day ban K.";
			do
			{
				cout << "\n Nhap so K (1 - 4): ";
				cin >> K;
			}while(K < 1 || K > 4);

			ham_InDayBanK(SoDo, K);
			cout << endl;
			system("pause");
		}

		if(luachon == 2)
		{
			int L;
			cout << "\n 2- Nhap 1 so L, in ra danh sach hoc sinh ngoi o cho thu L cua tat ca day ban.";
			do
			{
				cout << "\n Nhap so L (1 - 6): ";
				cin >> L;
			}while(L < 1 || L > 6);

			ham_InDayBanL(SoDo, L);
			system("pause");
		}

		if(luachon == 3)
		{
			int K, L;
			cout << "\n 3- Nhap 2 so K va L, in ra ten hoc sinh ngoi o day K vi tri L.";
			do
			{
				cout << "\n Nhap day K: ";
				cin >> K;
				cout << " Nhap vi tri L: ";
				cin >> L;
			}while(K < 1 || K > 4 || L < 1 || L > 6);

			ham_InViTriKVaL(SoDo, K, L);
			system("pause");
		}

		if(luachon == 4)
		{
			cout << "\n So do nay co " << ham_ViTriTrong(SoDo) << " vi tri con trong\n";
			system("pause");
		}

		if(luachon == 5)
		{
			cout << endl;
			ham_InRaSoDo(SoDo);
			system("pause");
		}

		if(luachon == 6)
		{
			int K1, L1, K2, L2;
			cout << "\n 6- Nhap 4 so K1, L1, K2, L2 sau do trao doi hoc sinh tai day K1 vi tri L1 voi hoc sinh ngoi day K2 vi tri L2.";
			do
			{
				cout << "\n Nhap day K1: ";
				cin >> K1;
				cout << " Nhap vi tri L1: ";
				cin >> L1;
			}while(K1 < 1 || K1 > 4 || L1 < 1 || L1 > 6);

			do
			{
				cout << "\n Nhap day K2: ";
				cin >> K2;
				cout << " Nhap vi tri L2: ";
				cin >> L2;
			}while(K2 < 1 || K2 > 4 || L2 < 1 || L2 > 6);

			ham_TraoDoi(SoDo, K1, L1, K2, L2);
			system("pause");
		}

		if(luachon == 7)
		{
			cout << "\n 7- Nhap 1 ky tu, sau do in ra ten cung vi tri cho ngoi cua tat ca hoc sinh co ten bat dau tu ky tu nhap vao.";
			char KyTu;
			cout << "\n Nhap chu cai in hoa dau tien cua ten hoc sinh: ";
			cin >> KyTu;

			ham_InTenTheoKyTu(SoDo, KyTu);
			system("pause");
		}

		if(luachon == 8)
		{
			cout << "\n\t\t\t === KET THUC ===\n\n";
			break;
		}
	}while(1);

	system("pause");
	return 0;
}


void ham_InDayBanK(string SoDo[4][6], int K)
{
	cout << " \n Cac hoc sinh ngoi o day ban thu " << K  << " la:  ";
	for(int j = 0; j < 6; j++)
	{
		if(SoDo[K - 1][j] != "X")
		{
			cout << SoDo[K - 1][j] << "\t";
		}
	}
}

void ham_InDayBanL(string SoDo[4][6], int L)
{
	cout << " \n Danh sach hoc sinh ngoi o to thu " << L << " cua tat ca day ban la:  \n\n";
	for(int i = 0; i < 4; i++)
	{
		if(SoDo[i][L - 1] != "X")
		{
			cout << " " << SoDo[i][L - 1] << "\n";
		}
	}
}

void ham_InViTriKVaL(string SoDo[4][6], int K, int L)
{
	if(SoDo[K - 1][L - 1] != "X")
	{
		cout << "\n Hoc sinh ngoi o day ban " << K << " va vi tri " << L << " la : " << SoDo[K - 1][L - 1] << endl;
	}
	else
	{
		cout << "\n Cho ngoi con trong\n";
	}
}

int ham_ViTriTrong(string SoDo[4][6])
{
	int trong = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(SoDo[i][j] == "X")
			{
				trong++;
			}
		}
	}
	return trong;
}

void ham_InRaSoDo(string SoDo[4][6])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << SoDo[i][j] << "\t";
		}
		cout << endl;
	}
}

void ham_TraoDoi(string SoDo[4][6], int K1, int L1, int K2, int L2)
{
	string tam = SoDo[K1 - 1][L1 - 1];
	SoDo[K1 - 1][L1 - 1] = SoDo[K2 - 1][L2 - 1];
	SoDo[K2 - 1][L2 -1] = tam;
	cout << "\nSo do lop sau khi doi cho " <<  SoDo[K1 - 1][L1 - 1] << " va " << SoDo[K2 - 1][L2 - 1] << endl;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cout << SoDo[i][j] << "\t";
		}
		cout << endl;
	}
}

void ham_InTenTheoKyTu(string SoDo[4][6], char KyTu)
{
	cout << endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			string name = SoDo[i][j];
			for(int k = 0; k < 1; k++)
			{
				if(name[k] == KyTu)
				{
					cout << SoDo[i][j] << " \tngoi o vi tri hang " << i + 1 << " va to thu " << j + 1 <<  endl;
				}
			}
		}
	}
}
