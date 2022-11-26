#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream docFILE;
    ofstream ghiFILE;
    cout << "\nNhap dia chi tap tin: "; //	D:\\TXT\\BTH4.txt   D:\\TXT\\MoHo.txt	D:\\TXT\\NhuNhungPhutBanDau.txt
    string Adress = " ";
    getline(cin, Adress);
    string Data = " ";
    char kt;
    int SoKyTu = 0;
    int SoDong = 0;

    docFILE.open(Adress, ios::in);
    if (docFILE.is_open())
    {
        cout << "\nDoc FILE thanh cong\n\n";
        while (!docFILE.eof())
        {
            getline(docFILE, Data);
            cout << Data << endl;
            SoDong++;

            for (int i = 0; i < Data.length(); i++)
            {
                for (kt = 'A'; kt <= 'z'; kt++)
                {
                    if (Data[i] == kt)
                    {
                        SoKyTu++;
                    }
                }
            }

            /*
            Cach cua ong An
            for (int i = 0; i < Data.length(); i++) {
				if (Data[i] != ' ') {
					SoKyTu++;
				}
				
			}
            */
        }
        docFILE.close();
        cout << "\nSo dong la: " << SoDong;
        cout << "\nSo ky tu la: " << SoKyTu;
    }
    else
    {
        cout << "\nKhong tim duoc FILE";
    }

    system("pause");
    return 0;
}