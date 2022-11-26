//- Chuỗi trong C: Bản chất là mảng 1 chiều các kí tự
//VD:
char s[30]; // chứa tối đa 29 kí tự
#include<string.h> // khai báo thư viện hỗ trợ dùng các hàm: strlen(), strcpy()....

//- Chuỗi trong C++: được hỗ trợ bởi cái class string
//VD: string s;
#include<string>// khai báo thư viện hỗ trợ các hàm xử lí


//=============================== NHẬP - XUẤT =============================== 
#include<iostream>
#include<string> // khai báo thư viện hỗ trợ dùng các hàm xử lí chuỗi
using namespace std;

// Nhập thông tin sinh viên gồm: họ tên, tuổi. Xuất kết quả
int main()
{
	//string s; // khai báo chuỗi string s
	//cout << "\nNhap chuoi: ";
	////cin >> s; // scanf(): C - lệnh nhập chuỗi nhưng không lấy kí tự khoảng trắng
	//getline(cin, s); // hàm nhập chuỗi s - nhận luôn kí tự khoảng trắng
	//cout << "\nChuoi nhan duoc: " << s;

	string hoten; // khai báo chuỗi chứa họ tên sinh viên
	int tuoi;

	cout << "\nNhap tuoi sinh vien: ";
	cin >> tuoi;
	cin.ignore(); // fflush(stdin); // xóa bộ nhớ đệm
	cout << "\nHo ten sinh vien: ";
	getline(cin, hoten);
	
	
	cout << "\n\t\t====== THONG TIN ======";
	cout << "\nHo ten sinh vien: " << hoten;
	cout << "\nTuoi sinh vien: " << tuoi;

	system("pause");
	return 0;
}

//============================ CÁC HÀM TRONG STRING C++ ============================ 
#include<iostream>
#include<string> // khai báo thư viện hỗ trợ dùng các hàm xử lí chuỗi
using namespace std;


int main()
{
	//char s[] = "lap trinh"; // 9 kí tự - tốn 9 byte để lưu chuỗi s
	//string str = "lap trinh";
	//cout << "\nKich thuoc that su can luu chuoi str: " << str.capacity();
	
	string s = "lap trinh";
	/*for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << endl;
	}*/
	//cout << "\nDo dai cua chuoi: " << s.length(); // lấy độ dài của chuỗi s

	//s.erase(s.begin() + 3); // xóa 1 kí tự trong chuỗi s tại vị trí thứ 3
	//cout << "\nChuoi sau khi xoa: " << s;

	//s.insert(s.begin() + 3, 'T'); // hàm thêm 1 kí tự 'T' tại vị trị số 3
	//cout << "\nChuoi sau khi them: " << s;
	//cout << "\nDo dai cua chuoi: " << s.length();

	s.push_back('C'); // thêm 1 kí tự - vào cuối chuỗi
	cout << "\nChuoi sau khi them 1 ki tu vao cuoi: " << s;

	system("pause");
	return 0;
}