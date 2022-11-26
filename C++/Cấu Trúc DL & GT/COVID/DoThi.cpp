#include <iostream>
#include <fstream>
#include <string>
const int MAX = 20;
using namespace std;
struct NODE
{
    int infor;
    struct NODE *link;
};
typedef struct NODE Node;

Node *sp;          // Cua Stack
Node *front, rear; // Cua Queue

int A[MAX][MAX];
int n;
char vertex[MAX];

void khoiTao();
void nhapMaTran();
void xuatMaTran();
void docFile();

int main()
{
    int choice;

    do
    {
        system("cls");
        cout << " ---------BTH5 , CHUONG 5 , DO THI -------" << endl;
        cout << "1. Khoi tao MA TRAN KE rong" << endl;
        cout << "2. Nhap MA TRAN KE tu file text" << endl;
        cout << "3. Nhap MA TRAN KE " << endl;
        cout << "4. Xuat MA TRAN KE " << endl;
        cout << "5. Duyet do thi theo chieu rong BFS" << endl;
        cout << "6. Duyet do thi theo chieu sau DFS" << endl;
        cout << "7. Tim dinh co gia tri x theo BFS";
        cout << "8. Thoat" << endl;
        cout << "\nVui long chon so de thuc hien: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            khoiTao();
            cout << "\nKhoi tao thanh cong!!!";
            break;

        case 2:
            docFile();
            break;

        case 3:
            nhapMaTran();
            break;

        case 4:
            xuatMaTran();
            break;

        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            cout << "Da thoat!" << endl;
            break;

        default:
            break;
        }

        cout << endl;
        system("pause");
    } while (choice != 8);

    system("pause");
    return 0;
}

void khoiTao()
{
    n = 0;
}

void nhapMaTran()
{
    cout << "\nNhap so dinh cua do thi: ";
    cin >> n;
    cout << "\n\tNhap ten dinh \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ten dinh thu " << i << ": ";
        cin >> vertex[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n\tNhap dong thu " << i << ": \n";
        for (int j = 0; j < n; j++)
        {
            cout << "Nhap vao cot thu " << j << ": ";
            cin >> A[i][j];
        }
    }
}

void xuatMaTran()
{
    cout << "  ";
    for (int i = 0; i < n; i++)
    {
        cout << vertex[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vertex[i] << " ";
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void docFile()
{
    ifstream docFile;
    docFile.open("E:\\TXT\\maTranKe.txt", ios::in);
    if (docFile.is_open())
    {
        cout << "\nDoc FILE thanh cong";
        while (!docFile.eof())
        {
            while (!docFile.eof())
            {
                docFile >> n;
                for (int i = 0; i < n; i++)
                {
                    docFile >> vertex[i];
                }

                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        docFile >> A[i][j];
                    }
                }
            }
            docFile.close();
        }
    }
    else
    {
        cout << "\nKhong mo duoc FILE";
    }
}