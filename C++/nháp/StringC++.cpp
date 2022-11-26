#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name = "Tran Dang Tuan";
	//cout << "Nhap ho va ten cua ban: ";
	//getline(cin, name);
	cout << "\nTen cua ban la: " << name;


    // s.length() là hàm thuộc tính trả về 1 số nguyên là số ký tự trong chuỗi s
    cout << "\nDo dai ten cua ban la: " << name.length();


    //toupper() chuyển ký tự kt thành in hoa. Trả về 1 ký tự sau khi in hoa.
    // Không thể tự gọi đơn thuần mà phải gán kết quả cho 1 biến cùng kiểu.
    for (int i = 0; i < name.length(); i++)
    {
        name[i] = toupper(name[i]);
    }
     cout <<"\nViet in hoa: " << name;
    

    //s.substr(begin_position [, size_t_n] ): lấy chuỗi con bắt đầu từ vị trí begin_position
    // và số ký tự lấy là size_t_n. Trả về 1 chuỗi con (dạng string).
    // Không thể tự gọi đơn thuần mà phải gán kết quả cho 1 biến cùng kiểu.
    string a = name.substr(10, 4 );
    cout << "\nLay chuoi con tu trong chuoi name la: " << a;


    //s.find(search_string, begin_position_search): tìm 1 chuỗi
    //con search_string xem có ở trong s hay không (kể từ vị trí bắt đầu là
    //begin_position_search về cuối chuỗi). Nếu không tìm thấy sẽ trả về -1,
    //nếu có trả về vị trí đầu tiên xuất hiện.
    //Không thể tự gọi đơn thuần mà phải gán kết quả cho 1 biến SỐ NGUYÊN.
    string TimKiem1 = "Tuan";
    string TimKiem2 = "TUAN";
    int KQ1 = name.find(TimKiem1, 0);
    int KQ2 = name.find(TimKiem2, 0);
    cout << "\nTim chu Tuan trong chuoi name: " << KQ1;
    cout << "\nTim chu TUAN trong chuoi name: " << KQ2;


    //s.erase(begin_position [, size_t_n]): xóa đi size_t_n
    //ký tự kể từ vị trí bắt đầu xóa là begin_position. Nếu không ấn
    //định size_t_n thì sẽ xóa kể từ vị trí bắt đầu về cuối chuỗi. Trả về chuỗi sau khi xóa.
    //CHUỖI CÓ THỂ XÓA TRỰC TIẾP TRÊN BẢN THÂN VÀ GÁN LẠI CHO CHÍNH NÓ.
    name.erase(5, 4);
    cout << "\nTen sau khi xoa la: " << name;

    //s.replace (begin_position, size_t_n, replace_string):
    //thay thế chuỗi thay thế replace_string với số ký tự cần thay thế là size_t_n 
    //kể từ vị trí bắt đầu begin_position. Kết quả trả về 1 chuỗi sau khi thay thế.
    //CHUỖI CÓ THỂ THAY THẾ TRỰC TIẾP TRÊN BẢN THÂN VÀ GÁN LẠI CHO CHÍNH NÓ.
    string name1 = "Dang";
    name.replace(0, 4, name1);
    cout << "\nTen sau khi thay the la: " << name;


    //s.insert (begin_position, insert_string): Chèn chuỗi insert_string vào chuỗi s kể từ vị trí bắt đầu
    //begin_position.Kết quả trả về chuỗi sau khi chèn.
    //CHUỖI CÓ THỂ XÓA TRỰC TIẾP TRÊN BẢN THÂN VÀ GÁN LẠI CHO CHÍNH NÓ.
    name.insert(0, "Tran ");
    cout << "\nTen sau khi chen la: " << name;


    //s.assign (count, assign_char): Gán ký tự assign_char vào chuỗi s với count số lần.
    // Kết quả trả về chuỗi sau khi gán.
    //CHUỖI CÓ THỂ XÓA TRỰC TIẾP TRÊN BẢN THÂN VÀ GÁN LẠI CHO CHÍNH NÓ.
    name.assign(10, '+');
    cout << "\nTen sau khi gan tam bay la: " << name;

    cout << endl;
	system("pause");
	return 0;
}