#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin>>q;
    vector<pair<ll, ll>> prevq;
    multiset<ll> h1, h2, h3, h4;
    // h1 x+y
    // h2 x-y
    // h3 -x+y
    // h4 -x-y
    ll ans=0;
    while(q--)
    {
        char c;
        ll x, y;
        cin>>c;
        if(c=='+')
        {
            cin>>x>>y;
            x^=ans;
            y^=ans;
            prevq.pb(mp(x, y));
            h1.insert(x+y);
            h2.insert(x-y);
            h3.insert(-x+y);
            h4.insert(-x-y);
        }
        else if(c=='-')
        {
            ll n;
            cin>>n;
            n^=ans;
            pair<ll, ll> p=prevq[n-1];
            x=p.ff;
            y=p.ss;
            h1.erase(h1.find(x+y));
            
            h2.erase(h2.find(x-y));
            h3.erase(h3.find(-x+y));
            h4.erase(h4.find(-x-y));
        }
        else if(c=='?')
        {
            cin>>x>>y;
            x^=ans;
            y^=ans;
            ans=max(max(*h1.rbegin()-(x+y), *h2.rbegin()-(x-y)), max(*h3.rbegin()-(-x+y), *h4.rbegin()-(-x-y)));
            cout<<ans<<endl;
        }
    }
	return 0;
}