#include <iostream>
using namespace std;
bool KTraSoNgTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        if (n == 2)
        {
            return true;
        }
        else
        {
            if (n % 2 == 0)
            {
                return false;
            }
            else
            {
                if (n % 2 != 0)
                {
                    for (int i = 2; i < n; i++)
                    {
                        if (n % i == 0)
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

void ham_Lamlai(int check)
{
        do
        {
	        cout<<"Ban co muon lam lai khong ? \n1.Co\n0.Khong "<<endl;
			cout<<"Nhap: ";
	        cin>>check;
			cout<<endl;
            if(check == 0)
			{
				cout<<"Ket thuc\n";
				break;
			}
		}while(check != 0 && check != 1);	
}

int main()
{
    int n;
    do
    {
        cout << "Nhap so bat ki: ";
        cin >> n;
        if (KTraSoNgTo(n) == true)
        {
            cout << n << " La so nguyen to\n\n";
        }
        else
        {
            cout << n << " Khong phai so nguyen to\n\n";
        }
        int check;
        ham_Lamlai(check);
    } while (n>=0 || n<0);
	system("pause");
	return 0;
}