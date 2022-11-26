#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream docFile;
    ofstream ghiFile;
    string AdressGhi;
    string DataDoc, AdressDoc;

    cout << "Nhap dia chi tap tin ban muon doc: "; //	D:\TXT\FileDeDoc.txt    D:\TXT\bathuongcon.txt
    cin >> AdressDoc;
    //fflush(stdin);	//	Xóa bộ nhớ đệm đang lưu dấu enter

    docFile.open(AdressDoc, ios::in);
    if (!docFile.is_open())
    {
        cout << "Khong tim thay tap tin!\n";
        system("pause");
        return 0;
    }

    // ===================================================================================

    cout << "Nhap dia chi tap tin ban muon ghi: "; //	D:\TXT\FileDeGhi.txt
    cin >> AdressGhi;
    //fflush(stdin);	//	Xóa bộ nhớ đệm đang lưu dấu enter

    ghiFile.open(AdressGhi, ios::out);
    if (!ghiFile.is_open())
    {
        cout << "Khong tim thay tap tin!\n";
        system("pause");
        return 0;
    }
    cout << endl;

    while (!docFile.eof())
    {
        getline(docFile, DataDoc);
        cout << DataDoc << endl;
        ghiFile << DataDoc << endl;
    }

    cout << "\n\nDa ghi thanh cong du lieu tu File co dia chi: " << AdressDoc << " toi File co dia chi: " << AdressGhi << endl;

    docFile.close();
    ghiFile.close();

    cout << endl;
    system("pause");
    return 0;
}