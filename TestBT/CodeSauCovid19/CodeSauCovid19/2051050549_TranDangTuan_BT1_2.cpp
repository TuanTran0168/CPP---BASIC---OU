#include <iostream>
using namespace std;

struct NODE
{
	int infor;
	struct NODE *link;
};
typedef struct NODE Node;
Node *first = NULL;

void khoiTao();
void duyetDS();
void themDau(int x);
void themCuoi(int x);
Node *timKiem(int x);
int timKiemViTri(int x);
int xoaDau();
int xoaCuoi();
int doDaiDanhSach();
int xoaNode(int viTri);
int timKiemSoLuong(int x);
void timVaXoaHet(int x);
int themSauNodeQ(int x);

int main()
{
	int chon;
	bool check = false;
	int x;
	int kQ;

	do
	{
		system("cls");
		cout << "1. Khoi tao danh sach\n";
		cout << "2. Xuat danh sach\n";
		cout << "3. Tim kiem va tra ve vi tri dau tien\n";
		cout << "4. Them dau\n";
		cout << "5. Xoa dau\n";
		cout << "6. Them cuoi\n";
		cout << "7. Xoa cuoi\n";
		cout << "8. Tim va xoa het\n";
		cout << "9. Tim va them vao sau\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Moi ban chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			khoiTao();
			check = true;
			cout << "\nKhoi tao thanh cong!!!";
			break;

		case 2:
			if (check == true)
			{
				duyetDS();
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 3:
			if (check == true)
			{
				cout << "\nNhap so can tim: ";
				cin >> x;
				kQ = timKiemViTri(x);
				if (kQ != -1)
					cout << "\nTim thay gia tri " << x << " o vi tri " << kQ << endl;
				else
					cout << "\nKhong tim thay!!!";
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 4:
			if (check == true)
			{
				cout << "\nNhap gia tri can them :";
				cin >> x;
				themDau(x);
				cout << "\nThem thanh cong!!!";
				cout << "\nDanh sach sau khi them: ";
				duyetDS();
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 5:
			if (check == true)
			{
				kQ = xoaDau();
				if (kQ == 1)
				{
					cout << "\nXoa thanh cong!!!";
					cout << "\nDanh sach sau khi xoa: ";
					duyetDS();
				}
				else
					cout << "\nXoa khong thanh cong!!!";
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 6:
			if (check == true)
			{
				cout << "\nNhap gia tri can them: ";
				cin >> x;
				themCuoi(x);
				cout << "\nThem thanh cong!!!";
				cout << "\nDanh sach sau khi them: ";
				duyetDS();
			}
			break;

		case 7:
			if (check == true)
			{
				kQ = xoaCuoi();
				if (kQ == 1)
				{
					cout << "\nXoa thanh cong!!!";
					cout << "\nDanh sach sau khi xoa: ";
					duyetDS();
				}
				else
					cout << "\nXoa khong thanh cong!!!";
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 8:
			if (check == true)
			{
				cout << "\nNhap gia tri can xoa het :";
				cin >> x;
				timVaXoaHet(x);
				cout << "\nDanh sach sau khi xoa: ";
				duyetDS();
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 9:
			if (check == true)
			{
				cout << "\nNhap node can them vao sau: ";
				cin >> x;

				kQ = themSauNodeQ(x);
				if (kQ == 1)
				{
					cout << "\nXoa thanh cong!!!";
					cout << "\nDanh sach sau khi them: ";
					duyetDS();
				}
				else
					cout << "Xoa khong thanh cong!!!";
			}
			else
				cout << "\nVui long khoi tao danh sach!!!";
			break;

		case 0:
			cout << "Chuong trinh ket thuc";
			break;
		default:
			cout << "Chuc nang khong ton tai!!!";
		}

		cout << endl;
		system("pause");
	} while (chon != 0);

	cout << endl;
	system("pause");
	return 0;
}

void khoiTao()
{
	first = NULL;
}
void duyetDS()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p->infor << " ";
		p = p->link;
	}
}
void themDau(int x)
{
	Node *p = new Node;
	p->infor = x;
	p->link = first;
	first = p;
}
void themCuoi(int x)
{
	Node *p = new Node;
	p->infor = x;
	p->link = NULL;

	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
Node *timKiem(int x)
{
	Node *p = first;
	while (p != NULL && p->infor != x)
	{
		p = p->link;
	}

	return p;
}
int timKiemViTri(int x)
{
	Node *p = first;
	int count = 0;
	while (p != NULL && p->infor != x)
	{
		count++;
		p = p->link;
	}

	if (p == NULL)
		return -1;
	return count;
}

int xoaDau()
{
	Node *p = first;
	if (first != NULL)
	{
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int xoaCuoi()
{
	if (first != NULL)
	{
		Node *p = first;
		Node *q = NULL;

		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}

		if (p == first)
			first = first->link;
		else
			q->link = NULL;

		delete p;
		return 1;
	}
	return 0;
}

int doDaiDanhSach()
{
	Node *p = first;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->link;
	}
	return count;
}
int xoaNode(int viTri)
{
	if (first != NULL)
	{
		if (viTri == 0)
		{
			xoaDau();
			return 1;
		}
		else if (viTri == doDaiDanhSach())
		{
			xoaCuoi();
			return 1;
		}
		else if (viTri > 0 && viTri < doDaiDanhSach())
		{
			Node *temp = first;
			Node *q = NULL;
			int count = 0;
			while (temp->link != NULL && count != viTri)
			{
				count++;
				q = temp;
				temp = temp->link;
			}
			q->link = temp->link;
			delete temp;
			return 1;
		}
	}
	return 0;
}
int timKiemSoLuong(int x)
{
	Node *p = first;
	int count = 0;
	while (p != NULL)
	{
		if (p->infor == x)
			count++;
		p = p->link;
	}
	return count;
}

void timVaXoaHet(int x)
{
	int soLuong = timKiemSoLuong(x);
	while (soLuong > 0)
	{
		int viTri = timKiemViTri(x);
		xoaNode(viTri);
		soLuong--;
	}
}

int themSauNodeQ(int x)
{
	Node *q = timKiem(x);
	if (q != NULL)
	{
		Node *p = new Node;
		p->infor = q->infor + 1;
		p->link = q->link;
		q->link = p;
		return 1;
	}
	return 0;
}