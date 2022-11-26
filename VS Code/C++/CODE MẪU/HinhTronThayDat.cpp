#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 200;
struct tron
{
	double x;
	double y;
	double r;
};

tron d[MAX + 1];
int soluong = 0;
int ReadDataFile(string fname)
{
	ifstream hinhtron;
	string temp;
	hinhtron.open(fname, ios ::in);
	if (hinhtron.is_open())
	{
		getline(hinhtron, temp);
		while (hinhtron.eof() == false)
		{
			soluong++;
			hinhtron >> d[soluong].x;
			hinhtron.ignore(1);
			hinhtron >> d[soluong].y;
			hinhtron.ignore(1);
			hinhtron >> d[soluong].r;
			hinhtron.ignore(1);
		}

		hinhtron.close();
		return 0;
	}
	else
		return -1;
}
//------------------------------------------------------------
int main()
{
	int ketqua = ReadDataFile("D:\\TXT\\HinhTron.txt");
	if (ketqua == -1)
	{
		cout << "Loi khi doc tap tin!";
		return -1;
	}
	double dt = 0, tongcv = 0;
	// tinh dien tich tung hinh tron
	cout << " dien tich cua tung hinh tron la: " << endl;
	for (int j = 1; j <= soluong; j++)
	{
		dt = d[j].r * d[j].r * 3.14;
		cout << dt << endl;
	}

	// tinh tong chu vi
	for (int j = 1; j <= soluong; j++)
		tongcv = tongcv + (2 * d[j].r * 3.14);
	cout << " tong chu vi cua tat ca hinh tron la: " << tongcv << endl;

	system("pause");
	return 0;
}