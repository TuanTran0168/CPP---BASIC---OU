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

// ========== CAY BAO TRUM ==========
// Khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE;

//Khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT;

// ========== PRIM ==========

int tonTai(int d, int D[], int nD);
void xoaViTri(int viTri);
void xoaCanhE(int u, int v);
void prim(int s);
void xuatCayBaotrum();

// ========== KRUSKAL ==========
void taoE();
void sapXepE();
void kruskal();

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
        cout << "5. Tim cay bao trum toi tieu bang Prim" << endl;
        cout << "6. Tim cay bao trum toi tieu bang Kruskal" << endl;
        cout << "7. Thoat" << endl;
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
			cout << "\nNhap dinh can duyet: ";
			cin >> s;
			prim(s);
			xuatCayBaotrum();
            break;

        case 6:
			taoE();
			sapXepE();
			kruskal();
			xuatCayBaotrum();
            break;

        case 7:
            cout << "Da thoat!" << endl;
            break;

        default:
            break;
        }

        cout << endl;
        system("pause");
    } while (choice != 7);

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
    docFile.open("E:\\TXT\\cayBaoTrum.txt", ios::in);
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

void duyetBFS(int v)
{
	int p, w;
	pushQueue(v);
	C[v] = 0;
	while (isEmptyQueue() == false)
	{
		popQueue(p);
		bfs[nbfs] = p;
		nbfs++;
		
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

// ==================== CAY BAO TRUM ====================

// ============== PRIM ==============
int tonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
	{
		if (D[i] == d)
			return 1;
	}
	return 0;
}

void xoaViTri(int viTri)
{
	for (int i = viTri; i < nE; i++)
	{
		E1[i] = E1[i + 1];
		E2[i] = E2[i + 1];
		wE[i] = wE[i + 1];
	}
	nE--;
}

void xoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
	{
		if (E1[i] == u && E2[i] == v)
		{
			xoaViTri(i);
			break;
		}
	}
}

void prim(int s)
{
	int u = s;
	int i;
	int min;
	int d1, d2;
	while(nT < n - 1)
	{
		//Vong lap duyet ma tran ke
		for (int v = 0; v < n; v++)
		{
			// Ke la khac 0, ke la bang 0
			if (A[u][v] != 0)
			{
				if (tonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = A[u][v];
					nE++;
				}
			}
		}

		for (i = 0; i < nE; i++)
		{
			if (tonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		}

		for (; i < nE; i++)
		{
			if (tonTai(E2[i], T2, nT) == 0)
			{
				if (wE[i] < min)
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
			}
		}

		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = A[d1][d2];
		nT++;
		A[d1][d2] = 0;//Danh dau la da duyet xong roi
		A[d2][d1] = 0;
		u = d2;

		xoaCanhE(d1, d2);
	}
}

void xuatCayBaotrum()
{
	int tong = 0;
	
	for (int i = 0; i < nT; i++)
	{
		cout << "(" << vertex[T1[i]] << ", " << vertex[T2[i]] << ") = " << wT[i] << endl;
		tong += wT[i];
	}

	cout << "\nTong trong so: " << tong << endl;
}

// ============== KRUSKAL ==============

void taoE()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = A[i][j];
				A[i][j] = 0;
				A[j][i] = 0;
				nE++;
			}
		}
	}
}

void sapXepE()
{
	for (int i = 0; i < nE - 1; i++)
	{
		for (int j = i + 1; j < nE; j++)
		{
			if (wE[i] > wE[j])
			{
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
				swap(wE[i], wE[j]);
			}
		}
	}
}

void kruskal() // BUG THIẾU ĐỈNH
{
	for (int i = 0; i < nE; i++)
	{
		if (tonTai(E1[i], T1, nT) == 1 && tonTai(E2[i], T2, nT) == 1)
		{
			continue;
		}

		if (tonTai(E1[i], T2, nT) == 1 && tonTai(E2[i], T1, nT) == 1)
		{
			continue;
		}

		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;

		if (nT == n - 1)
			break;
	}
}