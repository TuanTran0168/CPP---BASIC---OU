#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	int choice;
	cout << "\Ban ten la gi: ";
	getline(cin, name);
	cout << "\nBan muon CHUI " << name << " hay KHEN " << name << " ?: ";
	cout << "\n1. CHUI.\n2. KHEN";
	cout << "\nChon: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
		cout << "D*T M* M*Y " << name << endl;
	else
		cout << name << " THAT DEP TRAI\n";

	system("pause");
	return 0;
}