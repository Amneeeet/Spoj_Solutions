/// Activty alogrithm baby


#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

void readInt(int &x)
{
register int c = gc();
x = 0;
for(;(c<48 || c>57);c = gc());
for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

struct data
{
	int s;
	int f;
	int p;
};
 /// sturcture sort
bool operator<(data const &a,data const &b)
{
    return(a.p!=b.p)?(a.p<b.p):(a.f<b.f);
}

int main()
{
	int t;
	readInt(t);
	while(t--){
		int n,k,i;
		readInt(n);readInt(k);
		data arr[n];
		for(i=0;i<n;i++){
			readInt(arr[i].s);
			readInt(arr[i].f);
			readInt(arr[i].p);
		}
		if(n==0||n==1){
			printf("%d\n",n);
			continue;
		}
		sort(arr,arr+n);
		int cnt=1;
		int cur=0;
		for(i=1;i<n;i++)
		{
			if((arr[i].p!=arr[i-1].p)||(arr[i].p==arr[i-1].p && arr[i].s>=arr[cur].f))
			{
				cur=i;cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
