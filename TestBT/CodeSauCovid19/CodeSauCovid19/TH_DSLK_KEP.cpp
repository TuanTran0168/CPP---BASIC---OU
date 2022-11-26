#include <iostream>
using namespace std;

struct NODE
{
	int Infor;
	struct NODE *Next;
	struct NODE *Previous;
};
typedef struct NODE Node;

Node *first;
Node *last;

void Init();
void duyetDau();
void duyetCuoi();
void themDau(int x);
void themCuoi(int x);
Node *timKiem(int x);
Node *timKiemTuCuoi(int x);
int doDaiDanhSach();
int xoaDau();
int xoaCuoi();
int themSauQ(int x, int y);

int main()
{
	int choose;
	bool CheckInit = false;

	do
	{
		system("cls");
		cout << "\n\t======== MENU ========\n";
		cout << "\n1. Khoi tao danh sach"
			 << "\n2. Xuat danh sach tu dau toi cuoi"
			 << "\n3. Xuat danh sach tu cuoi len dau"
			 << "\n4. Tim kiem tu dau toi cuoi"
			 << "\n5. Tim kiem tu cuoi len dau"
			 << "\n6. Them dau"
			 << "\n7. Them cuoi"
			 << "\n8. Xoa dau"
			 << "\n9. Xoa cuoi"
			 << "\n10. Dem so luong Node trong danh sach"
			 << "\n11. Them sau Node q"
			 << "\n\nMoi ban nhap: ";
		cin >> choose;

		switch (choose)
		{
		case 1:
			Init();
			CheckInit = true;
			cout << "\nThuc hien thanh cong!";
			break;
		case 2:
			if (CheckInit)
			{
				cout << "\nDanh sach tu dau toi cuoi: ";
				duyetDau();
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 3:
			if (CheckInit)
			{
				cout << "\nDanh sach tu cuoi len dau: ";
				duyetCuoi();
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 4:
			if (CheckInit)
			{
				int x;
				cout << "\nTim kiem tu dau toi cuoi";
				cout << "\nNhap x can tim: ";
				cin >> x;
				Node *KQ = timKiem(x);

				if (KQ == NULL)
					cout << x << " khong co trong danh sach!";
				else
					cout << x << " co trong danh sach!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 5:
			if (CheckInit)
			{
				int x;
				cout << "\nTim kiem tu cuoi len dau";
				cout << "\nNhap x can tim: ";
				cin >> x;
				Node *KQ = timKiemTuCuoi(x);

				if (KQ == NULL)
					cout << x << " khong co trong danh sach!";
				else
					cout << x << " co trong danh sach!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 6:
			if (CheckInit)
			{
				int x;
				cout << "\nNhap x de them vao dau: ";
				cin >> x;

				themDau(x);
				cout << "\nThuc hien thanh cong!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 7:
			if (CheckInit)
			{
				int x;
				cout << "\nNhap x de them vao cuoi: ";
				cin >> x;

				themCuoi(x);
				cout << "\nThuc hien thanh cong!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 8:
			if (CheckInit)
			{
				int KQ = xoaDau();

				if (KQ == 1)
					cout << "\nThuc hien thanh cong!";
				else if (KQ == 0)
					cout << "\nThuc hien khong thanh cong!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 9:
			if (CheckInit)
			{
				int KQ = xoaCuoi();

				if (KQ == 1)
					cout << "\nThuc hien thanh cong!";
				else if (KQ == 0)
					cout << "\nThuc hien khong thanh cong!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 10:
			if (CheckInit)
			{
				cout << "\nSo luong Node trong danh sach la: " << doDaiDanhSach() << " Node!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 11:
			if (CheckInit)
			{
				int x, y;
				cout << "\nNhap gia tri Node q: ";
				cin >> y;
				cout << "\nNhap gia tri can them: ";
				cin >> x;
				themSauQ(x, y);

			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		default:
			cout << "\n\t======= EXIT ======\n";
		}
		cout << endl;
		system("pause");

	} while (choose >= 1 && choose <= 11);
	system("pause");
	return 0;
}

void Init()
{
	first = NULL;
	last = NULL;
}
void duyetDau()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p->Infor << " ";
		p = p->Next;
	}
}
void duyetCuoi()
{
	Node *p = last;
	while (p != NULL)
	{
		cout << p->Infor << " ";
		p = p->Previous;
	}
}
void themDau(int x)
{
	Node *p = new Node;
	p->Infor = x;
	p->Previous = NULL;
	p->Next = first;

	if (first != NULL) //Neu danh sach co it nhat 1 Node
		first->Previous = p;
	else //Neu danh sach rong thi no cung la Node dau va Node cuoi luon
		last = p;
	first = p;
}
void themCuoi(int x)
{
	Node *p = new Node;
	p->Infor = x;
	p->Next = NULL;
	p->Previous = last;

	if (last != NULL) //Neu danh sach co it nhat 1 Node
		last->Next = p;
	else //Neu danh sach rong thi no cung la Node dau va Node cuoi luon
		first = p;
	last = p;
}
Node *timKiem(int x)
{
	Node *p = first;
	while (p != NULL && p->Infor != x)
	{
		p = p->Next;
	}
	return p;
}
Node *timKiemTuCuoi(int x)
{
	Node *p = last;
	while (p != NULL && p->Infor != x)
	{
		p = p->Previous;
	}
	return p;
}
int doDaiDanhSach()
{
	int count = 0;
	Node *p = first;
	while (p != NULL)
	{
		p = p->Next;
		count++;
	}
	return count;
}
int xoaDau()
{
	if (first != NULL) // Co it nhat 1 Node trong danh sach moi xoa duoc
	{
		Node *p = first;
		first = first->Next;
		delete p;

		if (first != NULL) // Neu xoa xong ma Node first di chuyen qua ma van con 1 Node nua
			first->Previous = NULL;
		else // Neu xoa xong ma Node first di chuyen qua ma khong con Node nao
			last = NULL;

		return 1;
	}
	return 0;
}
int xoaCuoi()
{
	if (last != NULL) // Co it nhat 1 Node trong danh sach moi xoa duoc
	{
		Node *p = last;
		last = last->Previous;
		delete p;

		if (last != NULL) // Neu xoa xong ma Node last di chuyen qua ma van con 1 Node nua
			last->Next = NULL;
		else // Neu xoa xong ma Node last di chuyen qua ma khong con Node nao
			first = NULL;
		return 1;
	}
	return 0;
}

int themSauQ(int x, int y)
{
	Node *q = timKiem(y);
	if(q != NULL)
	{
		if (q == last)
		{
			themCuoi(x);
			return 1;
		}

		Node *p = new Node;
		p->Infor = x;
		p->Next = q->Next;
		p->Previous = q;
		q->Next = p;
		q = p->Next;
		q->Previous = p;
		return 1;
			
	}
	return 0;
}