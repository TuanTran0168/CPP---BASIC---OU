#include <iostream>
#define MAX 100
using namespace std;
void ham_Init(int a[MAX], int &sp);
int ham_IsFull(int a[MAX], int sp);
int ham_IsEmpty(int a[MAX], int sp);
int ham_Push(int a[MAX], int &sp, int x);
int ham_Pop(int a[MAX], int &sp, int &x);

int main()
{
    int a[MAX];
    int sp, x = 5;

    ham_Init(a, sp);
    ham_Push(a, sp, x);
    cout << ham_IsEmpty(a, sp) << endl;

    int x1;
    ham_Pop(a, sp, x1);

    cout << ham_IsEmpty(a, sp) << endl;
    cout << ham_IsFull(a, sp) << endl;

    cout << x1 << endl;
    system("pause");
    return 0;
}

void ham_Init(int a[MAX], int &sp)
{
    sp = -1;
}

int ham_IsFull(int a[MAX], int sp)
{
    if (sp == MAX - 1)
        return 1;
    return 0;
}

int ham_IsEmpty(int a[MAX], int sp)
{
    if (sp == -1)
        return 1;
    return 0;
}

int ham_Push(int a[MAX], int &sp, int x)
{
    if (sp < MAX - 1) // Nếu còn trống
    {
        a[++sp] = x; //Tăng sp lên trước rồi gán x vào stack a
        return 1;
    }
    return 0;
}

int ham_Pop(int a[MAX], int &sp, int &x)
{
    if (sp != -1) //Nếu không rỗng
    {
        x = a[sp--]; //Gán stack a vào x sau đó giảm sp xuống
        return 1;
    }
    return 0;
}
