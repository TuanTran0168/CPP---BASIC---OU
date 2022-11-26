#include <iostream>
using namespace std;

struct NODE
{
    int Data;
    struct NODE *link;
};
typedef struct NODE Node;

struct LISTQUEUE
{
    Node *pHead;
    Node *pTail;
};
typedef struct LISTQUEUE ListQueue;

void ham_Init(ListQueue &q);
Node *ham_CreateNode(int x);
int ham_IsEmpty(ListQueue q);
void ham_Push(ListQueue &q, Node *p);
void ham_Pop(ListQueue &q, int &x);
void ham_InPut(ListQueue &q);
void ham_OutPut(ListQueue q);
void ham_MENU(int &choice);

int main()
{
    ListQueue q;
    ham_Init(q);
    int choice;

    while (true)
    {
        system("cls");
        ham_MENU(choice);

        if (choice == 1)
        {
            ham_InPut(q);
        }
        else if (choice == 2)
        {
            ham_OutPut(q);
        }
        else if (choice == 3)
        {
            if (ham_IsEmpty(q))
                cout << "\nDanh sach rong";
            else
                cout << "\nDanh sach dang ton tai phan tu";
        }
        else if (choice == 4)
        {
            int x;
            cout << "\nNhap gia tri Node muon them: ";
            cin >> x;
            Node *p = ham_CreateNode(x);

            ham_Push(q, p);
        }
        else if (choice == 5)
        {
            int x;
            ham_Pop(q, x);
            cout << "\nGia tri vua xoa la: " << x;
        }
        else if (choice == 6)
        {
            cout << "\n============== KET THUC CHUONG TRINH ==============\n";
            break;
        }

        system("pause");
    }

    system("pause");
    return 0;
}

void ham_Init(ListQueue &q)
{
    q.pHead = NULL;
    q.pTail = NULL;
}

Node *ham_CreateNode(int x)
{
    Node *p = new Node;

    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !!!";
        return NULL;
    }
    p->Data = x;
    p->link = NULL;

    return p;
}

int ham_IsEmpty(ListQueue q)
{
    if (q.pHead == NULL)
        return 1;
    else
        return 0;
}

void ham_Push(ListQueue &q, Node *p)
{
    if (ham_IsEmpty(q)) //Rỗng
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        //Thêm cuối nếu queue đã có phần tử
        q.pTail->link = p;
        q.pTail = p;
    }
}

void ham_Pop(ListQueue &q, int &x)
{
    if (ham_IsEmpty(q)) //Rỗng
    {
        return;
    }
    else
    {
        //Xóa đầu
        Node *p = q.pHead;
        x = p->Data;
        q.pHead = q.pHead->link;
        delete p;
    }
}

void ham_InPut(ListQueue &q)
{
    int n;
    cout << "\nNhap so luong Node trong queue: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;

        ham_Push(q, ham_CreateNode(x));
    }
}

void ham_OutPut(ListQueue q)
{
    while (ham_IsEmpty(q) == false)
    {
        int x;
        ham_Pop(q, x);
        cout << x << " ";
    }
}

void ham_MENU(int &choice)
{
    cout << "\n============== MENU CHON LUA ==============\n";
    cout << "\n\t1.Nhap danh sach Queue";
    cout << "\n\t2.Xuat danh sach Queue";
    cout << "\n\t3.Kiem tra Queue rong";
    cout << "\n\t4.Them Node vao Queue";
    cout << "\n\t5.Xoa Node trong Queue";
    cout << "\n\t6.Ket thuc\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> choice;

    } while (choice < 1 || choice > 6);
}