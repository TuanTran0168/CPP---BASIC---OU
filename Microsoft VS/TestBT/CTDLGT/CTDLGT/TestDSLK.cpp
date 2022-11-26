#include <iostream>
using namespace std;
void ham_NhapDanhSachNode(int &n);
void ham_ThemDau(struct Node *p);
void ham_ThemCuoi(struct Node *p);
void ham_ThemCuoiLast(struct Node *p);
void ham_XuatDanhSachNode();

struct Node
{
	int infor;
	Node *link;
};

Node *first = NULL;

int main2()
{
	int n;
	ham_NhapDanhSachNode(n);
	ham_XuatDanhSachNode();

	system("pause");
	return 0;
}

struct Node *ham_NhapMotNode(int x)
{
	Node *p = new Node;
	p->infor = x;
	p->link = NULL;

	return p;
}

void ham_ThemDau(struct Node *p)
{
	p->link = first;
	first = p;
}

void ham_ThemCuoi(struct Node *p)
{
	Node *q = first;
	while (q->link != NULL)
	{
		q = q->link;
	}

	q->link = p;
}

void ham_NhapDanhSachNode(int &n)
{
	cout << "Nhap so luong Node: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "Nhap x[" << i << "]: ";
		cin >> x;

		ham_ThemDau(ham_NhapMotNode(x));
	}
}

void ham_XuatDanhSachNode()
{
	cout << "\nDanh sach Node" << endl;

	for (Node *i = first; i != NULL; i = i->link)
	{
		cout << i->infor << " ";
	}
}