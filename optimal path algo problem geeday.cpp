
//  137 ooptimal path algo catching the future farthest
#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;cin>>t;while(t--)
{
int n,m;cin>>n>>m;
int	a[m];
for(int i=1;i<=m;i++)
cin>>a[i];
int saff=0;
set<int> table;
// optimal page replacement algo
for(int i=1;i<=m;i++)
{
	int customer=a[i];
	if(table.find(customer)==table.end())
	{
		saff++;
		if(table.size()==n)
		{
			// check for the net future jehde aai so swap ght hou future vch
			set<int> temp=table;
			for(int f=i+1;f<=m && temp.size()>1;f++)
			temp.erase(a[f]);// jehde huni auga usnu apa delete nu krna baby
			// tmep has one size
			table.erase(*temp.begin());
		}
		table.insert(customer);
	}

}
cout<<saff<<endl;
}



	}

