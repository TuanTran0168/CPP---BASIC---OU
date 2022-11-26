#include <iostream>
using namespace std;

struct NODE
{
    int Data;
    struct NODE *Link;
};
typedef struct NODE Node;

struct LIST
{
    Node *pHead;
    Node *pTail;
};
typedef struct LIST List;

void ham_Init(List &l);
Node *ham_CreateNode(int x);
void ham_OutPut(List l);
void ham_OutPut_EvenNum(List l);
Node *ham_Search(List l, int x);

void ham_Insert_First(List &l, Node *p);
void ham_Insert_Last(List &l, Node *p);

void ham_Delete_First(List &l);
void ham_Delete_Last(List &l);
void ham_MENU(int &choice);

int main()
{
    List l;
    int choice;

    while (true)
    {
        system("cls");
        ham_MENU(choice);

        if (choice == 1)
        {
            ham_Init(l);
        }
        else if (choice == 2)
        {
            int x;
            cout << "\nNhap gia tri Node can them: ";
            cin >> x;
            Node *p = ham_CreateNode(x);

            ham_Insert_First(l, p);
        }
        else if (choice == 3)
        {
            int x;
            cout << "\nNhap gia tri Node can them: ";
            cin >> x;
            Node *p = ham_CreateNode(x);

            ham_Insert_Last(l, p);
        }
        else if (choice == 4)
        {
            ham_Delete_First(l);
        }
        else if (choice == 5)
        {
            ham_Delete_Last(l);
        }
        else if (choice == 6)
        {
            ham_OutPut(l);
        }
        else if (choice == 7)
        {
            ham_OutPut_EvenNum(l);
        }
        else if (choice == 8)
        {
            int x;
            cout << "\nNhap gia tri can tim: ";
            cin >> x;

            if (ham_Search(l, x))
                cout << "\nCo ton tai trong danh sach\n";
            else
                cout << "\nKhong ton tai trong danh sach\n";
        }
        else if (choice == 0)
        {
            cout << "\n============== KET THUC CHUONG TRINH ==============\n";
            break;
        }

        system("pause");
    }

    system("pause");
    return 0;
}

void ham_Init(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
    cout << "\nKhoi tao thanh cong!!!\n";
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
    p->Link = NULL;

    return p;
}

void ham_Insert_First(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
        cout << "\nThem thanh cong!!!\n";
    }
    else
    {
        p->Link = l.pHead;
        l.pHead = p;
        cout << "\nThem thanh cong!!!\n";
    }
}

void ham_Insert_Last(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
        cout << "\nThem thanh cong!!!\n";
    }
    else
    {
        l.pTail->Link = p;
        l.pTail = p;
        cout << "\nThem thanh cong!!!\n";
    }
}

void ham_OutPut(List l)
{
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        cout << k->Data << " ";
    }
}

void ham_OutPut_EvenNum(List l)
{
    int count = 0;
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        if (k->Data % 2 == 0)
        {
            cout << k->Data << " ";
            count++;
        }
    }

    if (count == 0)
        cout << "\nKhong co phan tu so chan\n";
}

Node *ham_Search(List l, int x)
{
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        if (k->Data == x)
            return k;
    }

    return NULL;
}

void ham_Delete_First(List &l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    else
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->Link;
        delete p;
        cout << "\nXoa thanh cong!!!\n";
    }
}

void ham_Delete_Last(List &l)
{
    if (l.pHead->Link == NULL)
    {
        ham_Delete_First(l);
        cout << "\nXoa thanh cong!!!\n";
        return;
    }

    if (l.pHead == NULL)
    {
        return;
    }
    else
    {
        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            if (k->Link == l.pTail)
            {
                delete l.pTail;
                k->Link = NULL;
                l.pTail = k;
                cout << "\nXoa thanh cong!!!\n";
                return;
            }
        }
    }
}

void ham_MENU(int &choice)
{
    cout << "\n============== MENU CHON LUA ==============\n";
    cout << "\n\t1.Khoi tao danh sach";
    cout << "\n\t2.Them Node vao dau";
    cout << "\n\t3.Them Node vao cuoi";
    cout << "\n\t4.Xoa Node o dau";
    cout << "\n\t5.Xoa Node o cuoi";
    cout << "\n\t6.Xuat danh sach";
    cout << "\n\t7.Xuat cac Node co gia tri so chan";
    cout << "\n\t8.Tim kiem Node x";
    cout << "\n\t0.Ket thuc\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> choice;

    } while (choice < 0 || choice > 8);
}