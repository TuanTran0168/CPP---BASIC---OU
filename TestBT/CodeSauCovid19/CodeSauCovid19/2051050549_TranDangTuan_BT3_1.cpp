#include <iostream>
using namespace std;
struct NODE
{
	int infor;
	struct NODE *left;
	struct NODE *right;
};
typedef struct NODE Node; // Node cua cay nhi phan

void khoiTao(Node *&root);
void themNodeKhongDeQuy(Node *p, int x);
void themNodeKhongDeQuy1(Node *&p, int x);
void themNodeKhongDeQuy2(Node *p, int x);
void duyetLNR(Node *p);
void duyetNLR(Node *p);
void duyetLRN(Node *p);
Node *timKiem(Node *p, int x);
void searchStandFor(Node *&p, Node *&q);
int xoaNodeKhongDeQuy(Node *&T, int x);

// ===== STACK =====
struct NoDe
{
	int infor;
	struct NoDe *link;
};
typedef struct NoDe NodeSQ; // Node xai Stack va Queue

void khoiTaoStack();
void pushStack(int x);
int popStack(int &x);
int isEmptyStack();
NodeSQ *sp;

// ===== QUEUE =====
void khoiTaoQueue();
void pushQueue(int x);
int popQueue(int &x);
int isEmptyQueue();

NodeSQ *front;
NodeSQ *rear;

void themNodeCu(Node *&p, int x);

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
				themNodeCu(root, a[i]);
				//themNodeKhongDeQuy(root, a[i]);
				//themNodeKhongDeQuy1(root, a[i]);
				//themNodeKhongDeQuy2(root, a[i]);
			}
		/*	int i;
			cout << "\nNhap i: ";
			cin >> i;
			themNodeKhongDeQuy1(root, a[i]);*/
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
			kQ = xoaNodeKhongDeQuy(root, x);
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

void themNodeKhongDeQuy(Node *p, int x)
{
	Node *q = p;
	if (q == NULL)
	{
		q = new Node;
		q->infor = x;
		q->left = NULL;
		q->right = NULL;
	}
	else
	{
		while(q != NULL)
		{
			if (q->infor > x)
			{
				if (q->left == NULL)
				{
					q->infor = x;
					q->left = NULL;
					q->right = NULL;
					return;
				}
				else
					q = q->left;
			}
			else
			{
				if (q->right == NULL)
				{
					q->infor = x;
					q->left = NULL;
					q->right = NULL;
					return;
				}
				else
					q = q->right;
			}
		}
	}
}

void themNodeKhongDeQuy1(Node *&p, int x)
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
		while (p != NULL)
		{
			if (p->infor > x)
				p = p->left;
			else if (p->infor < x)
				p = p->right;
			else
				return;
		}
	}
}

void themNodeKhongDeQuy2(Node *p, int x)
{
	Node *q = p;
	Node *g = NULL; // Node theo sau

	while (q != NULL)
	{
		g = q;
		if (x > q->infor)
			q = q->right;
		else
			q = q->left;
	}

	if (g == NULL)
	{
		g = new Node;
		g->infor = x;
		g->left = NULL;
		g->right = NULL;
	}

	else if (x < g->infor)
	{
		g = g ->left;
		g = new Node;
		g->infor = x;
		g->left = NULL;
		g->right = NULL;
	}
	else
	{
		g = g ->right;
		g = new Node;
		g->infor = x;
		g->left = NULL;
		g->right = NULL;
	}
}

void themNodeCu(Node *&p, int x)
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
			return themNodeCu(p->left, x);
		else
			return themNodeCu(p->right, x);
	}
}

void duyetLNR(Node *p)
{
	khoiTaoStack();
	Node *q = p;
	while (q != NULL || !isEmptyStack())
	{
		while(q != NULL)
		{
			pushStack(q->infor);
			q = q->left;
		}

		int x;
		popStack(x);
		cout << x << " ";
		q = timKiem(p, x);
		//if (q != NULL)
			q = q->right;
	}
}

void duyetNLR(Node *p)
{
	khoiTaoStack();
	Node *q = p;

	while (q != NULL || !isEmptyStack())
	{
		int x;
		while(p != NULL)
		{
			pushStack(q->infor);
			popStack(x);
			cout << x << " ";
			q = q->left;
		}

		q = timKiem(p, x);
		q = q->right;
	}
}

void duyetLRN(Node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->infor << " ";
	}
}

Node *timKiem(Node *p, int x)
{
	if (p != NULL)
	{
		if (x == p->infor)
			return p;
		else 
			if (x > p->infor)
				return timKiem(p->right, x);
			else
				return timKiem(p->left, x);
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

int xoaNodeKhongDeQuy(Node *&T, int x)
{
    Node* p = T;
    Node* q = NULL; //Node theo sau

	while (p != NULL && p->infor != x) 
	{
        q = p;
        if (x < p->infor)
            p = p->left;
        else
            p = p->right;
    }
 
    if (p == NULL) 
	{
        return 0;
    }
 
    if (p->left == NULL || p->right == NULL) //Node 1 con
	{
        Node* p1;
 
        if (p->left == NULL)
            p1 = p->right;
        else
            p1 = p->left;

        if (q == NULL)
            return 0;
 
        if (p == q->left)
            q->left = p1;
        else
            q->right = p1;
 
        delete p;
		return 1;
    }
    else //Node 2 con
	{
        Node* g = NULL;
        Node* temp;
 
		//searchStandFor khong de quy
        temp = p->right; //qua nhanh phai
        while (temp->left != NULL) //tim Node trai nhat ben nhanh phai
		{
            g = temp;
            temp = temp->left;
        }

        if (g != NULL)
            g->left = temp->right;
        else
            p->right = temp->right;
 
		p->infor = temp->infor;
        delete temp;
		return 1;
    }
    return 0;
}

// ==================== STACK ====================

void khoiTaoStack()
{
	sp = NULL;
}

void pushStack(int x)
{
	NodeSQ *p = new NodeSQ;
	p->infor = x;
	p->link = sp;
	sp = p;
}

int popStack(int &x)
{
	if (sp != NULL)
	{
		NodeSQ *p = sp;
		x = sp->infor;	
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

int isEmptyStack()
{
	if (sp == NULL)
		return 1;
	return 0;
}

// ==================== QUEUE ====================

void khoiTaoQueue()
{
	front = NULL;
	rear = NULL;
}

void pushQueue(int x)
{
	NodeSQ *p = new NodeSQ;
	p->infor = x;
	p->link = NULL;

	if (rear == NULL)
		front = p;
	else
		rear->link = p;

	rear = p;
}

int popQueue(int &x)
{
	if (front != NULL)
	{
		NodeSQ *p = front;
		x = p->infor;
		front = front->link;

		if (front == NULL)
			rear = NULL;

		delete p;
		return 1;
	}
	return 0;
}

int isEmptyQueue()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}