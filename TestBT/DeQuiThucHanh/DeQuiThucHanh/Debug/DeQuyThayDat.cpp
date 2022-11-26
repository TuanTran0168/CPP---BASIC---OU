#include <iostream>
using namespace std;

long NhiPhanSangThapPhan(long a, long sonhan)
{
	cout << "\nNhiPhanSangThapPhan(" << a << ", " << sonhan << ")" << endl;
	if (a == 0)
	{
		cout << "a= 0 ==> Ket qua tra ve= 0" << endl;
		return 0;
	}
	long giatri = (a % 10) * sonhan;
	cout << "==> " << a << "%10= " << a % 10 << " co gia tri la " << giatri << ", Tiep tuc doi " << a / 10 << " sang thap phan" << endl;
	long temp = NhiPhanSangThapPhan(a / 10, sonhan * 2);
	cout << "Ket qua tra ve= " << giatri << " + " << temp << "= " << (giatri + temp) << endl;
	return giatri + temp;
}

int main1()
{
	long x = 11011;
	cout << NhiPhanSangThapPhan(x, 1) << endl;
	system("pause");
	return 0;
}