//// countsubs
//// binary search first

#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{	
	ll int n,k,q,t,i,j,count0,count1,l,r,k1,ans,k2,km;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>n>>k>>q;
		cin>>s;
		count0=0,count1=0,j=0;
		vector<ll int> far(n+1),sumfar(n+1);
		far[0]=0;
		for(i=1;i<=n;i++)
		{
			while(j<=n&&count0<=k&&count1<=k)
			{
				j++;
				if(j>n)
				break;
				if(s[j-1]=='0')
				count0++;
				else if(s[j-1]=='1')
				count1++;
				
			}
			far[i]=j;
			if(s[i-1]=='0')
			count0--;
			else if(s[i-1]=='1')
			count1--;
		}	
		sumfar[0]=far[0];
		
		for(i=1;i<=n;i++)
		sumfar[i]=far[i]+sumfar[i-1];
		
		for(i=0;i<q;i++)
		{
			cin>>l>>r;
			if(l==r)
			{
				cout<<1<<endl;
				continue;
			}
			ans=0;
		         k1 = l-1;
   			 k2 = r+1;
   			 // find teh k which is less than equal to r far[k]<=r<=far[k-1]
   		 while (k2-k1>1)
		{
        	km = (k1 + k2)/2;
       		if(far[km] <= r)
            	k1 = km;
       		 else
          	  k2 = km;
		}
			ans+=sumfar[k1]-sumfar[l-1];
			ans+=(r-k1)*(r+1);
			ans-= r*(r+1)/2 - (l*(l-1)/2) ;
			cout<<ans<<endl;
		}
		
	}
}
