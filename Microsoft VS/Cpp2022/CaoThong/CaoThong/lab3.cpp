#include <iostream>
using namespace std;

bool cau6_check(int nam)
{
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else
		return 0;
}

void cau6(int nam)
{
	if (cau6_check(nam))
		cout << "Nam " << nam << " la nam nhuan\n";
	else
		cout << "Nam " << nam << " la nam khong nhuan\n";
}


void cau8(int thang, int nam)
{
	switch (thang)
	{
		case 2:
			if (cau6_check(nam))
				cout << "So ngay cua thang " << thang << " nam " << nam << " la 29 ngay";
			else
				cout << "So ngay cua thang " << thang << " nam " << nam << " la 28 ngay";

			cout << endl;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << "So ngay cua thang " << thang << " nam " << nam << " la 31 ngay";
			cout << endl;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cout << "So ngay cua thang " << thang << " nam " << nam << " la 30 ngay";
			cout << endl;
			break;
	}
}

int main()
{
	int thang, nam;
	while(1)
	{
		cout << "Nhap thang: ";
		cin >> thang;
		cout << "Nhap nam: ";
		cin >> nam;
		cau8(thang, nam);
	}

	system("pause");
	return 0;
}