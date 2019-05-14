#include<bits/stdc++.h>
using namespace std;
int main()
{
long n,c;
cin>>n>>c;

long l=1,r=n,mid;
long flag[150001]={0};
long val;
while(true)
{
if(r<l)
break;
mid=(l+r)/2;
cout<<"1 "<<mid<<endl;
cin>>val;
if(val==1){
flag[mid]=1;
r=mid-1;}
else if(val==0){
l=mid+1;}
cout<<"2"<<endl;
}
for(long i=1;i<=n;i++){
if(flag[i]==1){
cout<<"3 "<<i<<endl;break;}}


}
