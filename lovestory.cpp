#include <bits/stdc++.h>
#include<map>
#define ll long long int
using namespace std;
int main() 
{
    int t;cin>>t;
    while(t--)
    {
        int  n;
        ll p;
        cin>>n;
        ll a[n+1];
        map<ll,pair<int,int> > s;
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        {
             for(int j=i;j<n;j++)
             {
               if(i!=j)
               s.insert(make_pair(a[i]+a[j],make_pair(i,j)));
               
             } 
        }



        cin>>p;
        ///cout<<p<<endl;
        int flag=0;
       map< ll,  pair < int, int > > :: iterator it;
    for(int i=0;i<n;i++)
    {
    ll current=p-a[i];
     it = s.find(current);
    if(it!=s.end())
    {
        if(it->second.first!=i && it->second.second!=i){
        flag=1;break;}

    }

    }
        if(flag==1)
        cout<<"YES\n";
        else cout<<"NO\n";
    }

}









