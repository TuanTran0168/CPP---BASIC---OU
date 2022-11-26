#include <iostream>
#define MAX 100
using namespace std;
void ham_Init(int a[MAX], int &front, int &rear);
int ham_IsFull(int a[MAX], int &front, int &rear);
int ham_IsEmpty(int a[MAX], int &front, int &rear);
int ham_PushTinhTien(int a[MAX], int &front, int &rear, int x);
int ham_PopTinhTien(int a[MAX], int &front, int &rear, int &x);
int ham_PushVong(int a[MAX], int &front, int &rear, int x);
int ham_PopVong(int a[MAX], int &front, int &rear, int &x);

int main()
{
    int a[MAX];
    int front, rear;
    int x = 7;
    int x1 = 8;

    ham_Init(a, front, rear);
    cout << ham_IsEmpty(a, front, rear) << endl;
    cout << ham_IsFull(a, front, rear) << endl;

    ham_PushTinhTien(a, front, rear, x);
    ham_PushVong(a, front, rear, x1);
    cout << ham_IsEmpty(a, front, rear) << endl;

    int x2, x3;
    ham_PopTinhTien(a, front, rear, x2);
    cout << ham_IsEmpty(a, front, rear) << endl;
    ham_PopTinhTien(a, front, rear, x3);
    cout << ham_IsEmpty(a, front, rear) << endl;

    cout << x2 << endl;
    cout << x3 << endl;

    system("pause");
    return 0;
}

void ham_Init(int a[MAX], int &front, int &rear)
{
    front = -1;
    rear = -1;
}

int ham_IsFull(int a[MAX], int &front, int &rear)
{
    if (front == 0 && rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int ham_IsEmpty(int a[MAX], int &front, int &rear)
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

int ham_PushTinhTien(int a[MAX], int &front, int &rear, int x)
{
    if (ham_IsFull(a, front, rear)) // Đầy
        return 0;
    else
    {
        if (ham_IsEmpty(a, front, rear)) // Rỗng
            front = 0;
        if (rear == MAX - 1) // Tràn thì tịnh tiến
        {
            for (int i = front; i <= rear; i++)
            {
                a[i - front] = a[i]; // Dời ngược về vị trí 0
            }
            rear = rear - front;
            front = 0;
        }

        a[++rear] = x;
        return 1;
    }
}

int ham_PopTinhTien(int a[MAX], int &front, int &rear, int &x)
{
    if (ham_IsEmpty(a, front, rear)) // Rỗng
        return 0;
    else
    {
        x = a[front++];

        if (front > rear) // Có 1 phần tử thì front = rear mà xóa xong thì front++ nên hàng đợi rỗng
        {
            front = -1;
            rear = -1;
        }
        return 1;
    }
}

int ham_PushVong(int a[MAX], int &front, int &rear, int x)
{
    if (ham_IsFull(a, front, rear) || rear - front == -1 /*Thêm vòng tới khi rear đụng sát front là thỏa cái này*/) // Đầy
        return 0;
    else
    {
        if (ham_IsEmpty(a, front, rear)) // Rỗng
            front = 0;

        if (rear == MAX - 1) // rear ở cuối thì thêm vòng
        {
            rear = -1; // Vòng rear về -1
        }
        a[++rear] = x;
    }
}

int ham_PopVong(int a[MAX], int &front, int &rear, int &x)
{
    if (ham_IsEmpty(a, front, rear))
        return 0;
    else
    {
        x = a[front];

        if (front == rear) // Có 1 phần tử lấy ra rồi thì rỗng
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
            if (front > MAX - 1) // Tràn thì lại vòng về 0
                front = 0;
        }
        return 1;
    }
}