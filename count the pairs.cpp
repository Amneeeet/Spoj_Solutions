#include <bits/stdc++.h>
using namespace std;
int main() {
   int n;
   	unsigned long long k;
   	cin>>n>>k;
	unsigned long long count=0;
	vector<unsigned long long  > a(n);
	set<	unsigned long long   > s;
	for(int i=0;i<n;i++){
	cin>>a[i];
	s.insert(a[i]);}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++)
	{
		auto val=a[i]+k;
    	if(s.find(val)!=s.end())
    	count++;
	}
	cout<<count<<endl;}
	
