
//  SPOJ BINARY SEARCH PROBLEMS AGGRESIVE COWS
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int t;cin>>t;while(t--){
    ll cows,n;
    cin>>n>>cows;
    ll stals[n+1];
    for(int i=0;i<n;i++)cin>>stals[i];
    sort(stals,stals+n);
    ll l=0,mid;
    ll h=10000000LL;
    while(l<=h)
    {
        mid=(l+h)/2;
        ll c=1;
        ll manage=stals[0];
        for(int i=1;i<n;i++)
        {
         if(stals[i]-manage>=mid)//kine stalls  chal sakde
         {
             c++;
             manage=stals[i];
         }
         if(c>cows)
         break;
        }
        if(c<cows)
        h=mid-1;
        else
        l=mid+1;
    }
    cout<<h<<endl;

    }

	
} 
