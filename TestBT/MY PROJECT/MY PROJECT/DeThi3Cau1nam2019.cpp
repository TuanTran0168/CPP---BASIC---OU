#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ham_NhapSoThuc();
void ham_DemSoTrongFile(string s[], int &sl);
int ham_DemSoTrongFile1(char s[], int &sl);

int main()
{
	char s[100];
	string a[100];
	int sl;
	//ham_DemSoTrongFile(a, sl);
	cout << ham_DemSoTrongFile1(s, sl);


	system("pause");
	return 0;
}

void ham_NhapSoThuc()
{
	double n;
	cout << "Nhap: \n";
	do
	{
		cin >> n;

	}while(n != -1);
}

//void ham_DemSoTrongFile(string s[], int &sl)
//{
//	sl = 0;
//	ifstream docFile;
//	docFile.open("D:\\TXT\\DeThi3Cau1.txt", ios::in);
//
//	if (docFile.is_open())
//	{
//		while(docFile.eof() == false)
//		{
//			getline(docFile, s[sl]);
//			sl++;
//		}
//	}
//
//	for (int i = 0; i < sl; i++)
//	{
//		for (int j = 0; j < s[i].length(); j++)
//		{
//			if (s[j] >= 48 && s[j] <= 57)
//			{
//				cout << s[j] << endl;
//			}
//		}
//	}
//}

int ham_DemSoTrongFile1(char s[], int &sl)
{
	sl = 0;
	ifstream docFile;
	docFile.open("D:\\TXT\\DeThi3Cau1.txt", ios::in);

	if (docFile.is_open())
	{
		while(docFile.eof() == false)
		{
			docFile.get(s[sl]);
			sl++;
		}
	}

	int count = 0;

	for (int i = 0; i < sl; i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			count++;
		}
	}

	return count;
}