#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int UCLN(int a, int b)
{
	if (a == 0 || b == 0)
		return 1;

        a = abs(a);
        b = abs(b);

        while (a != b) 
		{
            if (a > b)
                a -= b;
            else if (b > a)
                b -= a;
        }
        return a;
}

void daoNguoc(string mang[1000], int n)
{    
    for (int i = 0; i < n / 2; ++i) {
        string temp = mang[i];
        mang[i] = mang[n - i - 1];
        mang[n - i - 1] = temp;
    }
}

int cau12(int n)
{
	int soDaoNguoc = 0;
	int soDuocTach = 0;

	int soDaoNguoc1 = 0;
	int soDuocTach1 = 0;

	while (n > 0)
	{
		soDuocTach = n % 10;
		soDaoNguoc = soDaoNguoc * 10 + soDuocTach;
		n = n / 10;	
	}

	int n1 = soDaoNguoc;
	while (n1 > 0)
	{
		soDuocTach1 = n1 % 10;
		soDaoNguoc1 = soDaoNguoc1 * 10 + soDuocTach1;
		n1 = n1 / 10;	
	}
	return soDaoNguoc1;
	// MET VL
}

void cau12_1(int n)
{
	stringstream ss;
	ss << n;
	string str = ss.str();

	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i] << " ";
	}
}

int main()
{
	cau12_1(101);

	system("pause");
	return 0;
}