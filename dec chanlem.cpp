#include<bits/stdc++.h>
using namespace std;
int main()
{
long n,c;
cin>>n>>c;

int l=1,r=n,mid=0,ans=0;;
int val;
while(l<=r){
mid=l+(r-l)/10;
cout<<"1 "<<mid<<endl;
cin>>val;
if(val==0)
{
l=mid+1;
ans=l;

}
else if(val==1)
{
r=mid-1;
ans=r+1;/// means mid answer
cout<<2<<endl;

}

}
cout<<"3 "<<ans<<endl;

}
