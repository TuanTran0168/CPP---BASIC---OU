#include <iostream>
#include <string>
using namespace std;

struct ngay {int ng, th, nam;} vaotruong, ratruong; 

struct sinhvien {char hoten[25]; ngay ngaysinh;};

int test (long a, long b) {
	if (a >= b) return a;
	else
		return test(2*a, b);
}

int tong (int x)
{
	if (x == 1)
		return 1;
	else
		return x + tong(x - 1);
}
int main() 
{
	char a[3] = {'1', '2', '3'};
	cout << a[2];

	system("pause");
	return 0;
}