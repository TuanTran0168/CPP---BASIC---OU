#include <iostream>
using namespace std;
void ham_ThemDau(int x);
void ham_ThemCuoi(int x);
void ham_NhapDanhSachNode(int &n);
void ham_XuatDanhSachNode();
struct Node *ham_TimKiem(int x);

struct Node
{
    int infor;
    Node *link;
};

Node *first = NULL;

int main()
{
    int n;
    int x;
    ham_NhapDanhSachNode(n);
    ham_XuatDanhSachNode();

    cout << "\nNhap gia tri can tim: ";
    cin >> x;

    if (ham_TimKiem(x) != NULL)
        cout << "\nCo xuat hien phan tu" << x << " trong danh sach";
    else
        cout << "\nKhong xuat hien phan tu " << x << " trong danh sach";

    system("pause");
    return 0;
}

void ham_ThemDau(int x)
{
    Node *p = new Node;
    p->infor = x;
    p->link = first;

    first = p;
}

void ham_ThemCuoi(int x)
{
    Node *p = new Node;
    p->infor = x;
    p->link = NULL;

    if (first == NULL)
        first = p;
    else
    {
        Node *q = first;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = p;
    }
}

void ham_NhapDanhSachNode(int &n)
{
    cout << "\nNhap so luong Node: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "Nhap x[" << i << "]: ";
        cin >> x;
        //ham_ThemDau(x);
        ham_ThemCuoi(x);
    }
}

void ham_XuatDanhSachNode()
{
    for (Node *i = first; i != NULL; i = i->link)
    {
        cout << i->infor << " ";
    }
}

struct Node *ham_TimKiem(int x)
{
    for (Node *i = first; i != NULL; i = i->link)
    {
        if (i->infor == x)
        {
            return i;
        }
    }

    return 0;
}
