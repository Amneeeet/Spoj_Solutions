#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

///// so done with hashmap with cumulative sums
//                                                    Again   after sometime the auditions problem problem

int main () 
{
int n,k,s;
	cin >> n >>k>>s;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n,greater<int>());
	int total=k*s,sum=0;int count=0;
	for(int i=0;i<n;i++)
	{
		if(sum<total)
		sum+=a[i],count++;
		else
		break;
	}
	cout<<count<<endl;
	
}