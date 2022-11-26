#include <iostream>
using namespace std;

struct NODE
{
    int Data;
    struct NODE *link;
};
typedef struct NODE Node;

struct LISTSTACK
{
    Node *Top;
};
typedef struct LISTSTACK ListStack;

void ham_Init(ListStack &s);
Node *ham_CreateNode(int x);
int ham_IsEmpty(ListStack s);
void ham_Push(ListStack &s, Node *p);
void ham_Pop(ListStack &s, int &x);
void ham_InPut(ListStack &s);
void ham_OutPut(ListStack s);
void ham_DecToBin(ListStack &s, int n);
void ham_MENU(int &choice);

int main()
{
    ListStack s;
    ham_Init(s);
    int choice;

    while (true)
    {
        system("cls");
        ham_MENU(choice);

        if (choice == 1)
        {
            ham_InPut(s);
        }
        else if (choice == 2)
        {
            ham_OutPut(s);
        }
        else if (choice == 3)
        {
            if (ham_IsEmpty(s))
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

            ham_Push(s, p);
        }
        else if (choice == 5)
        {
            int x;
            ham_Pop(s, x);
            cout << "\nGia tri vua xoa la: " << x;
        }
        else if (choice == 6)
        {
            int n;
            cout << "\nNhap so he thap phan can doi: ";
            cin >> n;

            ham_DecToBin(s, n);

            cout << "\nSo nhi phan la: ";
            ham_OutPut(s);
        }
        else if (choice == 7)
        {
            cout << "\n============== KET THUC CHUONG TRINH ==============\n";
            break;
        }

        system("pause");
    }

    system("pause");
    return 0;
}

void ham_Init(ListStack &s)
{
    s.Top = NULL;
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

int ham_IsEmpty(ListStack s)
{
    if (s.Top == NULL)
        return 1;
    else
        return 0;
}

void ham_Push(ListStack &s, Node *p)
{
    if (ham_IsEmpty(s)) //Rỗng
    {
        s.Top = p;
    }
    else
    {
        //Thêm đầu nếu stack đã có phần tử
        p->link = s.Top;
        s.Top = p;
    }
}

void ham_Pop(ListStack &s, int &x)
{
    if (ham_IsEmpty(s)) //Rỗng
    {
        return;
    }
    else
    {
        //Xóa đầu
        Node *p = s.Top;
        x = p->Data;
        s.Top = s.Top->link;
        delete p;
    }
}

void ham_InPut(ListStack &s)
{
    int n;
    cout << "\nNhap so luong Node trong stack: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;

        ham_Push(s, ham_CreateNode(x));
    }
}

void ham_OutPut(ListStack s)
{
    while (ham_IsEmpty(s) == false)
    {
        int x;
        ham_Pop(s, x);
        cout << x << " ";
    }
}

void ham_DecToBin(ListStack &s, int n)
{
    while (n != 0)
    {
        int x = n % 2; //Chia cho 2 lấy dư bỏ vào stack
        Node *p = ham_CreateNode(x);
        ham_Push(s, p);
        n = n / 2;
    }
}

void ham_MENU(int &choice)
{
    cout << "\n============== MENU CHON LUA ==============\n";
    cout << "\n\t1.Nhap danh sach Stack";
    cout << "\n\t2.Xuat danh sach Stack";
    cout << "\n\t3.Kiem tra Stack rong";
    cout << "\n\t4.Them Node vao Stack";
    cout << "\n\t5.Xoa Node trong Stack";
    cout << "\n\t6.Chuyen he thap phan sang nhi phan";
    cout << "\n\t7.Ket thuc\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> choice;

    } while (choice < 1 || choice > 7);
}