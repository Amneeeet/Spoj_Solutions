#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;cin>>n;
	multiset< ll,greater<ll> > max_heap;// 2 by 3 elements
	multiset< ll > min_heap;///  1 by 3 elemnts

    ll b=0;
for(ll i=0;i<n;i++)
{
	

int x;cin>>x;
if(x==1)
{
	b++;
	ll v;
	cin>>v;
    if(b<3)max_heap.insert(v);
    else if(b%3==0)
    {
    	// means insert ik hor element
    	auto it=*max_heap.begin();
    	if(v>it)     	min_heap.insert(v);
    	else
    	{
    		min_heap.insert(it);
    		max_heap.erase(max_heap.begin());
    		max_heap.insert(v);
    		
    	}
    	
    }
    else
    {
    	ll val = *min_heap.begin();
            if (v > val)
            {
                max_heap.insert(val);
                min_heap.erase(min_heap.begin());
                min_heap.insert(v);
            }
            else                        max_heap.insert(v);
        }
    }
    else if (x == 2)
    {
            if (min_heap.empty())             cout << "No reviews yet\n";
            else                        cout << *min_heap.begin() << '\n';
    }
}




}
