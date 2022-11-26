#include <iostream>
using namespace std;

struct NODE
{
    int Data;
    struct NODE *Left;
    struct NODE *Right;
};
typedef struct NODE Node;

void ham_Init(Node *&Root);
void ham_Insert(Node *&T, int x);
void ham_Delete(Node *&T, int Del);
void ham_OutPut_NLR(Node *T);
void ham_OutPut_LNR(Node *T);
void ham_OutPut_LRN(Node *T);
 Node *ham_Search(Node *T, int x);
void ham_MENU(int &choice);

int main()
{
    Node *Root;
    ham_Init(Root);

    int choice;
    while (true)
    {
        system("cls");
        ham_MENU(choice);

        if (choice == 1)
        {
            int x;
            cout << "\nNhap gia tri cho Node: ";
            cin >> x;

            ham_Insert(Root, x);
        }
        else if (choice == 2)
        {
            int x;
            cout << "\nNhap gia tri can tim: ";
            cin >> x;

             if (ham_Search(Root, x))
                 cout << "\nCo phan tu " << x << " trong cay";
             else
                 cout << "\nKhong co phan tu " << x << " trong cay";
        }
        else if (choice == 3)
        {
        }
        else if (choice == 4)
        {
            ham_OutPut_NLR(Root);
        }
        else if (choice == 5)
        {
            ham_OutPut_NLR(Root);
            /*ham_OutPut_LRN(Root);*/
            ham_OutPut_LNR(Root);
    
        }
        else if (choice == 6)
        {
        }

        system("pause");
    }

    system("pause");
    return 0;
}

void ham_Init(Node *&Root)
{
    Root = NULL;
}

void ham_Insert(Node *&T, int x) // Thêm x vào cây nhị phân
{
    if (T == NULL) // Nếu cây rỗng thì thêm vào Node đầu là Node Root của cây
    {
        Node *p = new Node;
        p->Data = x;
        p->Left = NULL;
        p->Right = NULL;
        T = p; // Cập nhật Node T (Node tại vị trí đang xét) là p
    }
    else
    {
        if (T->Data == x)
            return;
        else
        {
            if (T->Data > x)
                return ham_Insert(T->Left, x); // x bé hơn giá trị của Node ở vị trí đang xét nên rẽ trái
            else
                return ham_Insert(T->Right, x); // x lớn hơn giá trị của Node ở vị trí đang xét nên rẽ phải
        }
    }
}

void ham_OutPut_NLR(Node *T)
{
    if (T != NULL)
    {
        cout << T->Data << " ";
        ham_OutPut_NLR(T->Left);
        ham_OutPut_NLR(T->Right);
    }
}

void ham_OutPut_LNR(Node *T)
{
    if (T != NULL)
    {
        ham_OutPut_LNR(T->Left);
        cout << T->Data << " ";
        ham_OutPut_LNR(T->Right);
    }
}

void ham_Output_LRN(Node *T)
{
    if (T != NULL)
    {
        ham_Output_LRN(T->Left);
        ham_Output_LRN(T->Right);
        cout << T->Data << " ";
    }
}

void ham_SearchStandFor(Node *&p, Node *&q)
{
    if (q->Left == NULL)
    {
        p->Data = q->Data;
        p = q;
        q = q->Right;
    }
    else
    {
        ham_SearchStandFor(p, q->Left);
    }
}

// void ham_Delete(Node *&T, int Del)
// {
//     if (T == NULL)
//         return;
//     else if (T->Data == Del) // Tìm được Node để xóa
//     {
//         Node *p = Del; // Tạo ra Node thí mạng p nếu nó là Node lá thì xóa luôn

//         if (T->Left == NULL) // Node con trái không có thì nhảy qua Node con phải
//             T = T->Right;
//         else if (T->Right == NULL) // Node con phải không có thì nhảy qua Node con trái
//             T = T->Left;
//         else // Node có 2 con

//             ham_SearchStandFor(p, T->Right);

//             delete p; // Xóa Node thí mạng
//     }
//     else // Không có thì tìm tiếp như bình thường
//     {
//         if (T->Data < x)
//             ham_Delete(T->Right, Del);
//         else if (T->Data > x)
//             ham_Delete(T->Left, Del);
//     }
// }

Node *ham_Search(Node *T, int x)
{
    if (T == NULL)
        return NULL;
    else
    {
        if (T->Data == x)
            return T;
        else
        {
            if (T->Data > x)
                ham_Search(T->Left, x);
            else
                ham_Search(T->Right, x);
        }
    }
}

void ham_MENU(int &choice)
{
    cout << "\n\t===== MENU ===\n";
    cout << "\n1. Them mot Node cho cay";
    cout << "\n2. Tim kiem phan tu trong cay";
    cout << "\n3. Xoa mot Node trong cay";
    cout << "\n4. Xuat du lieu NRL cua cay";
    cout << "\n5. Xuat du lieu LNR cua cay";
    cout << "\n6. Xuat du lieu LNR cua cay";
    cout << "\n0. Ket thuc" << endl;

    do
    {
        cout << "\nNhap lua chon: ";
        cin >> choice;

    } while (choice < 0 || choice > 6);
}

