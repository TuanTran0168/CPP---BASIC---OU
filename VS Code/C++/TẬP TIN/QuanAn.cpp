#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 1000;
void ham_DocTapTin(int &sl);
//void ham_DocTapTinCODAUCHAM(int &sl);
void ham_InMotMonAn(int vitri);
void ham_InToanBoMonAn(int sl);
void ham_InRaHaiMonNuocVaManDuoiGiaTienNhapVao(int sl);
void ham_InRaHaiMonNuocVaManDuoiGiaTienNhapVaoKieu2(int sl);
void ham_SapXepMonAnGiaTuThapToiCao(int sl);
void ham_SapXepMonAnGiaTangHoacGiamDan(int sl);

struct QuanAn
{
    string MonAn;
    string DungCu;
    long Gia;
};

int sl;
string rac;
QuanAn DS[MAX];

int main()
{
    ham_DocTapTin(sl);
    ham_InRaHaiMonNuocVaManDuoiGiaTienNhapVaoKieu2(sl);

    system("pause");
    return 0;
}

//void ham_DocTapTinCODAUCHAM(int &sl)
//{
//	ifstream docFile;
//	sl = 1;
//	docFile.open("D:\\TXT\\QuanAnTEST.txt", ios::in);
//	if(docFile.is_open())
//	{
//		cout << "Mo thanh cong!!!\n";
//		getline(docFile, rac);
//		while(docFile.eof() == false)
//		{
//			getline(docFile, DS[sl].MonAn, ',');
//			getline(docFile, DS[sl].DungCu, ',');
//			docFile >> DS[sl].Gia;
//			getline(docFile, rac);
//			sl++;
//		}
//		docFile.close();
//	}
//	else
//		cout << "Khong mo duoc tap tin";
//}

void ham_DocTapTin(int &sl)
{
    ifstream docFile;
    sl = 1;
    docFile.open("D:\\TXT\\QuanAn.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "Mo thanh cong!!!\n";
        getline(docFile, rac);
        while (docFile.eof() == false)
        {
            getline(docFile, DS[sl].MonAn, ',');
            getline(docFile, DS[sl].DungCu, ',');
            docFile >> DS[sl].Gia;
            docFile.ignore(1);
            //getline(docFile, rac);
            sl++;
        }
        docFile.close();
    }
    else
        cout << "Khong mo duoc tap tin";
}

void ham_InMotMonAn(int vitri)
{
    cout << "\nTen mon: " << DS[vitri].MonAn;
    cout << "\nDung cu: " << DS[vitri].DungCu;
    cout << "\nGia ban: " << DS[vitri].Gia;
}

void ham_InToanBoMonAn(int sl)
{
    for (int i = 1; i < sl; i++)
    {
        ham_InMotMonAn(i);
        cout << endl;
    }
}

/* In ra tổ hợp 1 món nước và một món mặn giá dưới số tiền nhập vào (VD: 150k)
   Món nước xài Tô và món mặn xài dĩa
*/

void ham_InRaHaiMonNuocVaManDuoiGiaTienNhapVao(int sl)
{
    long Money;
    cout << "\nTim mon man va nuoc gia duoi so tien nhap vao";
    cout << "\nNhap so tien: ";
    cin >> Money;
    for (int i = 1; i < sl; i++)
    {
        if (DS[i].DungCu == "To")
        {
            for (int j = 1; j < sl; j++)
            {
                if (DS[j].DungCu == "Dia")
                {
                    if (DS[i].Gia + DS[j].Gia <= Money)
                    {
                        cout << "\nMon nuoc la: " << DS[i].MonAn << " / gia: " << DS[i].Gia;
                        cout << "\nMon man la: " << DS[j].MonAn << " / gia: " << DS[j].Gia;
                        cout << "\nTong tien la: " << DS[i].Gia + DS[j].Gia;
                        cout << "\n================================================\n";
                    }
                }
            }
        }
    }
}

void ham_InRaHaiMonNuocVaManDuoiGiaTienNhapVaoKieu2(int sl)
{
    long Money;
    int slnuoc = 1;
    int slman = 1;
    cout << "\nTim mon man va nuoc gia duoi so tien nhap vao";
    cout << "\nNhap so tien: ";
    cin >> Money;

    QuanAn NUOC[MAX];
    QuanAn MAN[MAX];

    for (int i = 1; i < sl; i++)
    {
        if (DS[i].DungCu == "Dia")
        {
            MAN[slman] = DS[i];
            slman++;
        }
        else if (DS[i].DungCu == "To")
        {
            NUOC[slnuoc] = DS[i];
            slnuoc++;
        }
    }

    for (int i = 1; i < slnuoc; i++)
    {
        for (int j = 1; j < slman; j++)
        {
            if (NUOC[i].Gia + MAN[j].Gia <= Money)
            {
                cout << "\nMon nuoc la: " << NUOC[i].MonAn << " / gia: " << NUOC[i].Gia;
                cout << "\nMon man la: " << MAN[j].MonAn << " / gia: " << MAN[j].Gia;
                cout << "\nTong tien la: " << NUOC[i].Gia + MAN[j].Gia;
                cout << "\n================================================\n";
            }
        }
    }
}

void ham_SapXepMonAnGiaTuThapToiCao(int sl) // Quá bình thường :)))
{
    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].Gia > DS[j].Gia)
            {
                QuanAn temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_SapXepMonAnGiaTangHoacGiamDan(int sl) // Đỉnh hơn nhiều :)))
{
    bool SapXep;
    cout << "\nBan muon xem gia tang dan hay giam dan\n0.Gia giam dan\n1.Gia tang dan";
    cout << "\nNhap: ";
    cin >> SapXep;

    for (int i = 1; i < sl; i++)
    {
        for (int j = i + 1; j < sl; j++)
        {
            if (DS[i].Gia > DS[j].Gia == SapXep)
            {
                QuanAn temp = DS[i];
                DS[i] = DS[j];
                DS[j] = temp;
            }
        }
    }
}

void ham_InRaHaiMonTheoGiaNhapVao(int sl)
{
    int Money;
    cout << "\nTim mon man va mon nuoc theo so tien nhap vao";
    cout << "\nNhap so tien: ";
    cin >> Money;
    for(int i = 1; i < sl; i++)
    {
        if(DS[i].DungCu == "To")
        {
            for(int j = 1; j < sl; j++)
            {
                if(DS[j].DungCu == "Dia")
                {
                    if(DS[i].Gia + DS[j].Gia <= Money)
                    {
                        
                    }
                }
            }
        }
    }
}