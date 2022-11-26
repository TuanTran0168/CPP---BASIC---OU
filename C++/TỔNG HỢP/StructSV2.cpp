#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct SinhVien
{
    int choNgoi;
    int dayBan;
    string mssv;
    string hoLot;
    string ten;
    string namSinh;
    string nganhHoc;
    string queQuan;
};
typedef struct SinhVien SV;
struct DanhSachSv
{
    SinhVien **arr; // khai báo con trỏ để quản lý mảng động sinh viên.
    int dong, cot;  // số lượng sinh viên có trong danh sách.
    SinhVien *dsSv; // khai báo con trỏ danh sách sinh viên mảng 1 chiều.
};
// tiền khai báo và nguyên mẫu hàm.
void Doc_File_Thong_Tin_1_Sinh_Vien(ifstream &fileIn, SinhVien &sv);
void Xuat_Thong_Tin_1_Sinh_Vien(SinhVien x);
int main()
{
    DanhSachSv ds;
    SinhVien sv;
    ifstream fileIn;
    fileIn.open("D:\\TXT\\SoDoSinhVien.txt");
    if (fileIn.is_open())
    {
        while (!fileIn.eof())
        {
            fileIn >> ds.cot;
            fileIn.ignore();
            fileIn >> ds.dong;

            ds.arr = new SinhVien *[ds.dong];
            for (int i = 0; i < ds.dong; i++)
                ds.arr[i] = new SinhVien[ds.cot];

            for (int i = 0; i < ds.dong; i++)
            {
                for (int j = 0; j < ds.cot; j++)
                    Doc_File_Thong_Tin_1_Sinh_Vien(fileIn, ds.arr[i][j]);
            }
        }
        fileIn.close();
    }
    else
        cout << "\nDoc file khong thanh cong!.";
    /* do thứ tự dãy + chỗ ngồi trong file không theo thứ tự, nên sắp xếp lại vị trí dãy + chỗ ngồi trong file bằng cách tạo 2 mảng
    1 mảng 1 chiều ví dụ dssv chứa các sinh viên (mỗi phần tử trong mảng là 1 struct SV). Mảng thứ 2 là 1 mảng 2 chiều ví dụ sodo 
    ứng với số dãy bàn và số chỗ/dãy đã đọc trong tập tin (ví dụ lớp có 10 dãy và 7 chỗ/dãy).Như vậy ví dụ đọc vào 1 dòng và biết 
    sinh viên này ngồi ở chỗ 8 dãy 2: Đầu tiên, thêm sv này vào mảng dssv , giả sử vị trí vừa thêm vào là phần tử thứ 5 sau đó sẽ 
    gán sodo[2][8]=5. Như vậy khi muốn in dssv ngồi ở dãy k, chỉ việc duyệt i qua từng cột ở hàng k và sẽ in ra thông tin sinh viên 
    ở dssv[ sodo[k][i] ] */
    // lưu toàn bộ danh sách sinh viên vào mảng 1 chiều (cấp phát động).
    ds.dsSv = new SinhVien[ds.dong * ds.cot];
    int countdsSv = 0;
    for (int i = 0; i < ds.dong; i++)
        for (int j = 0; j < ds.cot; j++)
            ds.dsSv[countdsSv++] = ds.arr[i][j];
    // lưu mảng 2 chiều ứng với số dãy + chỗ ngồi (cấp phát động).
    int **arr = new int *[ds.dong];
    for (int i = 0; i < ds.dong; i++)
        arr[i] = new int[ds.cot];
    int count = 0;
    for (int i = 0; i < ds.dong; i++)
        for (int j = 0; j < ds.cot; j++)
            arr[ds.arr[i][j].dayBan - 1][ds.arr[i][j].choNgoi - 1] = count++;
    // menu lựa chọn.
    int luaChon;
    do
    {
        system("cls");
        cout << "==============================MENU====================================";
        cout << "\n< 1 >. In thong tin cac sinh vien cua 1 day ban.";
        cout << "\n< 2 >. In thong tin cac sinh vien o vi tri X cua tat ca cac day ban.";
        cout << "\n< 3 >. In thong tin sinh vien vien ngoi o day X vi tri cho Y.";
        cout << "\n< 4 >. In thong tin cac sinh vien theo khuon dang ten.";
        cout << "\n< 5 >. In thong tin cac sinh vien sinh vao thang M.";
        cout << "\n< 6 >. In thong tin cac sinh vien hoc nganh K.";
        cout << "\n< 7 >. In thong tin cac sinh vien co que quan la Q.";
        cout << "\n< 8 >. In thong tin cac sinh vien theo khuon dang dau cua mssv.";
        cout << "\n< 9 >. In thong tin cac sinh vien theo khuong dang cuoi cua mssv.";
        cout << "\n< 10 >. Tim vi tri co kha nang 'gian lan' trong lop.";
        cout << "\n< 11 >. Thoat chuong trinh.";
        cout << "\n====================================================================";
        cout << "\n=> Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon)
        {
        // quy ước chung: dãy(hoặc chỗ ngồi) bắt đầu từ số 1 ứng với phần tử 0 trong mảng => dãy(hoặc chỗ ngồi) i = phần tử i - 1.
        case 1:
        {
            int viTriDay;
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien cua 1 day ban.";
            cout << "\n- Nhap vi tri day ban: ";
            cin >> viTriDay;
            cout << "\n- Day " << viTriDay << " gom:";
            for (int i = 0; i < ds.cot; i++)
            {
                cout << "\n\tThong tin sinh vien thu " << i + 1;
                Xuat_Thong_Tin_1_Sinh_Vien(ds.dsSv[arr[viTriDay - 1][i]]);
            }
            break;
        }
        case 2:
        {
            int viTriChoNgoi;
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien o vi tri X cua tat ca cac day ban.";
            cout << "\n- Nhap vi tri cho ngoi: ";
            cin >> viTriChoNgoi;
            cout << "\n- Cho ngoi thu " << viTriChoNgoi << " cua tat ca cac day gom:";
            for (int i = 0; i < ds.dong; i++)
            {
                cout << "\n\n\tThong tin sinh vien thu " << i + 1;
                Xuat_Thong_Tin_1_Sinh_Vien(ds.dsSv[arr[i][viTriChoNgoi - 1]]);
            }
            break;
        }
        case 3:
        {
            int dayGhe, choNgoi;
            cout << "\n<=> Lua chon cua ban: In thong tin sinh vien vien ngoi o day X vi tri cho Y.";
            cout << "\n- Nhap vi tri day ban: ";
            cin >> dayGhe;
            cout << "- Nhap vi tri cho ngoi: ";
            cin >> choNgoi;
            cout << "\n\tThong tin sinh vien";
            Xuat_Thong_Tin_1_Sinh_Vien(ds.dsSv[arr[dayGhe - 1][choNgoi - 1]]);
            break;
        }
        case 4:
        {
            string ten;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên, tránh bị lỗi.
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien theo khuon dang ten.";
            cout << "\nVd: Nhap 'Th' se in ra thong tin sinh vien co ky tu 'Th' trong ten cua sinh vien do.";
            cout << "\n- Nhap khuon dang ten: ";
            getline(cin, ten);
            // tạo biến đếm để kiểm tra có tháng cần tìm có trong danh sách hay không(đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    if (ten == ds.arr[i][j].ten.substr(0, ten.length())) // so sánh khuôn dạng tên vừa nhập với số lượng ký tự tên đó trong danh sách(bắt đầu từ vt 0).
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin!.\n";
            break;
        }
        case 5:
        {
            string thang;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên.
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien sinh vao thang M.";
            // kiểm tra tính đúng sai khi nhập tháng.
            do
            {
                cout << "\n- Nhap thang: ";
                getline(cin, thang);
                if (thang.length() < 2 || thang > "12")
                    cout << "- Nhap sai (thang 1 -> 9 vui long them so 0). Moi nhap lai!";
            } while (thang.length() < 2 || thang > "12"); // tháng 1 - 9 bắt NSD nhập thêm số 0 và tháng nằm trong (1,12)
            // tạo biến đếm xem có tháng cần tìm có trong danh sách hay không (đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    // so sánh tháng vừa nhập với tháng trong danh sách(bắt đầu từ vị trí 3 trong chuỗi năm sinh - vị trí 3 là tháng).
                    if (thang == ds.arr[i][j].namSinh.substr(3, thang.length()))
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin!.\n";
            break;
        }
        case 6:
        {
            string nganhHoc;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên.
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien hoc nganh K.";
            cout << "\n\n\tDanh sach cac nganh\n";
            /* lưu tất cả các ngành trong danh sách sinh viên vào mảng 1 chiều, 
            số lượng phần tử trong mảng sẽ tự thay đổi khi số lượng phần tử trong file thay đổi */
            int maxPhanTu = ds.dong * ds.cot;
            string *arr = new string[maxPhanTu]; // cấp phát động mảng 1 chiều để tối ưu bộ nhớ
            int soLuong = 0;
            int dem = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    arr[soLuong++] = ds.arr[i][j].nganhHoc;
            // kiểm tra các ngành để lọc ra các ngành phân biệt
            for (int i = 0; i < soLuong; i++)
            {
                bool KT = true; // giả sử arr[i] là phần tử phân biệt
                // duyệt ngược về đầu chuỗi để kiểm tra cái giả sử ban đầu
                for (int j = i - 1; j >= 0; j--)
                {
                    if (arr[i] == arr[j])
                    {
                        KT = false;
                        break;
                    }
                }
                if (KT == true)
                    cout << "- " << arr[i] << endl;
            }
            delete[] arr; // giải phóng bộ nhớ
            arr = nullptr;
            cout << "\n- Nhap nganh hoc de tim sinh vien: ";
            getline(cin, nganhHoc);
            // tạo biến đếm xem có quê quán cần tìm có trong danh sách hay không (đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    // so sánh ngành học vừa nhập với ngành học trong danh sách
                    if (nganhHoc == ds.arr[i][j].nganhHoc)
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin hoac nhap sai dinh dang!.\n";
            break;
        }
        case 7:
        {
            string queQuan;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên.
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien co que quan la Q.";
            cout << "\n- Nhap que quan de tim sinh vien: ";
            getline(cin, queQuan);
            // tạo biến đếm xem có quê quán cần tìm có trong danh sách hay không (đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    if (queQuan == ds.arr[i][j].queQuan)
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin hoac nhap sai dinh dang(phai viet hoa ky tu dau moi tu)!.\n";
            break;
        }
        case 8:
        {
            string dauMssv;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên.
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien theo khuon dang dau cua mssv.";
            cout << "\nVd: Nhap 102 thi in ra nhung sinh vien co mssv ma 3 ky tu dau la 102.";
            // kiểm tra tính đúng sai khi nhập tháng.
            do
            {
                cout << "\n- Nhap khuon dang dau mssv: ";
                getline(cin, dauMssv);
                if (dauMssv.length() <= 0 || dauMssv.length() > 4)
                    cout << "- Nhap sai (chi nhap toi da 4 ky tu). Moi nhap lai!";
            } while (dauMssv.length() <= 0 || dauMssv.length() > 4); // tối đa 4 ký tự hoặc không được nhập rỗng.
            // tạo biến đếm xem có khuôn dạng đầu mssv cần tìm có trong danh sách hay không (đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    // so sánh khuôn dạng đầu mssv vừa nhập với dauMssv.length() trong danh sách (bắt đầu từ vị trí 0 trong chuỗi mssv)
                    if (dauMssv == ds.arr[i][j].mssv.substr(0, dauMssv.length()))
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin!.\n";
            break;
        }
        case 9:
        {
            string cuoiMssv;
            cin.ignore(); // xóa ký tự xuống dòng khi thực hiện các câu lệnh ở trên
            cout << "\n<=> Lua chon cua ban: In thong tin cac sinh vien theo khuon dang cuoi cua mssv.";
            cout << "\nVd: Nhap 78 thi in ra nhung sinh vien co mssv ma 2 ky tu cuoi bang 78.";
            // kiểm tra tính đúng sai khi nhập tháng
            do
            {
                cout << "\n- Nhap khuon dang cuoi mssv: ";
                getline(cin, cuoiMssv);
                if (cuoiMssv.length() <= 0 || cuoiMssv.length() > 4)
                    cout << "- Nhap sai (chi nhap toi da 4 ky tu). Moi nhap lai!";
            } while (cuoiMssv.length() <= 0 || cuoiMssv.length() > 4);
            // tạo biến đếm xem có khuôn dạng cuối mssv cần tìm có trong danh sách hay không (đồng thời nếu 2 sinh viên trở lên thì count được coi là thứ tự danh sách).
            int count = 0;
            for (int i = 0; i < ds.dong; i++)
                for (int j = 0; j < ds.cot; j++)
                    // so sánh khuôn dạng cuối mssv vừa nhập với dauMssv.length() trong danh sách (bắt đầu từ vị trí độ dài chuỗi mssv - độ dài khuôn dạng cuối)
                    if (cuoiMssv == ds.arr[i][j].mssv.substr(ds.arr[i][j].mssv.length() - cuoiMssv.length(), cuoiMssv.length()))
                    {
                        count++;
                        cout << "\n\tThong tin sinh vien thu " << count;
                        Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i][j]);
                    }
            if (count == 0)
                cout << "- Khong tim thay thong tin!.\n";
            break;
        }
        case 10:
        {
            cout << ds.dsSv[arr[0][0]].hoLot << " " << ds.dsSv[arr[0][0]].ten;
            cout << "\n<=> Lua chon cua ban: Tim vi tri co kha nang 'gian lan' trong lop.\n";
            cout << "*Note: A co kha nang gian lan khi nguoi ngoi sau lung A la nguoi cung nganh hoac cung que quan.\n";
            int flag = 0; // đánh dấu xem trong danh sách, sinh viên có khả năng gian lận hay không.
            cout << "\n\tDanh sach sinh vien co kha nang gian lan";
            for (int i = 0; i < ds.dong; i++)
            {
                if (i == ds.dong - 1) // dãy cuối cùng không có khả năng gian lận, vì thế khi đến cuối thì thoát vòng lặp.
                    break;
                for (int j = 0; j < ds.cot; j++)
                {
                    // kiểm tra quê quán hoặc ngành học của dãy trên và dãy dưới
                    if (ds.dsSv[arr[i][j]].queQuan == ds.dsSv[arr[i + 1][j]].queQuan)
                    {
                        flag = 1;
                        cout << "\n- " << ds.dsSv[arr[i][j]].hoLot << " " << ds.dsSv[arr[i][j]].ten << " o day " << i + 1 << " cho ngoi thu " << j + 1 << " co kha nang gian lan(cung que quan).";
                    }
                    if (ds.dsSv[arr[i][j]].nganhHoc == ds.dsSv[arr[i + 1][j]].nganhHoc)
                    {
                        flag = 1;
                        cout << "\n- " << ds.dsSv[arr[i][j]].hoLot << " " << ds.dsSv[arr[i][j]].ten << " o day " << i + 1 << " cho ngoi thu " << j + 1 << " co kha nang gian lan(cung nganh hoc).";
                    }
                }
            }
            if (flag == 0)
                cout << "\n- Khong co vi tri nao co kha nang gian lan!.\n";
            break;
        }
        case 11:
        {
            cout << "\nBan da chon thoat!.\n";
            break;
        }
        }
        system("pause");
    } while (luaChon != 11);

    // giải phóng bộ nhớ con trỏ (danh sách sv đọc từ file).
    for (int i = 0; i < ds.dong; i++)
        delete[] ds.arr[i];
    delete[] ds.arr;
    ds.arr = nullptr;
    // giải phóng bộ nhớ con trỏ (danh sách sv mảng 1 chiều).
    delete[] ds.dsSv;
    ds.dsSv = nullptr;
    // giải phóng bộ nhớ con trỏ (danh sách dãy bàn + chỗ ngồi).
    for (int i = 0; i < ds.dong; i++)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
    return 0;
}
// hàm đọc file (đọc thông tin 1 sv từ file)
void Doc_File_Thong_Tin_1_Sinh_Vien(ifstream &fileIn, SinhVien &sv)
{
    fileIn >> sv.choNgoi;
    fileIn.ignore();
    fileIn >> sv.dayBan;
    fileIn.ignore();
    getline(fileIn, sv.mssv, ',');
    getline(fileIn, sv.hoLot, ',');
    getline(fileIn, sv.ten, ',');
    getline(fileIn, sv.namSinh, ',');
    getline(fileIn, sv.nganhHoc, ',');
    getline(fileIn, sv.queQuan);
}
// hàm xuất thông tin 1 sinh viên
void Xuat_Thong_Tin_1_Sinh_Vien(SinhVien x)
{
    cout << "\n- Vi tri cho ngoi: " << x.choNgoi;
    cout << "\n- Vi tri day ban: " << x.dayBan;
    cout << "\n- Mssv: " << x.mssv;
    cout << "\n- Ho va ten: " << x.hoLot << " " << x.ten;
    cout << "\n- Ngay sinh: " << x.namSinh;
    cout << "\n- Nganh hoc: " << x.nganhHoc;
    cout << "\n- Que quan: " << x.queQuan << endl;
}