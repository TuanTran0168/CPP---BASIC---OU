#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
const int MAX = 200;
const double pi = 3.1415;
double ham_DienTichHinhTron(struct HinhTron HT);
double ham_ChuViHinhTron(struct HinhTron HT);

struct HinhTron
{
	double x, y;
	double R;
};

int main()
{
	HinhTron HT[MAX + 1];
	ifstream docFile;
	string temp;
	double tong = 0;

	docFile.open("D:\\TXT\\HinhTron.txt", ios::in);
	if(docFile.is_open())
	{
		int sl = 1;
		cout << "\nMo thanh cong tap tin!!\n\n";
		while(docFile.eof() == false)
		{
			getline(docFile, temp);
			docFile >> HT[sl].x;
			docFile.ignore(1);
			docFile >> HT[sl].y;
			docFile.ignore(1);
			docFile >> HT[sl].R;
			sl++;
		}
		docFile.close();
		//cout << sl;

		for(int i = 1; i < sl - 1; i++)		// 117 dòng bỏ dòng đầu với dòng cuối không có gì trong tập tin còn 115 dòng 
		{
			cout << "\nDien tich hinh tron thu " << i << " la: " << ham_DienTichHinhTron(HT[i]) << endl;
			tong = tong + ham_ChuViHinhTron(HT[i]);
		}
		cout << "\nTong cac chu vi hinh tron la: " << tong;
	}
	else
	{
		cout << "\nKhong the mo tap tin";
	}

	cout << endl;
	system("pause");
	return 0;
}

double ham_DienTichHinhTron(struct HinhTron HT)
{
	return pi * pow(HT.R, 2);
}

double ham_ChuViHinhTron(struct HinhTron HT)
{
	return HT.R * 2 * pi;
}