#include <iostream>
using namespace std;
void ham_NhapMang2Chieu(double **&a, int &Row, int &Col);
void ham_XuatMang2Chieu(double **a, int Row, int Col);
void ham_GiaiPhong(double **&a, int Row);
double ham_TimMaxMin(double **a, int Row, int Col, bool o);
void ham_XuatMangZigZag(double **a, int Row, int Col);
void ham_SapXepZigZag(double **a, int Row, int Col);
int ham_DemSLPTuDuongTamGiacTren(double **a, int Row, int Col);
double ham_TongBien(double **a, int Row, int Col);

int main()
{
    double **a;
    int Row, Col;
    ham_NhapMang2Chieu(a, Row, Col);
    ham_XuatMang2Chieu(a, Row, Col);
    cout << "\nMAX la: " << ham_TimMaxMin(a, Row, Col, 1);
    cout << "\nMIN la: " << ham_TimMaxMin(a, Row, Col, 0);
    cout << endl
         << endl;

    ham_SapXepZigZag(a, Row, Col);
    ham_XuatMang2Chieu(a, Row, Col);
    cout << endl;

    cout << "\nSo luong phan tu duong o tam giac tren cua ma tran la: " << ham_DemSLPTuDuongTamGiacTren(a, Row, Col);
    cout << "\nTong cac phan tu nam o bien cua ma tran la: " << ham_TongBien(a, Row, Col) << endl;

    ham_GiaiPhong(a, Row);
    system("pause");
    return 0;
}

void ham_NhapMang2Chieu(double **&a, int &Row, int &Col)
{
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;

    a = new double *[Row]; // Cấp phát ra số dòng trước

    for (int i = 0; i < Row; i++)
    {
        *(a + i) = new double[Col]; // Rồi mỗi dòng cấp phát số cột sau
    }

    for (int i = 0; i < Row; i++)
    {
        cout << "\nNhap (" << Col << ") gia tri cho dong (" << i << ")\n";
        for (int j = 0; j < Col; j++)
        {
            cout << "Nhap gia tri thu [" << j << "]: ";
            cin >> *(*(a + i) + j);
        }
    }
}

void ham_XuatMang2Chieu(double **a, int Row, int Col)
{
    cout << "\n\tMang cua ban\n";

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << *(*(a + i) + j) << " ";
        }
        cout << endl;
    }
}

void ham_GiaiPhong(double **&a, int Row)
{
    for (int i = 0; i < Row; i++)
    {
        delete[] * (a + i);
    }
    delete[] a;
    a = NULL;
}

double ham_TimMaxMin(double **a, int Row, int Col, bool o)
{
    double temp = *(*(a + 0) + 0);

    if (o == true) // MAX
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                if (*(*(a + i) + j) > temp)
                {
                    temp = *(*(a + i) + j);
                }
            }
        }
        return temp;
    }

    else if (o == false) //MIN
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
            {
                if (*(*(a + i) + j) < temp)
                {
                    temp = *(*(a + i) + j);
                }
            }
        }
        return temp;
    }
}

void ham_XuatMangZigZag(double **a, int Row, int Col) // Cái này chỉ xuất ra chứ không có sắp xếp nha
{
    for (int i = 0; i < Row; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < Col; j++)
            {
                cout << *(*(a + i) + j) << " ";
            }
        }
        else
        {
            for (int j = Col - 1; j >= 0; j--)
            {
                cout << *(*(a + i) + j) << " ";
            }
        }

        cout << endl;
    }
}

void ham_SapXepZigZag(double **a, int Row, int Col) // Còn cái này chơi điếm thúi 1 tí :))) Chứ suy nghĩ sắp xếp trên 1 mảng không nổi :) MỆT :)
{
    double **b = new double *[Row]; // Cấp phát ra số dòng trước

    for (int i = 0; i < Row; i++)
    {
        *(b + i) = new double[Col]; // Rồi mỗi dòng cấp phát số cột sau
    }

    for (int i = 0; i < Row; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 0; j < Col; j++)
            {
                *(*(b + i) + j) = *(*(a + i) + Col - j - 1);
            }
        }
        else
        {
            for (int j = 0; j < Col; j++)
            {
                *(*(b + i) + j) = *(*(a + i) + j);
            }
        }
    }

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            *(*(a + i) + j) = *(*(b + i) + j);
        }
    }

    ham_GiaiPhong(b, Row);
}

int ham_DemSLPTuDuongTamGiacTren(double **a, int Row, int Col)
{
    int count = 0;

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (i == 0 || j == Col - 1 || i == j)
            {
                if (*(*(a + i) + j) > 0)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

double ham_TongBien(double **a, int Row, int Col)
{
    double sum = 0;

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (i == 0 || i == Row - 1 || j == 0 || j == Col - 1)
            {
                sum += *(*(a + i) + j);
            }
        }
    }

    return sum;
}
