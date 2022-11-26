#include <iostream>
#include <fstream>
#include <string>
const int MAX = 200;
using namespace std;

int A[MAX][MAX];
int n;
char vertex[MAX];

void khoiTao();
void nhapMaTran();
void xuatMaTran();
void docFile();

// ===== STACK =====
const int MAXSQ = 200;
int arrSQ[MAX];
int sp;
void khoiTaoStack();
int pushStack(int x);
int popStack(int &x);
int isEmptyStack();

// ===== QUEUE =====
int front;
int rear;
void khoiTaoQueue();
int pushQueue(int x);
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

// ========== DFS ==========
int dfs[MAX];
int ndfs = 0;
int s;
void duyetDFS(int s);
void xuatDFS();
void timKiemBangDFS(int x, int s);

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
        cout << "5. Duyet do thi theo chieu rong BFS (Danh sach dac)" << endl;
        cout << "6. Duyet do thi theo chieu sau DFS (Danh sach dac)" << endl;
        cout << "7. Tim dinh co gia tri x theo DFS" << endl;
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

			//timKiemBangBFS(x, 0);
			timKiemBangDFS(x, 0);
			
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
	sp = -1;
}

int pushStack(int x)
{
	if (sp < MAXSQ - 1)
	{
		arrSQ[++sp] = x;
		return 1;	
	}
	return 0;
}

int popStack(int &x)
{
	if (sp != -1)
	{
		x = arrSQ[sp--];
		return 1;
	}
	return 0;
}

int isFull()
{
	if(sp == MAXSQ -1)
		return 1;
	return 0;
}

int isEmptyStack()
{
	if (sp == -1)
		return 1;
	return 0;
}

// ==================== QUEUE ====================

void khoiTaoQueue()
{
	front = -1;
	rear = -1;
}

int pushQueue(int x)
{
	//if (rear - front == MAXSQ - 1)	//Full 
	//	return 0;
	//else
	//{
	//	if (isEmptyQueue())
	//		front = 0;
	//	if (rear == MAXSQ - 1)
	//	{
	//		for(int i = front; i <= rear; i++)
	//		{
	//			arrSQ[i - front] = arrSQ[i];
	//		}
	//		rear = MAXSQ - 1 - front;
	//		front = 0;
	//	}

	//	arrSQ[++rear] = x;
	//	return 1;
	//}

	if (rear - front == MAXSQ - 1 || rear - front == -1)
        return 0;
    else
    {
		if (isEmptyQueue())
            front = 0;

        if (rear == MAXSQ - 1)
        {
            rear = -1;
        }
        arrSQ[++rear] = x;
    }
}

int popQueue(int &x)
{
	/*if (front == -1)
		return 0;
	else
	{
		x = arrSQ[front++];
		if (front > rear)
		{
			front = - 1;
			rear = -1; 
		}
		return 1;
	}*/

	if (isEmptyQueue())
        return 0;
    else
    {
		x = arrSQ[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
            if (front > MAX - 1)
                front = 0;
        }
        return 1;
    }
}


int isEmptyQueue()
{
	if (front == -1 || rear == -1)
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

void timKiemBangDFS(int x, int s)
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
		{
			popStack(u);
			if (x == u)
			{
				cout << "Co ton tai " << vertex[x];
				return;
			}
		}
		
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
	cout << "\nKhong ton tai " << x;
}