#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void ham_DoiChu(string &Data, string TimKiem, string ThayThe);

int main()
{
    ifstream docFile;
    ofstream ghiFile;
    string AdressDoc, AdressGhi;
    cout << "Nhap dia chi tap tin ma ban muon doc: "; // D:\\TXT\\DoiChu.txt		D:\\TXT\\MoHo.txt	    D:\\TXT\\NhuNhungPhutBanDau.txt
    getline(cin, AdressDoc);
    string Data;
    string TimKiem, ThayThe;

    //====== MỞ FILE VÀ ĐỌC FILE BỎ VÀO CHUỖI DATA=====

    docFile.open(AdressDoc, ios::in);
    if (docFile.is_open())
    {
        cout << "Doc File thanh cong!\n\n";
        while (docFile.eof() == false)
        {
            getline(docFile, Data);
            //ham_DoiChu(Data, TimKiem, ThayThe);
            cout << Data << endl;
        }

        docFile.close();
    }
    else
    {
        cout << "Khong tim duoc File";
        system("pause");
        return 0;
    }

    cout << "\nNhap dia chi tap tin ma ban muon ghi: "; // D:\\TXT\\DoiChu.txt		D:\\TXT\\MoHo.txt	    D:\\TXT\\NhuNhungPhutBanDau.txt
    getline(cin, AdressGhi);

    // ===========MỞ TẬP TIN CẦN GHI VÀO + THÔNG TIN ĐỔI CHỮ============

    ghiFile.open(AdressGhi, ios::out);
    if (ghiFile.is_open())
    {
        cout << "\nBan muon doi chu nao: ";
        getline(cin, TimKiem);
        cout << "Nhap chu ma ban muon doi: ";
        getline(cin, ThayThe);
        cout << endl;

        // =============ĐỔI CHỮ TRONG TẬP TIN VÀ IN VÀO MÀN HÌNH CONSOLE + IN VÀO TẬP TIN =============

        docFile.open(AdressDoc, ios::in);
        while (docFile.eof() == false)
        {
            getline(docFile, Data);             // Đọc dòng thứ i và tìm được chữ
            ham_DoiChu(Data, TimKiem, ThayThe); //sau đó đổi chữ rồi đọc lại dòng đó 1 lần nữa mới tới dòng tiếp theo
            cout << Data << endl;
            ghiFile << Data << endl;
        }
        cout << "\nGhi thanh cong du lieu tu File co dia chi: " << AdressDoc << " den File co dia chi la: " << AdressGhi << endl;
        docFile.close();
    }
    else
    {
        cout << "Khong mo duoc File de ghi";
    }

    cout << endl;
    system("pause");
    return 0;
}

void ham_DoiChu(string &Data, string TimKiem, string ThayThe)
{
    int begin = 0;
    int sl = 0;
    for (int i = 0; i < TimKiem.length(); i++)
    {
        sl++;
    }

    for (int i = 0; i < Data.length(); i++)
    {
        begin = Data.find(TimKiem, 0);
        if (begin >= 0)
        {
            /*cout << Data << endl;
              cout << begin << endl;
			  cout << Data.length() << endl;*/
            Data.replace(begin, sl, ThayThe);
        }
    }
}