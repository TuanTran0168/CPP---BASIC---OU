#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void ham_Nhap(ifstream docFILE);

int main()
{
    ifstream docFILE;
    ofstream ghiFILE;

    ham_Nhap(docFILE);
	
	cout << endl;
    system("pause");
    return 0;
}

void ham_Nhap(ifstream docFILE)
{
	cout << "\nNhap dia chi tap tin: "; //	D:\\TXT\\BTH4.txt   D:\\TXT\\MoHo.txt	D:\\TXT\\NhuNhungPhutBanDau.txt
    string Adress = " ";
    getline(cin, Adress);
    string Data = " ";
    docFILE.open(Adress);
    if (docFILE.is_open())
    {
        cout << "\nDoc FILE thanh cong\n\n";
        while (!docFILE.eof())
        {
            getline(docFILE, Data);
            cout << Data << endl;
            
        }
        docFILE.close();
	}
    else
    {
        cout << "\nKhong tim duoc FILE";
    }
}