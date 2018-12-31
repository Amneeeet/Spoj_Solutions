#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

///// so done with hashmap with cumulative sums
//                                                    Again   after sometime the auditions problem problem

int main () 
{
	ll n;
	cin >> n;
	ll sum=0;
	for(int i=1;i<=sqrt(n);i++)
	{
	sum+=(n/i)-(i-1);
	}
	cout<<sum<<endl;
    
}