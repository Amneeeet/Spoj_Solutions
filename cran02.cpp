#include <bits/stdc++.h>
using namespace std;
//	/// so done with hashmap with cumulative sums
int main () {

	int t;
	cin >> t;
	map< long long int , long long int > sum_p;
	while ( t-- ) {
		long long int count = 0;
		long long int n;
		cin >> n;
		long long int array[n];
		cin >> array[0];
		sum_p[ array[0] ] ++;
		for ( int i = 1 ; i < n ; i++ ) {
			cin >> array[i];
			array[i] += array[i-1];
			sum_p[ array[i] ] ++;
		}
		// array[i] is the xumulative sum bro


		for (auto itr = sum_p.begin() ; itr != sum_p.end() ; itr++ ) {
			long long int a,b;

			a = itr->first;
			b = itr->second;
		

			if ( a != 0 ) {
				count += b * (b-1) / 2;// simple plus  the range  1 +2+3+4+5+6
			}
			else {
				count += b + (b * (b-1)/2 );// if zero appear then zero + freq of the zeros range   (1+2+3+4+5+6) if zero appear then this plus the count of the zeros
			}
		}

		cout << count << endl;
		sum_p.clear();
	}

	return 0;

}
