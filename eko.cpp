#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
	// added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ll n,meter;
    cin>>n>>meter;
    ll mx=0;
    ll a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(a[i]>mx)
    mx=a[i];
    }
    sort(a,a+n);
    ll low=0;
    ll high=mx;
    ll ans=0;
    while(low<=high)
    {
    	ll mid=(low+high)/2;
    	ll wood=0;
    	for(int i=0;i<n;i++)
    	{
    		if(a[i]>mid)
    		wood+=(a[i]-mid);
    	}
        if(wood>=meter)
    	{
    		ans=mid;
    		 low=mid+1;
    	}
    	else
    	high=mid-1;
    
    	
    }
    cout<<ans<<endl;
	
}