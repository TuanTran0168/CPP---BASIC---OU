#include <iostream>
#include <string>
using namespace std;
const int MAX=12;
string VN[MAX+1]={"","34-35","35","35-36","36","36-37","37","37-38","38","38-39","40","40-41","41"};
double US[MAX+1]={0,4, 4.5,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5};
double UK[MAX+1]={0,2, 2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5};
//Cac ban bo sung them viec tinh ra chieu dai ban chan!!!!
int main1()
{
cout<<"Bang qui doi co giay cho Nu"<<endl;
for(int i=1;i<=MAX;i++)
{
cout<<i<<"- Size "<<VN[i]<<endl;
}
cout<<"Nhap vao so tuong ung voi co giay (size) theo tieu chuan VN (1-"<<MAX<<"): ";
int cogiay;
cin>>cogiay;
cout<<"Co giay VN "<<VN[cogiay]<<" qui doi ra US la "<<US[cogiay]<<" va qui doi ra UK la"
 <<UK[cogiay]<<endl;
system("pause");
return 0;
}