#include <iostream>
using namespace std;

struct NODE
{
    int Infor;
    struct NODE *Link;
};
typedef struct NODE Node;

void Init(Node *&First);
void Process_List(Node *First);
void Insert_First(Node *&First, int x);
void Insert_Last(Node *&First, int x);
Node *Search(Node *First, int x);
int Insert_AfterQ(Node *&First, int x, int y);
int Insert_BeforeQ(Node *&First, int x, int y);
int Length_List(Node *First);
bool Prime_Num(Node *First);
int Prime_Num_In_List(Node *First);
int Delete_First(Node *&First);
int Delete_Last(Node *&First);
int Delete_AfterQ(Node *&First, int x);
int Delete_BeforeQ(Node *&First, int x);
int Insert_Node(Node *&First, int x, int pos);
int Delete_Node(Node *&First, int pos);
void Delete_All(Node *&First);

int main()
{
    Node *First; // Khai bao bien First cuc bo
    int choose;
    bool CheckInit = false;
    do
    {
        system("cls");
        cout << "\n\n\t==== MENU ===\n";
        cout << "\n1. Khoi tao"
             << "\n2. Duyet danh sach"
             << "\n3. Tim kiem"
             << "\n4. Them dau"
             << "\n5. Them cuoi"
             << "\n6. Them 1 Node dang sau 1 Node bat ki"
             << "\n7. Them 1 Node truoc 1 Node bat ki"
             << "\n8. Dem danh sach co bao nhieu Node"
             << "\n9. Dem danh sach co bao nhieu Node co gia tri la so nguyen to"
             << "\n10. Xoa dau"
             << "\n11. Xoa cuoi"
             << "\n12. Xoa 1 Node dang sau 1 Node bat ki"
             << "\n13. Xoa 1 Node dang truoc 1 Node bat ki"
             << "\n14. Them 1 Node vao vi tri bat ki"
             << "\n15. Xoa 1 Node o vi tri bat ki"
             << "\n16. Xoa toan bo danh sach lien ket";

        cout << "\n\nMoi ban chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init(First);
            CheckInit = true;
            cout << "\nThuc hien thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                Process_List(First);
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri can tim ";
                cin >> x;

                if (Search(First, x) != NULL)
                    cout << x << " co ton tai trong danh sach" << endl;
                else
                    cout << x << " khong ton tai trong danh sach" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 4:
            if (CheckInit)
            {
                if (CheckInit)
                {
                    int x;
                    cout << "\nNhap gia tri x them vao dau: ";
                    cin >> x;
                    Insert_First(First, x);
                    cout << "\nThuc hien thanh cong!!!";
                }
                else
                    cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            }
            break;
        case 5:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri x them vao cuoi: ";
                cin >> x;
                Insert_Last(First, x);
                cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 6:
            if (CheckInit)
            {
                int x, y;
                cout << "\nNhap gia tri can them: ";
                cin >> x;
                cout << "\nNhap gia tri de tim va them vao phia sau: ";
                cin >> y;
                int KQ = Insert_AfterQ(First, x, y);

                if (KQ == 1)
                    cout << "\nThem thanh cong";
                else if (KQ == 0)
                    cout << "\nThem khong thanh cong";
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 7:
            if (CheckInit)
            {
                int x, y;
                cout << "\nNhap gia tri can them: ";
                cin >> x;
                cout << "\nNhap gia tri de tim va them vao phia truoc: ";
                cin >> y;
                int KQ = Insert_BeforeQ(First, x, y);

                if (KQ == 1)
                    cout << "\nThem thanh cong";
                else if (KQ == 0)
                    cout << "\nThem khong thanh cong";
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 8:
            if (CheckInit)
            {
                cout << "\nDanh sach cua ban co: " << Length_List(First) << " Node" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 9:
            if (CheckInit)
            {
                cout << "\nDanh sach cua ban co: " << Prime_Num_In_List(First) << " Node co gia tri la so nguyen to" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 10:
            if (CheckInit)
            {
                int KQ = Delete_First(First);
                if (KQ == 0)
                    cout << "\nXoa khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nXoa thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 11:
            if (CheckInit)
            {
                int KQ = Delete_Last(First);
                if (KQ == 0)
                    cout << "\nXoa khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nXoa thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 12:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap Node de xoa Node phia sau: ";
                cin >> x;
                int KQ = Delete_AfterQ(First, x);
                if (KQ == 0)
                    cout << "\nXoa khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nXoa thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 13:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap Node de xoa Node phia sau: ";
                cin >> x;
                int KQ = Delete_BeforeQ(First, x);
                if (KQ == 0)
                    cout << "\nXoa khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nXoa thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;

        case 14:
            if (CheckInit)
            {
                int x;
                int pos;
                cout << "\nDanh sach dang co " << Length_List(First) << " Node";
                cout << "\nNhap vi tri ban muon them (Bat dau tu 1): ";
                cin >> pos;
                cout << "\nNhap gia tri Node can them: ";
                cin >> x;

                int KQ = Insert_Node(First, x, pos);
                if (KQ == 0)
                    cout << "\nThem khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nThem thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 15:
            if (CheckInit)
            {
                int pos;
                cout << "\nDanh sach dang co " << Length_List(First) << " Node";
                cout << "\nNhap vi tri ban muon xoa (Bat dau tu 1): ";
                cin >> pos;

                int KQ = Delete_Node(First, pos);
                if (KQ == 0)
                    cout << "\nXoa khong thanh cong!!!" << endl;
                else if (KQ == 1)
                    cout << "\nXoa thanh cong!!!" << endl;
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        case 16:
            if (CheckInit)
            {
                Delete_All(First);
                cout << "\nXoa thanh cong toan bo danh sach!!!";
            }
            else
                cout << "\nHay goi ham khoi tao danh sach lien ket!!!";
            break;
        default:
            Delete_All(First);
            cout << "\n======= EXIT =======" << endl;
        }

        system("pause");

    } while (choose >= 1 && choose <= 16);
    system("pause");
    return 0;
}

void Init(Node *&First)
{
    First = NULL;
}
void Process_List(Node *First)
{
    Node *p = First;
    while (p != NULL)
    {
        cout << p->Infor << " ";
        p = p->Link;
    }
}
void Insert_First(Node *&First, int x)
{
    Node *p = new Node;
    p->Infor = x;
    p->Link = First;
    First = p;
}
void Insert_Last(Node *&First, int x)
{
    Node *p = new Node;
    p->Infor = x;
    p->Link = NULL;

    if (First == NULL) // Neu danh sach rong thi se cho no la Node dau luon
        First = p;
    else
    {
        Node *q = First;
        while (q->Link != NULL) // q->Link tuc la Node ke ben Node q (va cung la Node ke cuoi)
        {
            q = q->Link;
        }
        q->Link = p;
    }
}
Node *Search(Node *First, int x)
{
    Node *p = First;
    while (p != NULL && p->Infor != x)
    {
        p = p->Link;
    }

    return p;
}
int Insert_AfterQ(Node *&First, int x, int y)
{
    // x la gia tri can them, y la gia tri can tim
    Node *q = Search(First, y); // Tim Node co infor la y
    if (q != NULL)
    {
        Node *p = new Node;
        p->Infor = x;
        p->Link = q->Link;
        q->Link = p;
        return 1;
    }
    return 0;
}
int Insert_BeforeQ(Node *&First, int x, int y)
{
    Node *q = Search(First, y);
    if (q == First)
    {
        Insert_First(First, x);
    }
    else if (q != NULL)
    {
        Node *temp = First; // Tim Node temp nam truoc Node q
        while (temp != NULL && temp->Link != q)
        {
            temp = temp->Link;
        }
        Node *p = new Node;
        p->Infor = x;
        p->Link = q;
        temp->Link = p;
        return 1;
    }
    return 0;
}
int Length_List(Node *First)
{
    Node *p = First;
    int count = 0;
    while (p != NULL)
    {
        p = p->Link;
        count++;
    }

    return count;
}
bool Prime_Num(int x)
{
    if (x < 2)
        return false;
    else
    {
        if (x == 2)
            return true;
        else
        {
            if (x % 2 == 0)
                return false;
            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                        return false;
                }
            }
        }
    }
    return true;
}
int Prime_Num_In_List(Node *First)
{
    Node *p = First;
    int count = 0;
    while (p != NULL)
    {
        if (Prime_Num(p->Infor) == true)
            count++;
        p = p->Link;
    }

    return count;
}
int Delete_First(Node *&First)
{
    Node *p = First;
    if (First != NULL) // Neu danh sach co it nhat 1 Node
    {
        First = First->Link;
        delete p;
        return 1;
    }
    return 0;
}
int Delete_Last(Node *&First)
{
    if (First != NULL) // Neu danh sach co it nhat 1 Node
    {
        Node *p = First;
        Node *q = NULL; // Node ke cuoi

        while (p->Link != NULL)
        {
            q = p;
            p = p->Link;
        }

        if (p == First) // Neu vong lap tren ko chay thi Node p van nam o Node First
            First = First->Link;
        else
            q->Link = NULL;

        delete p;
        return 1;
    }
    return 0;
}
int Delete_AfterQ(Node *&First, int x)
{
    if (First != NULL) // Danh sach co it nhat 1 Node moi xoa duoc
    {
        Node *q = Search(First, x);
        if (q == NULL) // Khong tim duoc Node q thi khong xoa duoc
            return 0;
        if (q->Link == NULL) // Tim duoc Node q nhung Node phia sau lai khong co thi khong xoa duoc
            return 0;
        if (q != NULL)
        {
            Node *p = new Node;
            p = q->Link;
            q->Link = p->Link;
            delete p;
            return 1;
        }
    }
    return 0;
}
int Delete_BeforeQ(Node *&First, int x)
{
    if (First != NULL) // Danh sach co it nhat 1 Node moi xoa duoc
    {
        Node *q = Search(First, x);
        if (q == First) // Node q la Node dau tien thi khong xoa duoc
            return 0;
        else
        {
            Node *p = First;
            Node *g = NULL; // Node g la Node nam truoc Node p (g -> p -> q)
            while (p->Link != q)
            {
                g = p;
                p = p->Link;
            }

            if (g != NULL) // Neu Node g da chay vao trong vong lap
                g->Link = q;
            else
                First = q; // Neu Node g van la NULL thi Node p van la Node First

            delete p;
            return 1;
        }
    }
    return 0;
}
int Insert_Node(Node *&First, int x, int pos)
{
    if (First == NULL || pos == 1)
    {
        Insert_First(First, x);
        return 1;
    }
    else if (pos == Length_List(First) + 1)
    {
        Insert_Last(First, x);
        return 1;
    }
    else if (pos > 1 && pos <= Length_List(First))
    {
        Node *temp = First;
        Node *q = NULL;
        int count = 1;

        while (temp->Link != NULL && count != pos) // Bat dau tu 1
        {
            count++;
            q = temp;
            temp = temp->Link;
        }

        Node *p = new Node;
        p->Infor = x;
        p->Link = temp;
        q->Link = p;
        return 1;
    }
    return 0;
}
int Delete_Node(Node *&First, int pos)
{
    if (First != NULL)
    {
        if (pos == 1)
        {
            Delete_First(First);
            return 1;
        }
        else if (pos == Length_List(First))
        {
            Delete_Last(First);
            return 1;
        }
        else if (pos > 1 && pos < Length_List(First))
        {
            Node *temp = First;
            Node *q = NULL;
            int count = 1;
            while (temp->Link != NULL && count != pos)
            {
                count++;
                q = temp;
                temp = temp->Link;
            }
            q->Link = temp->Link;
            delete temp;
            return 1;
        }
    }
    return 0;
}
void Delete_All(Node *&First)
{
    while (First != NULL)
    {
        Node *p = First;
        First = First->Link;
        delete p;
    }
}