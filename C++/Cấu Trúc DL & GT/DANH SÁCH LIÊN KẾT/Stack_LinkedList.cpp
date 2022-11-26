#include <iostream>
using namespace std;

struct NODE
{
    int Infor;
    struct NODE *Link;
};
typedef struct NODE Node;

Node *sp;

void Init();
int IsEmpty();
void Push(int x);
int Pop(int &x);
void Process_List_Stack();
int DecToBin_List_Stack(Node *&sp, int Dec);

int main()
{
    int choose;
    bool CheckInit = false;
    do
    {
        system("cls");
        cout << "\n\n\t==== MENU ===\n";
        cout << "\n1. Khoi tao Stack"
             << "\n2. Duyet List Stack tu dinh xuong day"
             << "\n3. Push / Them 1 phan tu vao List Stack"
             << "\n4. Pop /  Lay 1 phan tu ra khoi List Stack"
             << "\n5. Kiem tra List Stack Empty / Rong"
             << "\n6. Chuyen tu he thap phan sang nhi phan bang List Stack";

        cout << "\n\nMoi ban chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init();
            CheckInit = true;
            cout << "\nKhoi tao thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                cout << "\nList Stack cua ban: " << endl;
                Process_List_Stack();
            }
            else
                cout << "\nVui long khoi tao List Stack";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap phan tu de them vao List Stack: ";
                cin >> x;
                Push(x);
                cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao List Stack";
            break;
        case 4:
            if (CheckInit)
            {
                int x;
                int KQ = Pop(x);
                if (KQ == 1)
                    cout << "\nPhan tu vua duoc lay ra khoi List Stack la: " << x;
                else if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao List Stack";
            break;
        case 5:
            if (CheckInit)
            {
                int KQ = IsEmpty();
                if (KQ == 1)
                    cout << "\nStack dang rong!!!";
                else if (KQ == 0)
                    cout << "\nStack da co phan tu!!!";
            }
            else
                cout << "\nVui long khoi tao List Stack";
            break;
        case 6:
            if (CheckInit)
            {
                int Dec;
                cout << "\nNhap so thap phan nguyen duong: ";
                cin >> Dec;
                int KQ = DecToBin_List_Stack(sp, Dec);
                if (KQ == INT_MIN)
                    cout << "\nThuc hien khong thanh cong!!!";
                else
                    cout << "\nSo thap phan: " << Dec << " doi ra nhi phan la: " << KQ;
            }
            else
                cout << "\nVui long khoi tao List Stack";
            break;
        default:
            cout << "\t\n======  EXIT ======";
        }

        cout << endl;
        system("pause");

    } while (choose >= 1 && choose <= 6);
    system("pause");
    return 0;
}

void Init()
{
    sp = NULL;
}
int IsEmpty()
{
    if (sp == NULL)
        return 1;
    return 0;
}
void Push(int x)
{
    Node *p = new Node;
    p->Infor = x;
    p->Link = sp;
    sp = p;
}
int Pop(int &x)
{
    if (!IsEmpty())
    {
        Node *p = sp;
        x = sp->Infor;
        sp = sp->Link;
        delete p;
        return 1;
    }
    return 0;
}
void Process_List_Stack()
{
    Node *p = sp;
    while (p != NULL)
    {
        cout << p->Infor << endl;
        p = p->Link;
    }
}
int DecToBin_List_Stack(Node *&sp, int Dec)
{
    Init();
    int Remainder; // Remainder: so du ( Ghi tieng anh cho no sang :))) )
    while (Dec != 0)
    {
        Remainder = Dec % 2;
        Push(Remainder);
        Dec = Dec / 2;
    }

    int Bin = 0;
    while (!IsEmpty()) //Lay cho den khi nao List Stack rong thi thoi
    {
        int Num;
        if (!Pop(Num))
        {
            return INT_MIN;
        }

        Bin = Bin * 10 + Num;
    }
    return Bin;
}