
//  greedy stategy

#include<bits/stdc++.h>
using namespace std;
#define ul 	int
int main()
{
while(true)
{
  ul n;cin>>n;
  if(n==-1)
  break;
  ul sum=0;
  ul a[n+1];
  for(ul i=1;i<=n;i++){
  cin>>a[i];sum+=a[i];}
  ul average=sum/n;
  ul count=0;
  if(sum%average)
  cout<<"-1\n";
  else
  {
  	 for(ul i=1;i<=n-1;i++)
  	 {
  	 ul diff=a[i]-average;
  	 a[i+1]+=diff;
  	 count=max(count,abs(diff));
  	 }
  	 cout<<count<<endl;
  }






}
}
