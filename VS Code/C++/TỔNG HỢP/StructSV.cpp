#include <iostream>
#include <string >
#include <cmath>
using namespace std;

// Khai báo cấu trúc 1 sinh viên
struct sinhvien
{
    string maso;
    string hoten;
    int namsinh;
    float diem_tb;
};
typedef struct sinhvien SINHVIEN;

// khuôn mẫu hàm - để cho người khác biết mình sử dụng những hàm gì trong chương trình
void Nhap_Thong_Tin_Sinh_Vien(SINHVIEN &x);
void Nhap_Danh_Sach_Sinh_Vien(SINHVIEN arr[], int n);
void Xuat_Thong_Tin_1_Sinh_Vien(SINHVIEN x);
void Xuat_Danh_Sach_Sinh_Vien(SINHVIEN arr[], int n);
void Tim_Kiem_Sinh_Vien_Theo_Diem(SINHVIEN arr[], int n, float diem);
void Them(SINHVIEN arr[], int &n, int vt, SINHVIEN x);
void Xoa(SINHVIEN arr[], int &n, int vt);
void Sap_Xep_Tang_Dan_Diem_TB(SINHVIEN arr[], int n);
int main() // nếu tạo 1 hàm thì nên tạo sau hàm main rồi copy hàm lên trước hàm main - nhớ copy hàm, cuối hàm có dấu ";"
{
    SINHVIEN arr[100];
    int n;
    cout << "\nNhap so luong sinh vien : ";
    cin >> n;

    // nhập và xuất danh sách sinh viên
    Nhap_Danh_Sach_Sinh_Vien(arr, n);
    Xuat_Danh_Sach_Sinh_Vien(arr, n);

    // tìm kiếm sinh viên theo điểm
    int diem_tk;
    cout << "\nNhap diem can tim kiem: ";
    cin >> diem_tk;
    Tim_Kiem_Sinh_Vien_Theo_Diem(arr, n, diem_tk);

    // thêm sinh viên vào vị trí do người dùng nhập
    int vt;
    SINHVIEN x; // tạo 1 struct sinh viên để thêm vào mảng sinh viên
    cout << " \nNhap vi tri can them: ";
    cin >> vt; // vị trí được quy ước bắt đầu từ 1
    cout << "\n\tNHAP THONG TIN SINH VIEN CAN THEM\n";
    Nhap_Thong_Tin_Sinh_Vien(x);
    //do quy ước vị trí bắt đầu từ 1 nên truyền vào hàm là " vt -1", chương trình hiểu là truyền vào mảng ở vị trí thứ vt - 1
    Them(arr, n, vt - 1, x);
    Xuat_Danh_Sach_Sinh_Vien(arr, n);

    // tìm kiếm thông tin sinh viên bằng mã sinh viên
    string str;   // tạo 1 chuỗi nhập vào để tìm kiếm mã sinh viên, do mã sinh viên khai báo ở struct là string
    cin.ignore(); // bỏ qua ký tự xuống dòng, do trước đó nhập số nên tránh câu lệnh nhập chuỗi mã sinh viên có thể bị bỏ qua, không cho nhập
    cout << "\nNhap ma sinh vien de xoa du lieu sinh vien: ";
    getline(cin, str);
    int dem = 0; // kiểm tra xem mã sinh viên có trong danh sách sinh vien hay không.
    for (int i = 0; i < n; i++)
    {
        if (str == arr[i].maso) // nếu tìm thấy mã sv thì thực hiện lệnh xóa sinh viên đó ra khỏi danh sách.
        {
            Xoa(arr, n, i);
            dem++; // nếu tìm thấy mã sinh viên thì tăng biến đếm lên 1 đơn vị
        }
    }
    if (dem == 0) // nếu không tìm thấy mã sv thì xuất câu lệnh ở dưới
        cout << "\nKhong tim thay ma sinh vien trong danh sach. Vui long thu lai sau!\n";
    else // nếu tìm được mã sv thì xuất ra danh sách sinh viên
    {
        cout << "\n\tDANH DANH SACH SINH VIEN SAU KHI XOA\n";
        Xuat_Danh_Sach_Sinh_Vien(arr, n);
    }

    // sắp xếp danh sách sinh viên theo thứ tự tăng dần của điểm trung bình
    cout << "\n\tDANH SACH SINH VIEN SAU TANG DAN THEO DIEM TB\n";
    Sap_Xep_Tang_Dan_Diem_TB(arr, n);
    Xuat_Danh_Sach_Sinh_Vien(arr, n);

    system("pause ");
    return 0;
}
// hàm nhập 1 thằng sinh viên
void Nhap_Thong_Tin_Sinh_Vien(SINHVIEN &x)
{
    cin.ignore();
    cout << "- Nhap ma so sinh vien : ";
    getline(cin, x.maso);
    cout << "- Nhap ho ten sinh vien : ";
    getline(cin, x.hoten);
    cout << "- Nhap nam sinh sinh vien : ";
    cin >> x.namsinh;
    cout << "- Nhap diem tb sinh vien : ";
    cin >> x.diem_tb;
}
// hàm xuất thông tin 1 sinh viên
void Xuat_Thong_Tin_1_Sinh_Vien(SINHVIEN x)
{
    cout << "\n- Ma so sinh vien : " << x.maso;
    cout << "\n- Ho ten sinh vien : " << x.hoten;
    cout << "\n- Nam sinh sinh vien : " << x.namsinh;
    cout << "\n- Diem tb sinh vien : " << x.diem_tb;
}
// hàm nhập nhiều sinh viên - hàm nhập danh sách sinh viên
void Nhap_Danh_Sach_Sinh_Vien(SINHVIEN arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
        Nhap_Thong_Tin_Sinh_Vien(arr[i]);
    }
}
// hàm xuất thông tin sinh viên
void Xuat_Danh_Sach_Sinh_Vien(SINHVIEN arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tTHONG TIN SINH VIEN THU " << i + 1;
        Xuat_Thong_Tin_1_Sinh_Vien(arr[i]);
        cout << endl; // endl cho đẹp giao diện ^_^
    }
}
// hàm tìm kiếm thông tin sinh viên dựa vào điểm
void Tim_Kiem_Sinh_Vien_Theo_Diem(SINHVIEN arr[], int n, float diem)
{
    int dem = 0; // biến đếm để tìm kiếm sinh viên có điểm cần tìm hay không
    for (int i = 0; i < n; i++)
    {
        if (arr[i].diem_tb == diem) // nếu điểm do người dùng nhập trùng với điểm có trong danh sách thì xuất thông tin sv đó
        {
            cout << "\n\t THONG TIN SINH VIEN THU " << ++dem;
            Xuat_Thong_Tin_1_Sinh_Vien(arr[i]);
        }
    }
    if (dem == 0) // nếu không tìm thấy điểm do người dùng nhập thì xuất lệnh "không tìm thấy"
        cout << "\nKhong tim thay sinh vien co diem bang " << diem << endl;
}
// hàm thêm sinh viên vào vị trí bất kì
void Them(SINHVIEN arr[], int &n, int vt, SINHVIEN x)
{
    for (int i = n - 1; i >= vt; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[vt] = x;
    n++;
}
// hàm xóa sinh viên
void Xoa(SINHVIEN arr[], int &n, int vt)
{
    for (int i = vt + 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
}
// hàm sắp xếp danh sách sinh viên tăng dần theo điểm tb
void Sap_Xep_Tang_Dan_Diem_TB(SINHVIEN arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].diem_tb > arr[j].diem_tb)
            {
                SINHVIEN tam; // tạo 1 struct sinh viên trung gian
                tam = arr[i]; // 3 dòng code còn lại là hoán vị 2 vị trí sinh viên
                arr[i] = arr[j];
                arr[j] = tam;
            }
        }
    }
}