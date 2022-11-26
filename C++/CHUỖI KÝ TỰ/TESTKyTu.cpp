#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;
const int row = 4;
const int col = 1;
void ham_Xuat(string a[row][col], int row, int col);
void ham_DoiChu(string poem[row][col], int row, int col);

string poem[row][col] = 
                                {
                                    {"ba thuong con vi con giong me"},
                                    {"me thuong con vi con giong ba"},
                                    {"ca nha ta cung thuong yeu nhau"},
                                    {"xa la nho gan nhau la cuoi"}
                                };

int main()
{
    cout << "\tBAI THO BA THUONG CON\n\n";
    ham_Xuat(poem, row, col);
	ham_DoiChu(poem, row, col);
    cout <<"\n\tBAI THO SAU KHI DOI CHU\n\n";
	ham_Xuat(poem, row, col);

	system("pause");
    return 0;
}

void ham_Xuat(string poem[row][col], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << poem[i][j];
        }
        cout << endl;
        
    }
    
}

void ham_DoiChu(string poem[row][col], int row, int col)
{
    string thaythe, timkiem;
    cout <<"\nBan muon thay the chu nao: ";
    getline(cin, timkiem);
    cout << "Nhap chu can thay the: ";
    getline(cin, thaythe);
    
    int sl = 0;
    for(int i = 0; i < timkiem.length(); i++)
    {
        sl++;
    }

	int begin;
    for (int i = 0; i < row; i++)
	{
        for (int j = 0; j < col; j++)
        {
            do
            {
                begin = poem[i][j].find(timkiem, 0);
                if(begin >= 0)
                {
                    poem[i][j].replace(begin, sl, thaythe);
                }
                
            }while(begin >= 0);
        }
    }
}
