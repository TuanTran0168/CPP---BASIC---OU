#include <iostream>
using namespace std;
int main()
{
int n=7,k=1,v=0,kt=0;
while (v>=0){
if (kt==0){
for(int i=1;i<=v;i++) cout<<" ";
for(int i=1;i<=n-v*2;i++){
int a=k+(i-1)*2;
cout<<a<<" ";
}
cout<<endl;
v++;
k++;
if (v==4) {kt=1;v=2;}
}
if (kt==1){
for (int i=1;i<=v;i++) cout<<" ";
for(int i=1;i<=n-v*2;i++){
int a=k+(i-1)*2;
cout<<a<<" ";
}
k++;
v--;
cout<<endl;
}
}
system("pause");
}