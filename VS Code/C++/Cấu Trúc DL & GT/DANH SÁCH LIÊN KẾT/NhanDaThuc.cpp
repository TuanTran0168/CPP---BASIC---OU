#include <iostream>
using namespace std;
struct Node
{
    double coff;
    int expo;
    Node *next;
};
void init(Node *&first)
{
    first = NULL;
}
void add_First(double coff, int expo, Node *&first)
{
    Node *p = new Node();
    p->coff = coff;
    p->expo = expo;
    p->next = first;
    first = p;
}

void add_Last(double coff, int expo, Node *&first)
{
    Node *p = first;
    Node *add = new Node();
    add->coff = coff;
    add->expo = expo;
    add->next = NULL;
    if (p == NULL)
    {
        first = add;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = add;
    }
}

void Print_list(Node *first)
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->coff << "x^" << p->expo;
        if (p->next != NULL)
            cout << " + ";
        p = p->next;
    }
}

void Multi(Node *first, Node *first2, Node *&first3)
{
    Node *pol1 = first;
    Node *pol2 = first2;
    Node *pol3 = first3;

    if (pol1 == NULL || pol2 == NULL)
        return;

    int i = 0;

    while (pol1 != NULL)
    {

        while (pol2 != NULL)
        {

            pol3->coff = pol2->coff * pol1->coff;
            pol3->expo = pol2->expo + pol1->expo;

            if (i == 0)
                add_First(pol3->coff, pol3->expo, pol3);
            else
                add_Last(pol3->coff, pol3->expo, pol3);
            pol2 = pol2->next;
            i++;
        }

        pol2 = first2;
        pol1 = pol1->next;
    }
}

Node *Multi_new(Node *daThuc1, Node *daThuc2)
{
    Node *pol1 = daThuc1;
    Node *pol2 = daThuc2;

    Node *ketQua;
    init(ketQua);

    if (pol1 == NULL || pol2 == NULL)
        return NULL;

    while (pol1 != NULL)
    {

        while (pol2 != NULL)
        {
            add_Last(pol1->coff * pol2->coff, pol1->expo + pol2->expo, ketQua);
            pol2 = pol2->next;
        }

        pol1 = pol1->next;
        pol2 = daThuc2;
    }

    return ketQua;
}

int count_List(Node *first)
{
    int count = 0;
    Node *p = first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int main()
{
    Node *first;
    Node *first2;
    Node *first3;
    init(first);
    init(first2);
    init(first3);

    cout << "Da thuc so 1: ";
    add_First(2, 3, first);
    add_Last(3, 2, first);
    add_Last(4, 1, first);
    add_Last(5, 0, first);

    // add_Last(2, 2, first);
    // add_Last(3, 1, first);
    // add_Last(1, 0, first);
    Print_list(first);

    cout << "\nDa thuc so 2: ";
    add_First(4, 4, first2);
    add_Last(5, 3, first2);
    add_Last(8, 2, first2);
    add_Last(5, 1, first2);
    add_Last(7, 0, first2);

    // add_Last(6, 2, first2);
    // add_Last(5, 1, first2);
    // add_Last(2, 0, first2);
    Print_list(first2);

    cout << "\nNhan hai da thuc: ";
    // Multi(first, first2, first3);

    Node *kq = Multi_new(first, first2);
    Print_list(kq);

    cout << "\nSo luong: " << count_List(kq);

    delete first3;
    delete first2;
    delete first;

    return 0;
}