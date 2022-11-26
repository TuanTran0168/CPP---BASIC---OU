#include <iostream>
using namespace std;
const int MAX = 5;

void Init(int a[], int &Front, int &Rear);
int IsFull(int a[], int Front, int Rear);
int IsEmpty(int a[], int Front, int Rear);
void Process_Queue(int a[], int Front, int Rear);

/*=================== Tinh Tien ======================*/

int Push_TinhTien(int a[], int &Front, int &Rear, int x);
int Pop_TinhTien(int a[], int &Front, int &Rear, int &x);

/*=================== Vong ======================*/

int Push_Vong(int a[], int &Front, int &Rear, int x);
int Pop_Vong(int a[], int &Front, int &Rear, int &x);

int main()
{
    int a[MAX];
    int Front, Rear;
    int choose;
    bool CheckInit = false;

    do
    {

        system("cls");
        cout << "\n\t====== MENU ======\n";
        cout << "\n1. Khoi tao Queue"
             << "\n2. Duyet danh sach tu dinh xuong day"
             << "\n3. Push / Them 1 phan tu vao Queue bang phuong phap Tinh Tien"
             << "\n4. Pop / Lay 1 phan tu ra khoi Queue bang phuong phap Tinh Tien"
             << "\n5. Push / Them 1 phan tu vao Queue bang phuong phap Vong"
             << "\n6. Pop / Lay 1 phan tu ra khoi Queue bang phuong phap Vong"
             << "\n7. Kiem tra Queue rong"
             << "\n8. Kiem tra Queue day";
        cout << "\n\nMoi ban nhap: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init(a, Front, Rear);
            CheckInit = true;
            cout << "\nKhoi tao thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                cout << "Queue cua ban: " << endl;
                Process_Queue(a, Front, Rear);
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri de them vao Queue bang phuong phap Tinh Tien: ";
                cin >> x;

                int KQ = Push_TinhTien(a, Front, Rear, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 4:
            if (CheckInit)
            {
                int x;

                int KQ = Pop_TinhTien(a, Front, Rear, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nGia tri vua duoc lay ra khoi Queue bang phuong phap Tinh Tien la: " << x;
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 5:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap gia tri de them vao Queue bang phuong phap Vong: ";
                cin >> x;

                int KQ = Push_Vong(a, Front, Rear, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nThuc hien thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 6:
            if (CheckInit)
            {
                int x;

                int KQ = Pop_Vong(a, Front, Rear, x);
                if (KQ == 0)
                    cout << "\nThuc hien khong thanh cong!!!";
                else if (KQ == 1)
                    cout << "\nGia tri vua duoc lay ra khoi Queue bang phuong phap Vong la: " << x;
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 7:
            if (CheckInit)
            {
                int KQ = IsEmpty(a, Front, Rear);
                if (KQ == 0)
                    cout << "\nQueue dang ton tai phan tu!!!";
                else if (KQ == 1)
                    cout << "\nQueue dang rong!!!";
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        case 8:
            if (CheckInit)
            {
                int KQ = IsFull(a, Front, Rear);
                if (KQ == 0)
                    cout << "\nQueue chua day!!!";
                else if (KQ == 1)
                    cout << "\nQueue dang day!!!";
            }
            else
                cout << "\nVui long khoi tao Queue!!!";
            break;
        default:
            cout << "\n\t====== EXIT ======";
        }

        cout << endl;
        system("pause");
    } while (choose >= 1 && choose <= 8);

    system("pause");
    return 0;
}

void Init(int a[], int &Front, int &Rear)
{
    Front = -1;
    Rear = -1;
}
int IsFull(int a[], int Front, int Rear)
{
    if (Rear - Front == MAX - 1 || Rear - Front == -1)
        return 1;
    return 0;
}
int IsEmpty(int a[], int Front, int Rear)
{
    if (Rear == -1 && Front == -1)
        return 1;
    return 0;
}
void Process_Queue(int a[], int Front, int Rear)
{
    for (int i = Rear; i >= Front; i--)
    {
        cout << a[i] << endl;
    }
}
/*=================== Tinh Tien ======================*/

int Push_TinhTien(int a[], int &Front, int &Rear, int x)
{
    if (!IsFull(a, Front, Rear))
    {
        if (IsEmpty(a, Front, Rear))
            Front = 0;
        if (Rear == MAX - 1)
        {
            for (int i = Front; i <= Rear; i++)
            {
                a[i - Front] = a[i];
            }
            // Cap nhat lai Front va Rear ve dung vi tri
            Rear = MAX - 1 - Front;
            Front = 0; //Front phai thay doi gia tri sau Rear thi Rear moi co cai de tru :))) Sai sml troi oi
        }

        a[++Rear] = x;
        return 1;
    }
    return 0;
}
int Pop_TinhTien(int a[], int &Front, int &Rear, int &x)
{
    if (!IsEmpty(a, Front, Rear))
    {
        x = a[Front++];
        if (Front > Rear)
        {
            Front = -1;
            Rear = -1;
        }
        return 1;
    }
    return 0;
}

/*=================== Vong ======================*/

int Push_Vong(int a[], int &Front, int &Rear, int x)
{
    if (!IsFull(a, Front, Rear))
    {
        if (IsEmpty(a, Front, Rear))
            Front = 0;
        if (Rear == MAX - 1)
            Rear = -1;

        a[++Rear] = x;
        return 1;
    }
    return 0;
}
int Pop_Vong(int a[], int &Front, int &Rear, int &x)
{
    if (!IsEmpty(a, Front, Rear))
    {
        x = a[Front];
        if (Front == Rear)
        {
            Front = -1;
            Rear = -1;
        }
        else
        {
            Front++;
            if (Front > MAX - 1)
                Front = 0;
        }
        return 1;
    }
    return 0;
}