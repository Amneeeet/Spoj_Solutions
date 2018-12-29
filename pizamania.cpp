
// o(n) complexity
#include <bits/stdc++.h>
using namespace std;
int findPair(vector<int> &data, int length, int sum)
{
    int c=0;
    int right= length - 1;
    int low = 0;
    while(low<right)
    {
    	long  curSum = data[low] + data[right];

        if(curSum == sum)
        {
            c++;
             low++;
            right--;
        }
        else if(curSum > sum)
            right --;
        else
             low++;
    }

    return c;
    }

int main() {
	int t;cin>>t;
while(t--)
{   int n,m;
	scanf("%d %d",&n,&m);
	set<int> s;
	vector<int> a(n);
	int count=0;
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	cout<<findPair(a,n,m)<<endl;
	
}
}