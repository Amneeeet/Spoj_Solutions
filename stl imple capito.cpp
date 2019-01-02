#include<bits/stdc++.h>
using namespace std;
//                     **** all about the stl implementation****
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int p[n+1];
		int ans[n+1];
		map<int,int> mp;
		vector<vector<int> > edge(n+1);
		set<int> s;

		for(int i=1;i<=n;i++){
		cin>>p[i];
		s.insert(p[i]);
		mp.insert({p[i],i});}
		for(int i=1;i<=n-1;i++)
		{
			int a,b;cin>>a>>b;
			edge[a].push_back(b);
		    edge[b].push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			s.erase(p[i]);// first popultation// then delete all the edges that connected to it
			for(int j=0;j<edge[i].size();j++)
			s.erase(p[edge[i][j]]);/// eraes all the edges connnedted to it in the set
			
	    if (!s.empty())
        ans[i] = *s.rbegin();/// end  vala maximum
        // again inset all the vaues
        s.insert(p[i]);
        	for(int j=0;j<edge[i].size();j++)
			s.insert(p[edge[i][j]]);/// insert all the edges connnedted to it in the set
        
		}
		for(int i=1;i<=n;i++)
		{
			auto it=mp.find(ans[i]);
			cout<<(*it).second<<" ";
		}
					cout<<endl;
		
		
		
		
	}
}