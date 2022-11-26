#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
const int MAX = 100;
struct SV
{
	string MSSV;
	string HoLot;
	string Ten;
	string NgaySinh;
	string Nganh;
	string Que;
};
SV DSSV[MAX + 1];
int SoDay, SoO;
string SoDo[10][10];
int SLSV = 0;
void MoFile();
void Xuat(int i);
void XuatDay();
void XuatDayVaO();
void NamSinh();
void SVngoiGiua();
void SVngoiTrcVaSau();
void inViTriTrong();
void Menu();
int main()
{
	MoFile();
	for (int i = 1; i <= SoDay; i++)
	{
		for (int j = 1; j <= SoO; j++)
		{
			cout << SoDo[i][j] << "\t";
		}
		cout << endl;
	}

	Xuat(1);
	//Menu();

	system("pause");
}
void MoFile()
{
	ifstream DocFile;
	int dem = 0;
	DocFile.open("SoDoLop.txt", ios::in);
	if (DocFile.is_open())
	{
		while (!DocFile.eof())
		{
			string tam;
			if (dem == 0)
			{
				getline(DocFile, tam);
			}
			else if (dem == 1)
			{
				DocFile >> SoDay;
				DocFile.ignore(1);
				DocFile >> SoO;
				DocFile.ignore(1);
			}
			else if (dem == 2)
				getline(DocFile, tam);
			else
			{
				SLSV++;
				int LuuO;
				int LuuDay;
				DocFile >> LuuO;
				DocFile.ignore(1);
				DocFile >> LuuDay;
				DocFile.ignore(1);
				getline(DocFile, DSSV[SLSV].MSSV, ',');
				SoDo[LuuDay][LuuO] = DSSV[SLSV].MSSV;
				getline(DocFile, DSSV[SLSV].HoLot, ',');
				getline(DocFile, DSSV[SLSV].Ten, ',');
				getline(DocFile, DSSV[SLSV].NgaySinh, ',');
				getline(DocFile, DSSV[SLSV].Nganh, ',');
				getline(DocFile, DSSV[SLSV].Que);
			}
			dem++;
		}
		DocFile.close();
	}
	else
		cout << "khong mo duoc file\n";
}
void Xuat(int i)
{
	cout << "Thong tin cua sinh vien thu " << i << endl;
	cout << "Ho ten: " << DSSV[i].HoLot << " " << DSSV[i].Ten << endl;
	cout << "MSSV: " << DSSV[i].MSSV << endl;
	cout << "Ngay Sinh: " << DSSV[i].NgaySinh << endl;
	cout << "Nganh: " << DSSV[i].Nganh << endl;
	cout << "Que quan: " << DSSV[i].Que << endl;
}
void XuatDay()
{
	int Day;
	int dem = 0;
	do
	{
		cout << "Moi nhap so day ngoi: ";
		cin >> Day;
	} while (Day<1 || Day>SoDay);
	cout << "Cac sinh vien trong day " << Day << endl;
	for (int i = 1; i <= SLSV; i++)
	{
		for (int j = 1; j <= SoO; j++)
		{
			if (SoDo[Day][j] == DSSV[i].MSSV)
				Xuat(i);
		}
	}
}
void XuatDayVaO()
{
	int Day, O;
	do
	{
		cout << "Moi nhap so day va o ngoi: ";
		cin >> Day>>O;
	} while (Day<1 || Day>SoDay||O<1||O>SoO);
	cout << "Sinh vien ngoi o day " << Day << " o " << O << endl;
	for (int i = 1; i <= SLSV; i++)
	{
		if (SoDo[Day][O] == DSSV[i].MSSV)
			Xuat(i);
	}
}
void NamSinh()
{
	int dem = 0;
	string date;
	cout << "Moi nhap nam sinh cua sinh vien: ";
	getline(cin,date);
	cout << "Danh sach sinh vien co nam sinh " << date << endl;
	for (int i = 1; i <= SLSV; i++)
	{
		int kq = DSSV[i].NgaySinh.find(date, 0);
		if (kq == 6)
			Xuat(i);
	}
}
void SVngoiGiua()
{
	cout << "Cac sinh vien ngoi giua 2 sinh vien khac: " << endl;
	for (int i = 1; i <= SoDay; i++)
	{
		for (int j = 2; j <= SoO - 1; j++)
		{
			if (SoDo[i][j - 1] != "" && SoDo[i][j + 1] != "")
			{
				for (int k = 1; k <= SLSV; k++)
				{
					if (SoDo[i][j] == DSSV[k].MSSV)
						Xuat(k);
				}
			}
		}
	}
}
void SVngoiTrcVaSau()
{
	cout << "Cac sinh vien co sinh vien khac ngoi truoc va sau\n";
	for (int i = 2; i < SoDay; i++)
	{
		for (int j = 1; j <= SoO; j++)
		{
			int Chotrc = SoDo[i - 1][j].length();
			int ChoHienHanh = SoDo[i][j].length();
			int ChoSau = SoDo[i + 1][j].length();
			if (Chotrc > 0 && ChoHienHanh > 0 && ChoSau > 0)
			{
				for (int k = 1; k <= SLSV; k++)
				{
					if (SoDo[i][j] == DSSV[k].MSSV)
						Xuat(k);
				}
			}
		}
	}
}
void inViTriTrong()
{
	cout << "Cac vi tri trong\n";
	for (int i = 1; i <= SoDay; i++)
	{
		for (int j = 1; j <= SoO; j++)
		{
			if (SoDo[i][j] == "")
				cout << "Day " << i << " O " << j << endl;
		}
	}
}
void Menu()
{
	int chon;
	do
	{
		system("cls");
		cout << "Menu\n"
			<< "1/Nhap day in thong tin sinh vien trong day\n"
			<< "2/Nhap day va o in thong tin sinh vien\n"
			<< "3/Nhap nam sinh in thong tin sinh vien\n"
			<<"4/Sinh vien ngoi giua 2 sinh vien khac\n"
			<<"5/Sinh vien co sinh vien khac ngoi truoc va sau\n"
			<<"6/In ra cac vi tri trong\n"
			<< "Moi chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			XuatDay();
			break;
		case 2:
			XuatDayVaO();
			cin.ignore(1);
			break;
		case 3:
			NamSinh();
			break;
		case 4:
			SVngoiGiua();
			break;
		case 5:
			SVngoiTrcVaSau();
			break;
		case 6:
			inViTriTrong();
			break;
		default:
			break;
		}
		_getch();
	} while (chon>=1&&chon<=6);
}


			
				
				

	
		