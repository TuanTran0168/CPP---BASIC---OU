#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void ham_NhapMang2ChieuDong(int **&a, int &Row, int &Col);
void ham_NhapMang2ChieuDongKyPhapDoDoi(int **&a, int &Row, int &Col);
void ham_Mang2ChieuDongNgauNhien(int **&a, int &Row, int &Col);
void ham_Mang2ChieuDongNgauNhienKyPhapDoDoi(int **&a, int &Row, int &Col);
void ham_NhapMang2ChieuBangMang1ChieuCapPhatDong(int *&a, int &Row, int &Col);
void ham_XuatMang(int **a, int Row, int Col);
void ham_XuatMangKyPhapDoDoi(int **a, int Row, int Col);
void ham_XuatMang1ChieuNhungBieuDien2Chieu(int *a, int Row, int Col);
void ham_GiaiPhong(int **&a, int Row);

int main()
{
    int Row, Col;
    int **a;
    int *b;
    /* ========== HÀM CẤP PHÁT ĐỘNG MẢNG 2 CHIỀU ========== */

    //ham_NhapMang2ChieuDong(a, Row, Col);
    //ham_Mang2ChieuDongNgauNhien(a, Row, Col);
    ham_NhapMang2ChieuDongKyPhapDoDoi(a, Row, Col);
    //ham_XuatMang(a, Row, Col);
    ham_XuatMangKyPhapDoDoi(a, Row, Col);

    /* ========== HÀM CẤP PHÁT ĐỘNG MẢNG 1 CHIỀU NHƯNG BIỂU DIỄN THÀNH 2 CHIỀU ========== */
    //Dễ dàng xử lý 1 số bài toán

    //ham_NhapMang2ChieuBangMang1ChieuCapPhatDong(b, Row, Col);
    //ham_XuatMang1ChieuNhungBieuDien2Chieu(b, Row, Col);

    //delete[] b;
    //b = NULL;

    ham_GiaiPhong(a, Row); // Hàm giải phóng mảng 2 chiều cấp phát động

    if (a == NULL)
        cout << "\nDa giai phong\n";
    else
        cout << "\nChua giai phong\n";

    system("pause");
    return 0;
}

void ham_NhapMang2ChieuDong(int **&a, int &Row, int &Col)
{
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;
    cout << endl;

    a = new int *[Row]; // Cấp phát mảng có các phần tử là 1 con trỏ (số dòng)
    for (int i = 0; i < Row; i++)
    {
        a[i] = new int[Col]; // Cấp phát vùng nhớ cho mỗi con trỏ (số cột)
    }

    for (int i = 0; i < Row; i++)
    {
        cout << "Nhap (" << Col << ") gia tri cho cot: (" << i + 1 << "): \n";
        for (int j = 0; j < Col; j++)
        {
            cin >> a[i][j];
        }
        //cout << endl;
    }
}

void ham_NhapMang2ChieuDongKyPhapDoDoi(int **&a, int &Row, int &Col)
{
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;
    cout << endl;

    a = new int *[Row]; // Cấp phát mảng có các phần tử là 1 con trỏ (số dòng)
    for (int i = 0; i < Row; i++)
    {
        a[i] = new int[Col]; // Cấp phát vùng nhớ cho mỗi con trỏ (số cột)
    }

    for (int i = 0; i < Row; i++)
    {
        cout << "Nhap (" << Col << ") gia tri cho cot: (" << i + 1 << "): \n";
        for (int j = 0; j < Col; j++)
        {
            cin >> *(*(a + i) + j);
        }
        //cout << endl;
    }
}

void ham_Mang2ChieuDongNgauNhien(int **&a, int &Row, int &Col)
{
    srand(time(NULL));
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;
    cout << endl;

    a = new int *[Row]; // Cấp phát mảng có các phần tử là 1 con trỏ (số dòng)
    for (int i = 0; i < Row; i++)
    {
        a[i] = new int[Col]; // Cấp phát vùng nhớ cho mỗi con trỏ (số cột)
    }

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            a[i][j] = rand() % 10 + 1; // Khoảng sinh số ngẫu nhiên [1 - 10]
        }
        //cout << endl;
    }
}

void ham_Mang2ChieuDongNgauNhienKyPhapDoDoi(int **&a, int &Row, int &Col)
{
    srand(time(NULL));
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;
    cout << endl;

    a = new int *[Row]; // Cấp phát mảng có các phần tử là 1 con trỏ (số dòng)
    for (int i = 0; i < Row; i++)
    {
        a[i] = new int[Col]; // Cấp phát vùng nhớ cho mỗi con trỏ (số cột)
    }

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            *(*(a + i) + j) = rand() % 10 + 1; // Khoảng sinh số ngẫu nhiên [1 - 10]
        }
        //cout << endl;
    }
}

void ham_NhapMang2ChieuBangMang1ChieuCapPhatDong(int *&a, int &Row, int &Col) // Xịn
{
    //Cách 2: Dùng mảng 1 chiều để biểu diễn mảng 2 chiều
    // Ý tưởng: Cấp phát mảng 1 chiều có kích thước m x n và truy cập nó như một mảng 2 chiều với các chỉ số thông qua công thức liên hệ.

    // Phần tử a[i][j] tương ứng với phần tử a[i*n + j] trong mảng.
    // Ví dụ:
    srand(time(NULL));
    cout << "Nhap so dong: ";
    cin >> Row;
    cout << "Nhap so cot: ";
    cin >> Col;
    cout << endl;

    a = new int[Row * Col]; //cấp phát xong
    //khởi tạo bằng 0
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            a[i * Col + j] = rand() % 10 + 1; // Khoảng sinh số ngẫu nhiên [1 - 10]
        }
    }
}

void ham_XuatMang(int **a, int Row, int Col)
{
    cout << "\n\tMang cua ban\n\n";

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void ham_XuatMangKyPhapDoDoi(int **a, int Row, int Col)
{
    cout << "\n\tMang cua ban\n\n";

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << *(*(a + i) + j) << "\t";
        }
        cout << endl;
    }
}

void ham_XuatMang1ChieuNhungBieuDien2Chieu(int *a, int Row, int Col) // Xịn
{
    cout << "\n\tMang cua ban\n\n";

    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
        {
            cout << a[i * Col + j] << "\t";
        }
        cout << endl;
    }
}

void ham_GiaiPhong(int **&a, int Row)
{
    for (int i = 0; i < Row; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    a = NULL;
}