#include <iostream>
#include <string>
using namespace std;
int ham_TimKhoangTrang(string name);
void ham_VietHoa(string name);
void ham_Ten(string name);
void ham_HovaTenDem(string name);


int main()
{
	string name;
	cout << "Nhap ho va ten: ";
	getline(cin, name);

	ham_VietHoa(name);
	cout << endl;

	ham_Ten(name);
	cout << " ";
	ham_HovaTenDem(name);
	cout << endl;

	ham_Ten(name);
	cout << ",";
	ham_HovaTenDem(name);

    cout << endl;
	system("pause");
	return 0;
}

int ham_TimKhoangTrang(string name)
{
	int i = name.length() - 1;
	int j;
	for(j = i; j >= 0; j--)
	{
		if(name[j] == ' ')
		{
			break;
		}
	}
	return j;
}

void ham_VietHoa(string name)
{
	for(int i = 0; i < name.length(); i++)
	{
		name[i] = toupper(name[i]);
	}
	cout << name;
}

void ham_Ten(string name)
{
	for(int i = ham_TimKhoangTrang(name) + 1; i < name.length(); i++)
	{
		name[i] = toupper(name[i]);
		cout << name[i];
	}
}

void ham_HovaTenDem(string name)
{
	for(int i = 0; i < ham_TimKhoangTrang(name); i++)
	{
		name[i] = toupper(name[i]);
		cout << name[i];
	}
}