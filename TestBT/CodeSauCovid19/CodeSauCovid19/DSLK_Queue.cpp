#include <iostream>
using namespace std;

struct NODE
{
    int Infor;
    struct NODE *Link;
};
typedef struct NODE Node;

void Init(Node *&Front, Node *&Rear);
int IsEmpty(Node *Front);
void Push(Node *&Front, Node *&Rear, int x);
int Pop(Node *&Front, Node *&Rear, int &x);
void Process_List_Queue(Node *Front, Node *Rear);

int main()
{
    Node *Front;
    Node *Rear;
    int choose;
    bool CheckInit = false;

    do
    {
        system("cls");
        cout << "\n\t====== MENU ======\n";
        cout << "\n1. Khoi tao List Queue"
             << "\n2. Xuat List Queue"
             << "\n3. Push / Them 1 phan tu vao List Queue"
             << "\n4. Pop / Lay 1 phan tu ra khoi List Queue"
             << "\n5. Kiem tra List Queue rong";
        cout << "\n\nMoi ban nhap: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init(Front, Rear);
            CheckInit = true;
            cout << "\nKhoi tao thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                cout << "\nList Queue cua ban (xem tam thoi, no bi nguoc): " << endl;
                Process_List_Queue(Front, Rear);
            }
            else
                cout << "\nVui long khoi tao List Queue!!!";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri de them vao List Queue: ";
                cin >> x;
                Push(Front, Rear, x);
                cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao List Queue!!!";
            break;
        case 4:
            if (CheckInit)
            {
                int x;
                int KQ = Pop(Front, Rear, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nPhan tu vua duoc lay ra khoi List Queue la: " << x;
            }
            else
                cout << "\nVui long khoi tao List Queue!!!";
            break;
        case 5:
            if (CheckInit)
            {
                int KQ = IsEmpty(Front);
                if (KQ == 0)
                    cout << "\nQueue dang ton tai phan tu!!!";
                else if (KQ == 1)
                    cout << "\nQueue dang rong!!!";
            }
            else
                cout << "\nVui long khoi tao List Queue!!!";
            break;
        default:
            cout << "\n====== EXIT ======";
        }

        cout << endl;
        system("pause");
    } while (choose >= 1 && choose <= 5);

    system("pause");
    return 0;
}

void Init(Node *&Front, Node *&Rear)
{
    Front = NULL;
    Rear = NULL;
}
int IsEmpty(Node *Front)
{
    if (Front == NULL)
        return 1;
    return 0;
}
void Push(Node *&Front, Node *&Rear, int x)
{
    Node *p = new Node;
    p->Infor = x;
    p->Link = NULL;

    if (IsEmpty(Front))
        Front = p;
    else
        Rear->Link = p;

    Rear = p;
}
int Pop(Node *&Front, Node *&Rear, int &x)
{
    if (!IsEmpty(Front))
    {
        Node *p = Front;
        x = Front->Infor;
        Front = Front->Link;

        if (Front == NULL)
            Rear = NULL;

        delete p;
        return 1;
    }
    return 0;
}
void Process_List_Queue(Node *Front, Node *Rear)
{
    // No se bi nguoc lai :(( Xem tam
    Node *p = Front;
    while (p != NULL)
    {
        cout << p->Infor << endl;
        p = p->Link;
    }
}