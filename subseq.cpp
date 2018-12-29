#include <bits/stdc++.h>
using namespace std;

///// so done with hashmap with cumulative sums

int main () 
{
	int t;
	cin >> t;
	map < long long int , long long int > sum_p;
	while ( t-- ) 
	{
		long long int ans = 0;
		long long int n;
		cin >> n;
		long long int array[n];
		cin>>array[0];
		for(int i=1;i<n;i++) 
		{
			cin>>array[i];
			array[i]=array[i]+array[i-1];
		}
		
// now we hve the cumulative sum bro

sum_p[0]++;// for the first 47 value bro beta

for(int i=0;i<n;i++)
{
auto value=	array[i];// this is the cumulative sums bro
ans+=sum_p[value-47];// prev cumulative sum if any then plus usdi freqnexy
sum_p[value]++;
}

		cout << ans << endl;
		sum_p.clear();
	}

	return 0;
}
