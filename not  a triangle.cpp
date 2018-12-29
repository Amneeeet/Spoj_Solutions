#include <bits/stdc++.h>
using namespace std;

int main() {
while(true)
{   int n;
	cin>>n;
	if(n==0)
	break;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a.begin(),a.end());
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
	    {
	    	if(i!=j)
	    	{
	    	auto it=lower_bound(a.begin(),a.end(),a[i]+a[j]);
	    	auto m=it-a.begin();
	    	if(a[m]==a[i]+a[j])
	    	{
	    	while(a[m]==a[i]+a[j])
	    	++m;
	    	count+=(n-m);	
	    	}
	    
	    	else
	    	count+=(n-m);

	    	
	    	
	    	}
	    }
	}
	cout<<count<<endl;
}
	return 0;
}