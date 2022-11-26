#include <iostream>
using namespace std;
bool ham_KTraSoNguyenTo(int so)
{
  int dem = 0;
  for(int i = 1; i <= so; i++)
  {
    if(so % i == 0)
    {
      dem++;
    }
  }
  if(dem == 2)
  {
    return true;
  }
  else
  {
      return false;
  }
}

int main()
{
  int so1,so2;
  int check;
  do
  {
    cout<<"\nNhap so thu 1: ";
    cin>>so1;
    cout<<"Nhap so thu 2: ";
    cin>>so2;
    cout<<"Cac so nguyen to la: ";
  for(int i = so1; i <= so2; i++)  
  { 
   if(ham_KTraSoNguyenTo(i) == true)
   {
            cout<< i <<" ";
   }
  }      
    cout<<"\n\nBan co muon lam lai khong ? \n1.Co\n2.Khong\n";
    cout<<"Nhap: ";
    cin>>check;
    if(check == 2)
    {
        cout<<"\nKET THUC\n";
        break;
    }
  }while(check == 1);
  system("pause");
  return 0;
}