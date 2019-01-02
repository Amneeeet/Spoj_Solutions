#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	
int t;cin>>t;
while(t--)
{
	////////////////////////////////log(n) operations only insettion,search and deletion
	multiset<ll,greater<ll> > mx;
	multiset< ll > mi;
	ll n,k;cin>>k>>n;
	ll c=0;
	for(ll i=0;i<n;i++)
	{
	ll v;
	cin>>v;
	++c;
	if(c==k)
	{
		mi.insert(v);
		mx.insert(v);
		cout<<*mi.begin()<<" ";
	}
	else if(c<k)
	{
		mi.insert(v);
		mx.insert(v);
		cout<<"-1 ";
	}
	else
	{
		auto it=*mi.begin();
		if(v<=it)
		cout<<it<<" ";
		else
		{
			//greater
		mi.erase(it);
		mi.insert(v);
	    mx.erase(mx.find(it));
	    mx.insert(v);
	    cout<<*mi.begin()<<" ";
			
		}
		
		
	}
	
	
	}
	cout<<endl;

	
	
	
	
	
}

}
