#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
const int MAX = 100;
void TinhPTB1(int a, int b);
void TinhPTB2(int a, int b, int c);
void MoFile();
void docFile(string data[], int &soLuong);
bool kiemTra(string data);

// void xuat();
int main()
{
    int soLuong;
    int a, b, c;
    string data[MAX];
    docFile(data, soLuong);

    cout << "-----------------------------------\n";
    for (int i = 0; i < soLuong; i++)
    {
        cout << data[i] << endl;
    }

    cout << "-----------------------------------\n";
    MoFile();
    // xuat();

    system("pause");
    return 0;
}
void TinhPTB1(int a, int b)
{
    if (a == 0)
    {
        if (b == 0)
            cout << "Phuong trinh co VSN\n";
        else
            cout << "Phuong trinh VN\n";
    }
    else
        cout << "Ket qua la " << -b * 1.0 / a << endl;
}
void TinhPTB2(int a, int b, int c)
{
    if (a == 0)
        TinhPTB1(b, c);
    else
    {
        double DelTa = b * b - 4 * a * c;
        if (DelTa < 0)
            cout << "Phuong trinh vo nghiem\n";
        else if (DelTa == 0)
            cout << "Phuong trinh co 1 nghiem kep: " << -b * 1.0 / 2 * a << endl;
        else
        {
            cout << "Phuong trinh co 2 nghiem phan biet\n";
            cout << "x1 = " << (-b + sqrt(DelTa) / 2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(DelTa) / 2 * a) << endl;
        }
    }
}
void MoFile()
{
    ifstream DocFile;
    string TenFile;
    // getline(cin, TenFile);
    DocFile.open("PTB1va2.txt", ios::in);
    int dem = 0;
    if (DocFile.is_open())
    {
        while (!DocFile.eof())
        {
            string tam;
            int a, b, c;
            if (dem == 0)
            {
                getline(DocFile, tam);
                dem++;
            }
            if (dem == 2 || dem == 6 || dem == 8 || dem == 9 || dem == 12 || dem == 13)
            {
                DocFile >> a;
                DocFile.ignore(1);
                DocFile >> b;
                DocFile.ignore(1);
                cout << "Voi a = " << a << " va b =  " << b << endl;
                TinhPTB1(a, b);
            }
            else
            {
                DocFile >> a;
                DocFile.ignore(1);
                DocFile >> b;
                DocFile.ignore(1);
                DocFile >> c;
                DocFile.ignore(1);
                cout << "Voi a = " << a << " va b = " << b << " va c = " << c << endl;
                TinhPTB2(a, b, c);
            }
            dem++;
        }
        DocFile.close();
    }
    else
        cout << "Khong mo duoc File" << endl;
}

void docFile(string data[], int &soLuong)
{
    ifstream docFile;
    docFile.open("PTB1va2.txt", ios::in);
    if (docFile.is_open())
    {
        string temp;
        getline(docFile, temp);
        soLuong = 0;
        while (!docFile.eof())
        {
            getline(docFile, data[soLuong]);
            cout << data[soLuong] << " check: " << kiemTra(data[soLuong]) << endl;
            soLuong++;
        }
        cout << "-----------------------------------\n";
        docFile.close();
        cout << endl;

        docFile.open("PTB1va2.txt", ios::in);
        if (docFile.is_open())
        {

            int a, b, c;
            getline(docFile, temp);

            for (int i = 0; i < soLuong; i++)
            {
                if (kiemTra(data[i]) == true)
                {
                    docFile >> a;
                    docFile.ignore(1);
                    docFile >> b;
                    docFile.ignore(1);
                    docFile >> c;
                    docFile.ignore(1);

                    cout << "Voi a = " << a << " va b = " << b << " va c = " << c << endl;
                    // TinhPTB2(a, b, c);
                }

                else
                {
                    docFile >> a;
                    docFile.ignore(1);
                    docFile >> b;
                    docFile.ignore(1);

                    cout << "Voi a = " << a << " va b = " << b << endl;
                    // TinhPTB1(a, b);
                }
            }
        }
        docFile.close();
    }
    else
        cout << "\nKhong mo duoc";
}

bool kiemTra(string data)
{
    int count = 0;
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == 44)
            count++;
    }

    if (count == 1)
        return false;
    else
        return true;
}
