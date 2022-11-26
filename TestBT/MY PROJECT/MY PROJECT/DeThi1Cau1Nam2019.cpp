#include <iostream>
#include <fstream>
using namespace std;
void ham_ChuyenChuHoa(char *s);
void ham_GhiKyTuMotDong(char *s);

int main1()
{
	char s[100];
	cin.getline(s, 100);
	//ham_ChuyenChuHoa(s);
	ham_GhiKyTuMotDong(s);
	cout << s;

	system("pause");
	return 0;
}

void ham_ChuyenChuHoa(char *s)
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] = s[i] - 32;
		}
	}
}

void ham_GhiKyTuMotDong(char *s)
{
	int n = strlen(s);
	ofstream ghiFile;
	ghiFile.open("D:\\TEST.txt", ios::out);

	if(ghiFile.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			ghiFile << s[i] << endl;
		}
				cout << "\nGhi thanh cong!!!";
	}
	else
		cout << "\nKhong mo duoc!!!";
}

