#include <iostream>
using namespace std;
struct NODE
{
    int Infor;
    struct NODE *Left;
    struct NODE *Right;
};
typedef struct NODE Node;

void Init(Node *&Root);
Node *Search(Node *p, int x);
Node *Search_Recursion(Node *p, int x);
void Insert_Recursion(Node *&p, int x);
int Delete_Recursion(Node *&p, int x);
void Search_Stand_For(Node *&p, Node *&q);
void Process_Left_Node_Right(Node *T);

int main()
{
    Node *Root;
    int choose;
    bool CheckInit = false;
    const int n = 9;
    int a[n] = {5, 8, 6, 9, 12, 15, 30, 18, 11};
    do
    {
        system("cls");
        cout << "\n\n\t==== MENU ===\n";
        cout << "\n1. Khoi tao Cay Nhi Phan Tim Kiem"
             << "\n2. Duyet Left Node Right"
             << "\n3. Tim kiem 1 Node"
             << "\n4. Tim kiem 1 Node (khong dung de quy)"
             << "\n5. Them 1 Node"
             << "\n6. Xoa 1 Node";

        cout << "\n\nMoi ban chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init(Root);
            CheckInit = true;
            cout << "\nKhoi tao thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                cout << "\nDuyet cay nhi phan theo Left Node Right: " << endl;
                Process_Left_Node_Right(Root);
            }
            else
                cout << "\nVui long khoi tao Cay Nhi Phan Tim Kiem";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri can tim: ";
                cin >> x;

                if (Search_Recursion(Root, x) == NULL)
                    cout << x << " khong ton tai trong cay!!!";
                else
                    cout << x << " ton tai trong cay!!!";
            }
            else
                cout << "\nVui long khoi tao Cay Nhi Phan Tim Kiem";
            break;
        case 4:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri can tim (khong dung de quy): ";
                cin >> x;

                if (Search(Root, x) == NULL)
                    cout << x << " khong ton tai trong cay!!!";
                else
                    cout << x << " ton tai trong cay!!!";
            }
            else
                cout << "\nVui long khoi tao Cay Nhi Phan Tim Kiem";
            break;
        case 5:
            if (CheckInit)
            {
                // int x;
                // cout << "\nNhap gia tri Node can them: ";
                // cin >> x;
                // Insert_Recursion(Root, x);
                // cout << "\nThuc hien xong!!!";

                for (int i = 0; i < n; i++)
                {
                    Insert_Recursion(Root, a[i]);
                }
            }
            else
                cout << "\nVui long khoi tao Cay Nhi Phan Tim Kiem";
            break;
        case 6:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri can xoa: ";
                cin >> x;

                int KQ = Delete_Recursion(Root, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao Cay Nhi Phan Tim Kiem";
            break;
        default:
            cout << "\n\t====== EXIT ======";
        }

        cout << endl;
        system("pause");
    } while (choose >= 1 && choose <= 6);

    system("pause");
    return 0;
}

void Init(Node *&Root)
{
    Root = NULL;
}
Node *Search(Node *p, int x)
{
    while (p != NULL)
    {
        if (p->Infor == x)
            return p;
        else
        {
            if (x > p->Infor)
                p = p->Right;
            else
                p = p->Left;
        }
    }
    return NULL;
}
Node *Search_Recursion(Node *p, int x)
{
    while (p != NULL)
    {
        if (p->Infor == x)
            return p;
        else
        {
            if (x > p->Infor)
                Search_Recursion(p->Right, x);
            else
                Search_Recursion(p->Right, x);
        }
    }
    return NULL;
}
void Insert_Recursion(Node *&p, int x)
{
    if (p == NULL)
    {
        p = new Node;
        p->Infor = x;
        p->Left = NULL;
        p->Right = NULL;
    }
    else
    {
        if (p->Infor == x)
            return;
        else
        {
            if (x > p->Infor)
                Insert_Recursion(p->Right, x);
            else
                Insert_Recursion(p->Left, x);
        }
    }
}
int Delete_Recursion(Node *&T, int x)
{
    if (T != NULL)
    {
        if (T->Infor == x)
        {
            Node *p = T;
            if (T->Left == NULL)
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            else
                Search_Stand_For(p, T->Right);

            delete p;
            return 1;
        }
    }
    return 0;
}
void Search_Stand_For(Node *&p, Node *&q)
{
    if (q->Left == NULL)
    {
        p->Infor = q->Infor;
        p = q;
        q = q->Right;
    }
    else
        Search_Stand_For(p, q->Left);
}
void Process_Left_Node_Right(Node *T)
{
    if (T != NULL)
    {
        Process_Left_Node_Right(T->Left);
        cout << T->Infor << " ";
        Process_Left_Node_Right(T->Right);
    }
}