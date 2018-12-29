#include <bits/stdc++.h>
using namespace std;
#define ll long long int

///// so done with hashmap with cumulative sums
//                                                    Again   after sometime the auditions problem problem

int main () 
{
	int t;
	cin >> t;
	//int sum_p[1000000]={0};
// map <ll,ll> sum_p;
 unordered_map <ll,ll> sum_p;
	while ( t-- ) 
	{
		long long int ans = 0;
		long long int n,k;
		cin >> n  >> k;
		string s;cin>>s;
		long long int array[n];
		array[0]=s[0]-'0';
		for(int i=1;i<n;i++) 
		{
			array[i]=array[i-1]+s[i]-'0';
		}
		
// now we hve the cumulative sum bro

sum_p[0]++;// for the first 47 value bro beta


for(int i=0;i<n;i++)
{
auto value=	array[i];// this is the cumulative sums bro

if(value-k >=0)//// means map vch ta negative sar ju but apne array vch ni sarna
ans+=sum_p[value-k];
sum_p[value]++;
}

		cout << ans << endl;
		sum_p.clear();
	}

	return 0;
}
