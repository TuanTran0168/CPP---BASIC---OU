#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX = 100;
int main()
{
    ifstream docFile;
    string a[MAX];
    bool tim = false;
    int v[MAX];
    int b[MAX];
    int d[MAX];
    int soquocgia;
    string nuoc;

    docFile.open("E:\Top20Tokyo.txt", ios::in);
    if (docFile.is_open())
    {
        docFile >> soquocgia;

        for (int i = 0; i < soquocgia; i++)
        {
            if (i == soquocgia - 1)
                getline(docFile, a[i]);
            else
                getline(docFile, a[i], ',');

            cout << i;
        }

        for (int i = 0; i < soquocgia; i++)
        {
            docFile >> v[i];
            docFile.ignore(1);
            docFile >> b[i];
            docFile.ignore(1);
            docFile >> d[i];
            docFile.ignore(1);
        }
        docFile.close();
        cout << "Thanh cong" << endl;
    }
    else
        cout << "Khong mo duoc file";

    for (int i = 0; i < soquocgia; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < soquocgia; i++)
    {
        cout << v[i] << " " << b[i] << " " << d[i] << endl;
    }

    system("pause");
}