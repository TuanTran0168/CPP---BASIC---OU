#include <iostream>
using namespace std;


int main()
{
    ham_Init()
    system("pause");
    return 0;
}

void ham_Init(Node *&Root)
{
    Root = NULL;
}

void ham_Insert(Node *&T, int x)
{
    if (T == NULL)
    {
        Node *p = new Node;
        p->Data = x;
        p->Left = NULL;
        p->Right = NULL;
        T = p;
    }
    else
    {
        if (T->Data == x)
            return;
        else
        {
            if (T->Data > x)
                return ham_Insert(T->Left, x);
            else
                return ham_Insert(T->Right, x);
        }
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

void ham_Delete(Node *&T, int Del)
{
    if (T == NULL)
        return;
    else if (T->Data == Del) // Tìm được Node để xóa
    {
        Node *p = Del; // Tạo ra Node thí mạng p nếu nó là Node lá thì xóa luôn

        if (T->Left == NULL) // Node con trái không có thì nhảy qua Node con phải
            T = T->Right;
        else if (T->Right == NULL) // Node con phải không có thì nhảy qua Node con trái
            T = T->Left;
        else // Node có 2 con
        {
            ham_SearchStandFor(p, T->Right);
        }

        delete p; // Xóa Node thí mạng
    }
    else // Không có thì tìm tiếp như bình thường
    {
        if (T->Data < Del)
            ham_Delete(T->Right, Del);
        else if (T->Data > Del)
            ham_Delete(T->Left, Del);
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