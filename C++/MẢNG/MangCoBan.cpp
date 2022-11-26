#include <iostream>
using namespace std;
const int Max = 100;
//Xuat gia tri lon nhat tren dong va nho nhat tren cot
void ham_Xuat(int Arr[Max][Max], int Row, int Col);
int ham_MaxRow(int Arr[Max][Max], int Col, int i);
int ham_MinCol(int Arr[Max][Max], int Row, int j);
void ham_XuatMaxCol_MinRow(int Arr[Max][Max], int Row, int Col);

//=====================================================================
int ham_TinhTong(int Arr[Max][Max], int Row, int Col);
void ham_CacPhanTuChiaHetChoN(int Arr[Max][Max], int Row, int Col);
int ham_TongBienMaTran(int Arr[Max][Max], int Row, int Col);
int ham_TongTamGiacTrenMaTran(int Arr[Max][Max], int Row, int Col);
void ham_TimCotCoTichMax(int Arr[Max][Max], int Row, int Col);

int main()
{
    int a[Max][Max] =
        {
            {1, 2, 6, 5, 9},
            {3, 6, 8, 9, 0},
            {4, 5, 8, 4, 8},
            {0, 0, 3, 1, 2}};

    int b[Max][Max] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    int Row = 4;
    int Col = 5;

    ham_TimCotCoTichMax(a, Row, Col);

    system("pause");
    return 0;
}

void ham_Xuat(int Arr[Max][Max], int Row, int Col)
{
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << Arr[i][j] << '\t';
        }
        cout << endl;
    }
}

//Xuat gia tri lon nhat tren dong va nho nhat tren cot

int ham_MaxRow(int Arr[Max][Max], int Col, int i)
{
    int MaxRow = Arr[i][0];
    for (int j = 0; j < Col; j++)
    {
        if (Arr[i][j] > MaxRow)
        {
            MaxRow = Arr[i][j];
        }
    }
    return MaxRow;
}

int ham_MinCol(int Arr[Max][Max], int Row, int j)
{
    int MinCol = Arr[0][j];
    for (int i = 0; i < Row; i++)
    {
        if (Arr[i][j] < MinCol)
        {
            MinCol = Arr[i][j];
        }
    }

    return MinCol;
}

void ham_XuatMaxCol_MinRow(int Arr[Max][Max], int Row, int Col)
{
    cout << "\nCac phan tu co Max Dong va Min Cot la: ";
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if ((Arr[i][j] == ham_MaxRow(Arr, Col, i)) && (Arr[i][j] == ham_MinCol(Arr, Row, j)))
            {
                cout << "Arr[" << i << "][" << j << "]: " << Arr[i][j];
            }
        }
    }
}

//Ôn tập mảng 2 chiều (ma trận)

int ham_TinhTong(int Arr[Max][Max], int Row, int Col)
{
    int sum = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            sum += Arr[i][j];
        }
    }
    return sum;
}

void ham_CacPhanTuChiaHetChoN(int Arr[Max][Max], int Row, int Col)
{
    int N;
    cout << "\nNhap N: ";
    cin >> N;

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (Arr[i][j] % N == 0)
            {
                cout << Arr[i][j] << " ";
            }
        }
    }
}

int ham_TongBienMaTran(int Arr[Max][Max], int Row, int Col)
{
    int sum = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            if (i == 0 || i == Row - 1 || j == 0 || j == Col - 1)
            {
                sum += Arr[i][j];
            }
        }
    }
    return sum;
}

int ham_TongTamGiacTrenMaTran(int Arr[Max][Max], int Row, int Col)
{
    int sum = 0;
    for (int i = 0; i < Row; i++)
    {
        for (int j = i; j < Col; j++)
        {
            if (i == 0 || j == Col - 1 || i == j)
            {
                sum += Arr[i][j];
            }
        }
    }
    return sum;
}

void ham_TimCotCoTichMax(int Arr[Max][Max], int Row, int Col)
{
    int temp[100];
    int dem = 0;

    for (int j = 0; j < Col; j++)
    {
        int Tich = 1;
        for (int i = 0; i < Row; i++)
        {
            Tich *= Arr[i][j];
        }
        temp[j] = Tich;
        dem++;
    }

    int Max = temp[0];
    int vitri;

    for (int i = 0; i < dem; i++)
    {
        cout << "\nTich cot " << i << ": " << temp[i];
        if (temp[i] > Max)
        {
            Max = temp[i];
            vitri = i;
        }
    }

    cout << "\n\nCot co tich lon nhat la cot " << vitri << " co gia tri la: " << Max;
}
