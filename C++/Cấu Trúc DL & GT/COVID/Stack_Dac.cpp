#include <iostream>
using namespace std;
const int MAX = 100;
void Init(int a[], int &sp);
int IsFull(int a[], int sp);
int IsEmpty(int a[], int sp);
int Push(int a[], int &sp, int x);
int Pop(int a[], int &sp, int &x);
void Output_Stack(int a[], int sp);
int DecToBin_Stack(int a[], int &sp, int Dec);

int main()
{
    int a[MAX];
    int sp;
    bool CheckInit = false;
    int choose;

    do
    {
        system("cls");
        cout << "\n\n\t==== MENU ===\n";
        cout << "\n1. Khoi tao Stack"
             << "\n2. Duyet Stack tu dinh xuong day"
             << "\n3. Push / Them 1 phan tu vao Stack"
             << "\n4. Pop /  Lay 1 phan tu ra khoi Stack"
             << "\n5. Kiem tra Stack Full / Day"
             << "\n6. Kiem tra Stack Empty / Rong"
             << "\n7. Chuyen tu he thap phan sang nhi phan bang Stack";

        cout << "\n\nMoi ban chon: ";
        cin >> choose;

        switch (choose)
        {
        case 1:
            Init(a, sp);
            CheckInit = true;
            cout << "\nKhoi tao thanh cong!!!";
            break;
        case 2:
            if (CheckInit)
            {
                cout << "\nStack cua ban: " << endl;
                Output_Stack(a, sp);
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        case 3:
            if (CheckInit)
            {
                int x;
                cout << "\nNhap phan tu de them vao Stack: ";
                cin >> x;

                int KQ = Push(a, sp, x);
                if (KQ == 1)
                    cout << "\nThem thanh cong!!!";
                else if (KQ == 0)
                    cout << "\nThem khong thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        case 4:
            if (CheckInit)
            {
                int x;
                int KQ = Pop(a, sp, x);
                if (KQ == 1)
                    cout << "\nLay thanh cong phan tu: " << x << " ra khoi Stack";
                else if (KQ == 0)
                    cout << "\nLay khong thanh cong!!!";
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        case 5:
            if (CheckInit)
            {
                if (IsFull(a, sp))
                    cout << "\nStack dang day!!!";
                else
                    cout << "\nStack chua day!!!";
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        case 6:
            if (CheckInit)
            {
                if (IsEmpty(a, sp))
                    cout << "\nStack dang rong!!!";
                else
                    cout << "\nStack chua rong!!!";
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        case 7:
            if (CheckInit)
            {
                int Dec;
                cout << "\nNhap so thap phan nguyen duong: ";
                cin >> Dec;

                int KQ = DecToBin_Stack(a, sp, Dec);
                if (KQ == INT_MIN)
                    cout << "\nChuyen doi khong thanh cong!!!";
                else
                    cout << "\nSo thap phan " << Dec << " chuyen sang nhi phan la: " << KQ;
            }
            else
                cout << "\nVui long khoi tao Stack";
            break;
        }

        cout << endl;
        system("pause");

    } while (choose >= 1 && choose <= 7);

    system("pause");
    return 0;
}

void Init(int a[], int &sp)
{
    sp = -1;
}
int IsFull(int a[], int sp)
{
    if (sp == MAX - 1)
        return 1;
    return 0;
}
int IsEmpty(int a[], int sp)
{
    if (sp == -1)
        return 1;
    return 0;
}
int Push(int a[], int &sp, int x)
{
    if (sp < MAX - 1)
    {
        a[++sp] = x;
        return 1;
    }
    return 0;
}
int Pop(int a[], int &sp, int &x)
{
    if (sp != -1)
    {
        x = a[sp--];
        return 1;
    }
    return 0;
}
void Output_Stack(int a[], int sp)
{
    for (int i = sp; i >= 0; i--)
    {
        cout << a[i] << endl;
    }
}
int DecToBin_Stack(int a[], int &sp, int Dec)
{
    Init(a, sp);
    while (Dec != 0) // Tach so
    {
        int Remainder = Dec % 2; // Remainder: so du ( Ghi tieng anh cho no sang :))) )
        if (!Push(a, sp, Remainder))
        {
            return INT_MIN; //Tra ve so am vo cuc cho khoi bi trung voi so nhi phan tra ve
        }
        //Ham Push da duoc goi phia tren nen khong goi lai nua
        Dec = Dec / 2;
    }

    int Bin = 0;
    while (!IsEmpty(a, sp)) //Neu stack chua rong thi cu lay tiep cho den khi rong thi thoi
    {
        int Temp;
        if (!Pop(a, sp, Temp))
        {
            return INT_MIN; //Tra ve so am vo cuc cho khoi bi trung voi so nhi phan tra ve
        }

        Bin = Bin * 10 + Temp;
    }
    return Bin;
}