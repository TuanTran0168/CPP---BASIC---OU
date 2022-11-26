#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
	string a = " Tien ve";
	ifstream TuyenVietNam;
	TuyenVietNam.open("D:\\TXT\\TuyenVietNam1.txt",ios::in);
	string Hello = " ";
	int sl = 0;
	if (TuyenVietNam.is_open())
	{
		while(!TuyenVietNam.eof())
		{
			getline(TuyenVietNam,Hello);

			if(Hello.find(a, 0) >= 0)
			{
				cout << Hello << endl;
				sl++;
			}
	    }
		 TuyenVietNam.close();
		 cout << "\nSo luong la: "<< sl;
	}
	else cout<<"khong tim duoc tep tin"<<endl;
	system("pause");
    return 0;

}