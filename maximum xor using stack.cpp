/// maximum Xor of the mx and scond max in a sequence using the stack based apporoach
// 0(n) stack based apporoach
#include<bits/stdc++.h>
#define  ul long long
using namespace std;
int main()
{
	ul n,mx=-1;;cin>>n;
	ul a[100001];
	for(ul i=0;i<n;i++)
	cin>>a[i];
	stack<ul> forward_increasing;	ul first=a[0]; ul second=a[1];
	forward_increasing.push(first);forward_increasing.push(second);
	mx=max(first^second,mx);
	for(ul i=2;i<n;i++)
	{
		while(!forward_increasing.empty() && forward_increasing.top()<a[i])
		forward_increasing.pop();
        long long last=a[i];
        if(!forward_increasing.empty())
        {
            long long prev=forward_increasing.top();
            mx=max(mx, prev^last);
        }
        forward_increasing.push(last);
	}
	// backward increasing
	stack<ul> backward_increasing;	 first=a[n-1]; second=a[n-2];
	backward_increasing.push(first);backward_increasing.push(second);
	mx=max(first^second,mx);
	for(ul i=n-3;i>=0;i--)
	{
		while(!backward_increasing.empty() && backward_increasing.top()<a[i])
		backward_increasing.pop();
        long long last=a[i];
        if(!backward_increasing.empty())
        {
            long long prev=backward_increasing.top();
            mx=max(mx, prev^last);
        }
        backward_increasing.push(last);
	}
	cout<<mx<<endl;


}
