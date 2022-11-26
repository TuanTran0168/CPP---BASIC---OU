#include <iostream>
using namespace std;
struct NODE
{
	int infor;
	struct NODE *left;
	struct NODE *right;
};
typedef struct NODE Node;

void khoiTao(Node *&root);
void themNode(Node *&p, int x);
void duyetLNR(Node *p);
void duyetNLR(Node *p);
void duyetLRN(Node *p);
Node *timKiem(Node *p, int x);
void searchStandFor(Node *&p, Node *&q);
int xoaNode(Node *&T, int x);


int main()
{
	int chon;
	int a[] = {40, 20, 50, 10, 25, 43, 55, 7, 15, 23, 30, 47, 60, 5, 21, 22};
	int n = 16;
	int x;
	Node *ketQua;
	int kQ;
	Node *root;

	do
	{
		system("cls");
		cout << "===== BTH CHUONG 4 - CAY NHI PHAN TIM KIEM =====\n";
		cout << "\n1. Khoi tao cay rong";
		cout << "\n2. Them Node vao cay";
		cout << "\n3. Duyet theo thu tu LNR";
		cout << "\n4. Duyet theo thu tu NLR";
		cout << "\n5. Duyet theo thu tu LRN";
		cout << "\n6. Tim kiem";
		cout << "\n7. Xoa";
		cout << "\n8. Thoat";

		cout << "\n\nNhap cai gi di: ";
		cin >> chon;

		switch(chon)
		{
		case 1:
			khoiTao(root);
			cout << "\nKhoi tao thanh cong!";
			break;
		case 2:
			for (int i = 0; i < n; i++)
			{
				themNode(root, a[i]);
			}
			cout << "\nThem thanh cong!!!";
			break;
		case 3:
			duyetLNR(root);
			break;
		case 4:
			duyetNLR(root);
			break;
		case 5:
			duyetLRN(root);
			break;
		case 6:
			cout << "\nNhap gia tri can tim: ";
			cin >> x;
			ketQua = timKiem(root, x);
			if (ketQua == NULL)
				cout << "\nKhong tim thay!!!";
			else
				cout << "\nTim thay " << x << " o dia chi " << ketQua;
			break;
		case 7:
			cout << "\nNhap x de xoa: ";
			cin >> x;
			kQ = xoaNode(root, x);
			if (kQ == 1)
				cout << "\nXoa thanh cong!!!";
			else
				cout << "\nXoa khong thanh cong!!!";
			break;
		case 8:
			cout << "\nDA THOAT!!!";
			break;
		default:
			cout << "\nChuc nang khong ton tai!!!";
		}
	
		cout << endl;
		system("pause");
	}while(chon != 8);
	system("pause");
	return 0;
}

void khoiTao(Node *&root)
{
	root = NULL;
}

void themNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->infor = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->infor > x)
			return themNode(p->left, x);
		else
			return themNode(p->right, x);
	}
}

void duyetLNR(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->infor << " ";
		duyetLNR(p->right);
	}
}

void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->infor << " ";
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}

void duyetLRN(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout << p->infor << " ";
	}
}

Node *timKiem(Node *p, int x)
{
	if (p != NULL)
	{
		if (x == p->infor)
			return p;
		else if (x > p->infor)
			return timKiem(p->right, x);
		else
			timKiem(p->left, x);
	}
	return NULL;
}

void searchStandFor(Node *&p, Node *&q)
{
    if (q->left == NULL)
    {
        p->infor = q->infor;
        p = q;
		//q = p;
        q = q->right;
    }
    else
    {
        searchStandFor(p, q->left);
    }
}

int xoaNode(Node *&T, int x)
{
    if (T == NULL)
        return -1;
    else if (T->infor == x)
    {
        Node *p = T;

        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)
            T = T->left;
        else
            searchStandFor(p, T->right);

        delete p;
		return 1;
    }
    else
    {
        if (T->infor < x)
            xoaNode(T->right, x);
        else if (T->infor > x)
            xoaNode(T->left, x);
    }
}