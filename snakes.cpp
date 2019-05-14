#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long
using namespace std;

int n, k;

bool exist(vector<int>& pre, int i, int j)
{
	int total;
	if (i == 0)
		total = pre[j];
	else
		total = pre[j] - pre[i-1];
	return ((((j - i + 1) * k) - total) <= i);
}
int32_t main()
{
	int t; cin >> t;
	while(t--) {
		cin >> n;
		int q; cin >> q;
		vector<int> l(n); 
		for (int o = 0; o < n; o++) 
		 cin >> l[o]; 
		vector<int> pre(n, 0);
		sort(l.begin(), l.end());
		pre[0] = l[0];
		for (int i = 1; i < n; ++i)
			pre[i] = pre[i-1] + l[i];
		for (int i = 0; i < q; ++i)
		{
			cin >> k;
			int j = (lower_bound(l.begin(), l.end(), k) - l.begin());
			j--;
			if (j < 0)
			{
				cout << n << "\n";
				continue;
			}
	int s = 0, e = j + 1;
			while(s < e)
			{
				int m = (s + e) / 2;
				if(exist(pre, m, j))
					e = m;
				else
					s = m + 1;
			}
			cout << n - s << "\n";
		}
	}
	return 0;
}