/// #spoj  #big numbers 1.
#include<bits/stdc++.h>
using namespace std;
#define ul unsigned long long
int main()
{
ul t;cin>>t;
	while(t--)
{
	ul n,k,m,man=1000000000000000000ULL;/// if k>59 then break
	ul temp=0;
	cin>>n>>k>>m;
	int time=0;
 while(n<=m)
 {
 	temp=n*k;
 	n=temp;
 	if(n>m)
 	break;
 	time++;
 }
 cout<<time<<endl;

}


}
