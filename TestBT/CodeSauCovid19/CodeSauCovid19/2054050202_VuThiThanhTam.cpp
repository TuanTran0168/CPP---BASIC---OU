#include<iostream>
#include<string>
using namespace std;
struct SinhVien
{
	string mssv, hoTen, diaChi, gioiTinh;
	int namSinh;
	double diemTB;
}sv;
struct Node
{
	SinhVien info;
	Node *link;
	
};
struct List
{
	Node* first;
};
void khoiTao(List &l)
{
	l.first = NULL;

}
Node * taoNode()
{
	Node *p = new Node;
	cout << "Nhap thong tin sinh vien: \n";
	SinhVien sv;
	cout << "Nhap MSSV: ";
	getline(cin, sv.mssv);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);
	cout << "Nhap dia chi ";
	getline(cin, sv.gioiTinh);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cout << "Nhap diem trung binh: ";
	cin >> sv.diemTB;
	p->info = sv;
	p->link = NULL;
	return p;
}
void nhapSV(List &l)
{
	int flag = 0;

	do {
		Node *p = new Node;
		cout << "Nhap thong tin sinh vien: \n";
		SinhVien sv;
		cout << "Nhap MSSV: ";
		getline(cin, sv.mssv);
		cout << "Nhap ho ten: ";
		getline(cin, sv.hoTen);
		cout << "Nhap dia chi ";
		getline(cin, sv.gioiTinh);
		cout << "Nhap nam sinh: ";
		cin >> sv.namSinh;
		cout << "Nhap diem trung binh: ";
		cin >> sv.diemTB;
		p->info = sv;
		p->link = l.first;
		l.first = p;
		cout << "Nhap tiep khong (1/0 - Co/Khong)";
		cin >> flag;
		cin.ignore(1);
	} while (flag);
}
void xuatSV(List l)
{
	if (l.first == NULL)
		cout << "Danh sach rong: \n";
	Node* p = l.first;
	int i = 1;
	while (p != NULL)
	{
		cout << "-----------------\n";
		cout << "sinh vien thu " << i << ": \n";
		cout << "Ma so sinh vien: " << p->info.mssv << endl;
		cout << "Ho ten: " << p->info.hoTen << endl;
		cout << "Nam sinh: " << p->info.namSinh << endl;
		cout << "Dia chi: " << p->info.diaChi << endl;
		cout << "Diem trung binh: " << p->info.diemTB << endl;
		p = p->link;
		i++;

	}

}
void chinhSua(List &l, string mssv)
{
	Node *p = l.first;
	while (p != NULL)
	{
		if (p->info.mssv == mssv)
		{
			cout << "Nhap mssv: ";
			cin >> p->info.mssv;
			cout << "Nhap ho ten:";
			cin >> p->info.hoTen;
			cout << "Nhap nam sinh: ";
			cin >> p->info.namSinh;
			cout << "Nhap dia chi: ";
			cin >> p->info.diaChi;
			cout << "nhap diem trung binh: ";
			cin >> p->info.diemTB;

			break;
		}
		else
			p = p->link;
	}
		if (p != NULL)
			cout << "MSSV khong co!\n";

}
void them(List &l)
{
	SinhVien sv;
	cin.ignore(1);
	cout << "Nhap MSSV: ";
	getline(cin, sv.mssv);
	cout << "Nhap ho ten: ";
	getline(cin, sv.hoTen);
	cout << "Nhap dia chi ";
	getline(cin, sv.gioiTinh);
	cout << "Nhap nam sinh: ";
	cin >> sv.namSinh;
	cout << "Nhap diem trung binh: ";
	cin >> sv.diemTB;
	cin.ignore(1);
	Node *p = new Node;
	p->info = sv;
	p->link = l.first;
	l.first = p;
}
int main()
{
	List listS;
	khoiTao(listS);
	nhapSV(listS);
	xuatSV(listS);
	string mssv;
	cout << "\n----------------------\n";
	cout <<" Nhap ma so sinh vien can chinh sua : ";
	getline(cin, mssv);
	chinhSua(listS, mssv);
	cout << "sau khi hieu chinh: \n";
	xuatSV(listS);
	cout << "\--------------\n";
	cout << "Them thong tin 1 sinh vien\n";
	them(listS);
	xuatSV(listS);
	system("pause");
}