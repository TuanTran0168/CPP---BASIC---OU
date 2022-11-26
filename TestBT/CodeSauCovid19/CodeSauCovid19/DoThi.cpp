#include <iostream>
#include <fstream>
#include <string>
const int MAX = 20;
using namespace std;
struct NODE
{
    int infor;
    struct NODE *link;
};
typedef struct NODE Node;

Node *sp;     // Cua Stack
Node *front; // Cua Queue
Node *rear; // Cua Queue

int A[MAX][MAX];
int n;
char vertex[MAX];

void khoiTao();
void nhapMaTran();
void xuatMaTran();
void docFile();

// ===== STACK =====
void khoiTaoStack();
void pushStack(int x);
int popStack(int &x);
int isEmptyStack();

// ===== QUEUE =====
void khoiTaoQueue();
void pushQueue(int x);
int popQueue(int &x);
int isEmptyQueue();

// ========== BFS ==========
int bfs[MAX];
int nbfs = 0;
int C[MAX]; //Luu dinh chua xet
int v;
int x;
void khoiTaoDinhChuaXet();
void duyetBFS(int v);
void xuatBFS();
void timKiemBangBFS(int x, int v);
//void timKiemBangBFS_BUG(int v);

// ========== DFS ==========
int dfs[MAX];
int ndfs = 0;
int s;
void duyetDFS(int s);
void xuatDFS();

int main()
{
    int choice;

    do
    {
        system("cls");
        cout << " ---------BTH5 , CHUONG 5 , DO THI -------" << endl;
        cout << "1. Khoi tao MA TRAN KE rong" << endl;
        cout << "2. Nhap MA TRAN KE tu file text" << endl;
        cout << "3. Nhap MA TRAN KE " << endl;
        cout << "4. Xuat MA TRAN KE " << endl;
        cout << "5. Duyet do thi theo chieu rong BFS" << endl;
        cout << "6. Duyet do thi theo chieu sau DFS" << endl;
        cout << "7. Tim dinh co gia tri x theo BFS" << endl;
        cout << "8. Thoat" << endl;
        cout << "\nVui long chon so de thuc hien: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            khoiTao();
            cout << "\nKhoi tao thanh cong!!!";
            break;

        case 2:
            docFile();
            break;

        case 3:
            nhapMaTran();
            break;

        case 4:
            xuatMaTran();
            break;

        case 5:
			khoiTaoDinhChuaXet();
			nbfs = 0;
			cout << "\nNhap vi tri dinh de xet: ";
			cin >> v;
			duyetBFS(v);
			cout << "\nBFS: ";
			xuatBFS();
            break;

        case 6:
			khoiTaoDinhChuaXet();
			ndfs = 0;
			cout << "\nNhap vi tri dinh de xet: ";
			cin >> s;
			cout << "\nDFS: ";
			duyetDFS(s);
			xuatDFS();
            break;

        case 7:
			khoiTaoDinhChuaXet();
			cout << "\nNhap dinh can tim: ";
			cin >> x;

			timKiemBangBFS(x, 0);
			//timKiemBangBFS_BUG(0);
            break;

        case 8:
            cout << "Da thoat!" << endl;
            break;

        default:
            break;
        }

        cout << endl;
        system("pause");
    } while (choice != 8);

    system("pause");
    return 0;
}

void khoiTao()
{
    n = 0;
}

void nhapMaTran()
{
    cout << "\nNhap so dinh cua do thi: ";
    cin >> n;
    cout << "\n\tNhap ten dinh \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ten dinh thu " << i << ": ";
        cin >> vertex[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNhap dong thu " << i << ": \n";
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap vao cot thu " << j << ": ";
            cin >> A[i][j];
        }
    }
}

void xuatMaTran()
{
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << vertex[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vertex[i] << " ";
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void docFile()
{
    ifstream docFile;
    docFile.open("E:\\TXT\\maTranKe.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "\nDoc FILE thanh cong";
        while (!docFile.eof())
        {
            while (!docFile.eof())
            {
                docFile >> n;
                for (int i = 0; i < n; i++)
                {
                    docFile >> vertex[i];
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        docFile >> A[i][j];
                    }
                }
            }
            docFile.close();
        }
    }
    else
    {
        cout << "\nKhong mo duoc FILE";
    }
}

// ==================== STACK ====================

void khoiTaoStack()
{
	sp = NULL;
}

void pushStack(int x)
{
	Node *p = new Node;
	p->infor = x;
	p->link = sp;
	sp = p;
}

int popStack(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = sp->infor;	
		sp = sp->link;
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
	Node *p = new Node;
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
		Node *p = front;
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

// ==================== BFS ====================

void khoiTaoDinhChuaXet()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}

void duyetBFS(int v) //v la vi tri cua dinh bat dau (A, B, C,...)
{
	int p, w;
	pushQueue(v);
	C[v] = 0; //Danh dau la duyet roi
	while (isEmptyQueue() == false)
	{
		popQueue(p);
		bfs[nbfs] = p;
		nbfs++;
		//Kiem tra xem con dinh ke hay khong de dua vao hang doi luon
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				pushQueue(w);
				C[w] = 0;
			}
		}
	}
}

void xuatBFS()
{
	for (int i = 0; i < nbfs; i++)
	{
		cout << vertex[bfs[i]] << " ";
	}
}

void timKiemBangBFS(int x, int v)
{
	int p, w;
	pushQueue(v);
	C[v] = 0;
	while (isEmptyQueue() == false)
	{
		popQueue(p);
		if (x == p)
		{
			cout << "Co ton tai " << vertex[x];
			return;
		}
		
		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				pushQueue(w);
				C[w] = 0;
			}
		}
	}
	cout << "\nKhong ton tai " << x;
}

//void timKiemBangBFS_BUG(int v)
//{
//	int p, w;
//	pushQueue(v);
//	C[v] = 0;
//	while (isEmptyQueue() == false)
//	{
//		popQueue(p);
//		if (3 == p)
//		{
//			cout << "Co ton tai " << vertex[3];
//			return;
//		}
//		
//		for (w = 0; w < n; w++)
//		{
//			if (C[w] == 1 && A[p][w] == 1)
//			{
//				pushQueue(w);
//				C[w] = 0;
//			}
//		}
//	}
//	cout << "\nKhong ton tai " << x;
//}

// ==================== DFS ====================
void duyetDFS(int s)
{
	pushStack(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1;
	int u = s;

	while (isEmptyStack() == false)
	{
		if (v == n)
			popStack(u);
		
		for (v = 0; v < n; v++)
		{
			if (C[v] == 1 && A[u][v] == 1)
			{
				pushStack(u);
				pushStack(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

void xuatDFS()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << vertex[dfs[i]] << " ";
	}
}