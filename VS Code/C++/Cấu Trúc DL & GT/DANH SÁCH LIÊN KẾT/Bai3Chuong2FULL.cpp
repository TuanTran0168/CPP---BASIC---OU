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
void ham_Insert_First(List &l, Node *p);
void ham_Insert_Last(List &l, Node *p);
void ham_InPut(List &l);
void ham_OutPut(List l);
Node *ham_Search(List l, int x);

void ham_Delete_First(List &l);
void ham_Delete_Last(List &l);
void ham_DeleteNode(List &l, int &x);
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
            ham_InPut(l);
        }
        else if (choice == 2)
        {
            ham_OutPut(l);
        }
        else if (choice == 3)
        {
            int x;
            cout << "\nNhap gia tri can tim: ";
            cin >> x;

            if (ham_Search(l, x))
                cout << "\nCo ton tai trong danh sach";
            else
                cout << "\nKhong ton tai trong danh sach";
        }
        else if (choice == 4)
        {
            int x;
            cout << "\nNhap gia tri Node can them: ";
            cin >> x;
            Node *p = ham_CreateNode(x);

            ham_Insert_First(l, p);
        }
        else if (choice == 5)
        {
            ham_Delete_First(l);
        }
        else if (choice == 6)
        {
            int x;
            cout << "\nNhap gia tri Node can xoa: ";
            cin >> x;
            Node *p = ham_CreateNode(x);

            ham_Insert_Last(l, p);
        }
        else if (choice == 7)
        {
            ham_Delete_Last(l);
        }
        else if (choice == 8)
        {
            int x;
            ham_DeleteNode(l, x);
        }
        else if (choice == 9)
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
}

Node *ham_CreateNode(int x) //Node số nguyên
{
    Node *p = new Node; //Cấp phát Node p
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !!!";
        return NULL;
    }
    p->Data = x;
    p->Link = NULL; //Node mới chưa có liên kết nào nên trỏ đến NULL

    return p; //Trả về Node p đó có chứa x trong Data
}

void ham_Insert_First(List &l, Node *p)
{
    if (l.pHead == NULL) //Danh sách rỗng không có phần tử nào
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->Link = l.pHead;
        l.pHead = p;
    }
}

void ham_Insert_Last(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->Link = p;
        l.pTail = p;
    }
}

void ham_InPut(List &l)
{
    int n;
    cout << "\nNhap so luong Node: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;

        //ham_Insert_First(l, ham_CreateNode(x));
        ham_Insert_Last(l, ham_CreateNode(x));
    }
}

void ham_OutPut(List l)
{
    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        cout << k->Data << " ";
    }
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
    if (l.pHead == NULL) //Danh sách rỗng thì khỏi xóa
    {
        return;
    }
    else
    {
        Node *p = l.pHead;
        l.pHead = l.pHead->Link; // Cập nhật Node đầu (Node l.pHead) là Node kế tiếp
        delete p;
    }
}

void ham_Delete_Last(List &l)
{
    if (l.pHead->Link == NULL) //Trường hợp danh sách có một phần tử thì xóa đầu
    {
        ham_Delete_First(l);
        return;
    }

    if (l.pHead == NULL) //Danh sách rỗng
    {
        return;
    }
    else
    {
        for (Node *k = l.pHead; k != NULL; k = k->Link)
        {
            //Lúc này trong vòng lặp đang dừng lại ở (Node k) ở vị trí kế Node cuối (Node l.pTail) nên điều kiện if là (k->Link) tức là Node l.pTail
            if (k->Link == l.pTail)
            {
                delete l.pTail; //Xóa Node cuối
                k->Link = NULL; //Cho Node kế cuối trỏ đến NULL vì Node cuối (Node l.pTail) đã xóa
                l.pTail = k;    //Cập nhật Node cuối thành Node k
                return;
            }
        }
    }
}

void ham_DeleteNode(List &l, int &x)
{
    if (l.pHead == NULL) // Rỗng
    {
        return;
    }

    cout << "\nNhap gia tri Node muon xoa: ";
    cin >> x;

    if (l.pHead->Data == x)
    {
        ham_Delete_First(l);
        return;
    }

    if (l.pTail->Data == x)
    {
        ham_Delete_Last(l);
        return;
    }

    Node *g = new Node;

    for (Node *k = l.pHead; k != NULL; k = k->Link)
    {
        if (k->Data == x)
        {
            g->Link = k->Link;
            delete k;
            return;
        }
        g = k; //Node g là Node trước Node k
    }
}

void ham_MENU(int &choice)
{
    cout << "\n============== MENU CHON LUA ==============\n";
    cout << "\n\t1.Nhap danh sach Node";
    cout << "\n\t2.Xuat danh sach Node";
    cout << "\n\t3.Tim phan tu";
    cout << "\n\t4.Them Node vao dau";
    cout << "\n\t5.Xoa Node dau";
    cout << "\n\t6.Them Node vao cuoi";
    cout << "\n\t7.Xoa Node cuoi";
    cout << "\n\t8.Tim va xoa Node do";
    cout << "\n\t9.Ket thuc\n";

    do
    {
        cout << "\nBan muon lam cau may: ";
        cin >> choice;

    } while (choice < 1 || choice > 9);
}