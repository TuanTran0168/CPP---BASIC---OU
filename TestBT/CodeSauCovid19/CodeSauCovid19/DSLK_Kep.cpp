#include <iostream>
using namespace std;

struct NODE
{
	int Infor;
	struct NODE *Next;
	struct NODE *Previous;
};
typedef struct NODE Node;

Node *First;
Node *Last;

void Init();
void Process_List();
void Process_List_Reverse();
void Insert_First(int x);
void Insert_Last(int x);
Node *Search(int x);
Node *Search_Reverse(int x);
int Length_List();
int Delete_First();
int Delete_Last();

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
				Process_List();
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 3:
			if (CheckInit)
			{
				cout << "\nDanh sach tu cuoi len dau: ";
				Process_List_Reverse();
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
				Node *KQ = Search(x);

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
				Node *KQ = Search_Reverse(x);

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

				Insert_First(x);
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

				Insert_Last(x);
				cout << "\nThuc hien thanh cong!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 8:
			if (CheckInit)
			{
				int KQ = Delete_First();

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
				int KQ = Delete_Last();

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
				cout << "\nSo luong Node trong danh sach la: " << Length_List() << " Node!";
			}
			else
				cout << "\nBan chua khoi tao danh sach!";
			break;
		case 11:
			if (CheckInit)
			{
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
	First = NULL;
	Last = NULL;
}
void Process_List()
{
	Node *p = First;
	while (p != NULL)
	{
		cout << p->Infor << " ";
		p = p->Next;
	}
}
void Process_List_Reverse()
{
	Node *p = Last;
	while (p != NULL)
	{
		cout << p->Infor << " ";
		p = p->Previous;
	}
}
void Insert_First(int x)
{
	Node *p = new Node;
	p->Infor = x;
	p->Previous = NULL;
	p->Next = First;

	if (First != NULL) //Neu danh sach co it nhat 1 Node
		First->Previous = p;
	else //Neu danh sach rong thi no cung la Node dau va Node cuoi luon
		Last = p;
	First = p;
}
void Insert_Last(int x)
{
	Node *p = new Node;
	p->Infor = x;
	p->Next = NULL;
	p->Previous = Last;

	if (Last != NULL) //Neu danh sach co it nhat 1 Node
		Last->Next = p;
	else //Neu danh sach rong thi no cung la Node dau va Node cuoi luon
		First = p;
	Last = p;
}
Node *Search(int x)
{
	Node *p = First;
	while (p != NULL && p->Infor != x)
	{
		p = p->Next;
	}
	return p;
}
Node *Search_Reverse(int x)
{
	Node *p = Last;
	while (p != NULL && p->Infor != x)
	{
		p = p->Previous;
	}
	return p;
}
int Length_List()
{
	int count = 0;
	Node *p = First;
	while (p != NULL)
	{
		p = p->Next;
		count++;
	}
	return count;
}
int Delete_First()
{
	if (First != NULL) // Co it nhat 1 Node trong danh sach moi xoa duoc
	{
		Node *p = First;
		First = First->Next;
		delete p;

		if (First != NULL) // Neu xoa xong ma Node First di chuyen qua ma van con 1 Node nua
			First->Previous = NULL;
		else // Neu xoa xong ma Node First di chuyen qua ma khong con Node nao
			Last = NULL;

		return 1;
	}
	return 0;
}
int Delete_Last()
{
	if (Last != NULL) // Co it nhat 1 Node trong danh sach moi xoa duoc
	{
		Node *p = Last;
		Last = Last->Previous;
		delete p;

		if (Last != NULL) // Neu xoa xong ma Node Last di chuyen qua ma van con 1 Node nua
			Last->Next = NULL;
		else // Neu xoa xong ma Node Last di chuyen qua ma khong con Node nao
			First = NULL;
		return 1;
	}
	return 0;
}