#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifile;
	string s;
	long dem=0;
	ifile.open("D:\\TXT\\TuyenVietNam.txt");
	if (ifile.is_open())
	{
		while(!ifile.eof())
		{
			getline(ifile,s);
			if(s.find("Tien ve",0)>=0)
			{
				cout<<s<<endl;
				dem++;
			}

		}
		cout<<"Co "<<dem<<" tien ve"<<endl;
		ifile.close();
	}
	else
		cout<<"Khong the mo tap tin!!";
system("pause");
	return 0;
}