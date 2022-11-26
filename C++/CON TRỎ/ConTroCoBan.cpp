#include <iostream>
using namespace std;
void ham_NhapMangCoConTro(int *a, int n);
void ham_NhapMangCoConTro1(int *&a, int &n);
void ham_NhapMangBinhThuong(int a[], int &n);
void ham_XuatMang(int *a, int n);
void ham_XuatMangKyPhapDoDoi(int *a, int n);
int *ham_TimMaxMinCoConTro(int *a, int n, bool MaxOrMin);
void ham_SapXepMang(int *a, int n, bool TangOrGiam);
int *ham_TinhTongCoConTro(int *a, int n);
int *ham_TinhTongCoConTro1(int *a, int n);
int *ham_TinhTongKyPhapDoDoi(int *a, int n);
void ham_ThemPhanTuMangDong(int *&a, int &n, int &vitri, int &x);
void ham_XoaPhanTuMangDong(int *&a, int &n, int &vitri);

int main()
{
    cout << "\n\tNHAP MANG CO CON TRO\n\n";
    int n;
    int *a;
    ham_NhapMangCoConTro1(a, n);

    cout << "\n\tXUAT MANG CO CON TRO\n\n";
    //ham_XuatMang(a, n);
    ham_XuatMangKyPhapDoDoi(a, n);

    /*=============================================================================================================*/

    cout << "\n\n\tMOT SO CHUC NANG KHAC\n";
    cout << "\nGia tri nho nhat trong mang la: (" << *ham_TimMaxMinCoConTro(a, n, 0) << ") co dia chi la: (" << ham_TimMaxMinCoConTro(a, n, 0) << ")";
    ham_XuatMang(a, n); // LỖI CHỖ NÀY
    cout << "\nGia tri lon nhat trong mang la: (" << *ham_TimMaxMinCoConTro(a, n, 1) << ") co dia chi la: (" << ham_TimMaxMinCoConTro(a, n, 1) << ")";
    ham_XuatMang(a, n); // LỖI CHỖ NÀY
    cout << endl;

    cout << "\nMang giam dan: ";
    ham_SapXepMang(a, n, 0);
    ham_XuatMang(a, n);
    cout << "\nMang tang dan: ";
    ham_SapXepMang(a, n, 1);
    ham_XuatMang(a, n);
    cout << endl;

    cout << "\nTong mang co con tro: " << *ham_TinhTongCoConTro(a, n);
    //cout << "\nTong mang co con tro 1: " << *ham_TinhTongCoConTro1(a, n);
    cout << "\nTong mang co ky phap do doi: " << *ham_TinhTongKyPhapDoDoi(a, n);
    cout << endl;

    int vitri, x;
    ham_ThemPhanTuMangDong(a, n, vitri, x);
    ham_XuatMangKyPhapDoDoi(a, n);
    ham_XoaPhanTuMangDong(a, n, vitri);
    ham_XuatMangKyPhapDoDoi(a, n);

    /*cout << "\n====================================================================================\n";

    cout << "\n\tNHAP MANG BINH THUONG\n";
    int c;
    int b[100];
    ham_NhapMangBinhThuong(b, c);

    cout << "\n\tXUAT MANG BINH THUONG\n";
    ham_XuatMang(b, c);*/

    delete[] a;

    cout << endl;
    system("pause");
    return 0;
}

void ham_NhapMangCoConTro(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void ham_NhapMangCoConTro1(int *&a, int &n)
{

    cout << "Ban muon mang co bao nhieu phan tu: ";
    cin >> n;
    a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void ham_NhapMangBinhThuong(int a[], int &n)
{
    cout << "Ban muon mang co bao nhieu phan tu: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> a[i];
    }
}

void ham_XuatMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void ham_XuatMangKyPhapDoDoi(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}

int *ham_TimMaxMinCoConTro(int *a, int n, bool MaxOrMin)
{
    /* 
		CHỖ NÀY NẾU KHÔNG GÁN TRUNG GIAN QUA BIẾN TEMP THÌ Ô a[0] SẼ BỊ GÁN THÀNH BIẾN MAXMIN :)) LÚ 
		VÌ BIẾN MAXMIN ĐANG LẤY CÙNG 1 ĐỊA CHỈ VỚI Ô a[0] :)) 
	*/
    int temp = a[0];
    int &MAXMIN = temp;

    if (MaxOrMin == 1) // Lớn nhất
    {
        for (int i = 1; i < n; i++)
        {
            if (MAXMIN < a[i])
            {
                MAXMIN = a[i];
            }
        }
    }
    else if (MaxOrMin == 0) // Nhỏ nhất
    {
        for (int i = 1; i < n; i++)
        {
            if (MAXMIN > a[i])
            {
                MAXMIN = a[i];
            }
        }
    }
    return &MAXMIN;
}

void ham_SapXepMang(int *a, int n, bool TangOrGiam)
{
    if (TangOrGiam == 1) // Tăng dần
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    else if (TangOrGiam == 0) // Giảm dần
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] < a[j])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

int *ham_TinhTongCoConTro(int *a, int n)
{
    int temp = 0;
    int &tong = temp;

    for (int i = 0; i < n; i++)
    {
        tong = tong + a[i];
    }
    return &tong;
}

int *ham_TinhTongKyPhapDoDoi(int *a, int n)
{
    int temp = 0;
    int &tong = temp;

    for (int i = 0; i < n; i++)
    {
        tong = tong + *(a + i);
    }
    return &tong;
}

//int *ham_TinhTongCoConTro1(int *a, int n)
//{
//    int tong = 0;
//
//    for (int i = 0; i < n; i++)
//    {
//        tong = tong + a[i];
//    }
//    return &tong;
//}

void ham_ThemPhanTuMangDong(int *&a, int &n, int &vitri, int &x)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;

    a = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    delete[] temp;

    cout << "\nNhap gia tri ban muon them: ";
    cin >> x;
    cout << "Nhap vi tri ban muon them: ";
    cin >> vitri;

    for (int i = n - 1; i >= vitri; i--)
    {
        a[i + 1] = a[i];
    }
    a[vitri] = x;
    n++;
}

void ham_XoaPhanTuMangDong(int *&a, int &n, int &vitri)
{
    cout << "\nNhap vi tri ban muon xoa: ";
    cin >> vitri;

    for (int i = vitri; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--; // VÍ DỤ n = 5 THÌ CHỖ NÀY GIẢM n CÒN 4

    int *temp = new int[n]; // CẤP PHÁT MẢNG PHỤ CÓ n Ô TỨC LÀ 4 Ô
    for (int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;

    a = new int[n]; // CẤP PHÁT MẢNG MỚI CÓ n Ô TỨC LÀ 4 Ô
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    delete[] temp;
}