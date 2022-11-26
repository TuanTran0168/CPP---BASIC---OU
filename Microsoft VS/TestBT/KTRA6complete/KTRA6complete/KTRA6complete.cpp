#include <iostream>
using namespace std;
int main ()
{
  int n;
  do
  {
  int ks=0;
  long s=0, t=0;
	  do
	  {
		cout<<"nhap mot so nguyen: ";
	    cin>>n;
		if(n<=0)
		{
			cout<<"ban nhap sai, moi ban nhap lai" << endl<<endl;
		}//if 5
	  }//do
	  while(n<=0); 
	  int n1 = n;
	  while(n1>0)
	  {
	    t = t + n1%10;
	    s = s*10 + n1%10;
	    ks++;
	    n1 = n1/10;
	  }//while
	  cout<<"tong cac ky so la : " <<t << endl;
	  cout<<"so ky so la : " <<ks<< endl;
	  cout<<"so dao nguoc la : " << s <<endl;
	  if(n == s)
	  {
		cout<<"so " <<n<<" la so doi xung"<<endl<<endl;
	  }//if
	  else
		cout<<"so "<<n<< " la so khong doi xung"<<endl<<endl;
	}//do
	while(n>0);
  return 0;
}//main