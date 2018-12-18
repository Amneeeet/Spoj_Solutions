
//  greedy stategy

#include<bits/stdc++.h>
using namespace std;
vector< pair < int,int > > vc;
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}
 void func(int x,int *a,int *b,int n,int *flag)
 {
 	for(int i=1;i<=n;i++)
 	{
 	if(a[i]>b[i])
 vc.push_back(make_pair(a[i]-b[i],i));// insert the difference
 	}
 	sort(vc.begin(),vc.end(),sortinrev);
 for(int i=0;i<vc.size();i++)
 {
 	if(x>0)
 	{
 		flag[vc[i].second]=1;
 		--x;
 	}
 }


 }
int main()
{
int n,x,y;
cin>>n>>x>>y;
int a[n+1];
int b[n+1];
int flag[100001]={0};
long  sum=0;
for(int i=1;i<=n;i++)
cin>>a[i];
for(int i=1;i<=n;i++)
cin>>b[i];
// check for the min

if(x<=y)
{
func(x,a,b,n,flag);
for(int i=1;i<=n;i++)
{
	//cout<<flag<<"  "<<a[i]<<" "<<b[i]<<endl;
	if(flag[i]==1)
	sum+=a[i];
	else
	sum+=b[i];
}
}

else
{
//	cout<<"aahi clya 2 \n";
func(y,b,a,n,flag);
for(int i=1;i<=n;i++)
{
	if(flag[i]==1)
	sum+=b[i];
	else
	sum+=a[i];
}
}
cout<<sum<<endl;
}
