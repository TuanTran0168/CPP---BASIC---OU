// sau khi em truyen mang TeamsName vao ham de nhan gia tri

// khi em in lai o so 0 bi mat gia tri
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const long MAXCOL = 100;
long Ratio[MAXCOL][MAXCOL] = {{0}};
string TeamsName[MAXCOL] = {" "};

//The number of team will be stored in Ratio[0][0]

void FilesReader(long Ratio[][MAXCOL], string Name[MAXCOL])

{

    ifstream FilesName;
    string FileAdd;
    cout << " Please enter an address to the file: (Example: D:\\taptin\\diem.txt )" << endl;
    cin >> FileAdd;
    FilesName.open(FileAdd, ios::in);

    if (FilesName.is_open())
    {
        FilesName >> Ratio[0][0];
        FilesName.ignore(1);
        for (long i = 0; i < Ratio[0][0]; i++)
        {
            string Temporary = " ";
            getline(FilesName, Temporary, ',');
            //cout << i<<" "<<Temporary <<endl; // cho nay em dung de kiem tra
            Name[i] = Temporary;
            //cout << Name[i] <<endl; // cho nay em dung de kiem tra
        }
        FilesName.ignore(1);
        for (long i = 1; i <= Ratio[0][0]; i++)
            for (long y = 0; y < Ratio[0][0]; y++)
                FilesName >> Ratio[i][y];
        FilesName.close();
        
        cout << " Information received successfully! " << endl;
        cout << "In thong tin truoc khi ra khoi ham" << endl;
        cout << "Gia tri Ratio[0][0]=" << Ratio[0][0] << endl;
        for (int i = 0; i <= Ratio[0][0]; i++)
        {
            for (int j = 0; j <= Ratio[0][0]; j++)
                cout << Ratio[i][j] << "  ";
            cout << endl;
        }
        for (int i = 0; i <= Ratio[0][0]; i++)
            cout << Name[i] << "  ";
        cout << endl;
        system("pause");
    }

    else

        cout << "Can not open the file, please try again!" << endl;
}

int main()

{

    FilesReader(Ratio, TeamsName);

    int MaxTeam = Ratio[0][0];

    cout << endl;

    for (long i = 1; i <= Ratio[0][0]; i++)

    {

        for (long y = 0; y < Ratio[0][0]; y++)

            cout << Ratio[i][y];

        cout << endl;
    }

    cout << endl;

    for (long x = 0; x < MaxTeam; x++)

        cout << TeamsName[x] << endl;

    system("Pause");

    return 0;
}
