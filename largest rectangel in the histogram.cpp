/// largest area of the rectangle in the histogram
// 0(n) stack based apporoach
#include<bits/stdc++.h>
#define  ul unsigned long long
using namespace std;
ul largest_rec_in_histo(ul *hist,ul n)
{
	stack<ul> s;
	ul max_area=0;
	ul area_top=0;
	ul i=0;
	while(i<n)
	{
		if(s.empty()==true|| hist[s.top()]<=hist[i])
		s.push(i++);
		else
		{
			ul topp=s.top();
			s.pop();
			 area_top=hist[topp]*(s.empty()?i:i-s.top()-1);
			 if(max_area<area_top)
			 max_area=area_top;


		}
	}
	// jehdiy value bach giya
	while(s.empty()==false)
	{
		    ul topp=s.top();
			s.pop();
			 area_top=hist[topp]*(s.empty()?i:i-s.top()-1);
			 if(max_area<area_top)
			 max_area=area_top;
	}
	return max_area;
}
int main()
{
	while(true)
	{
		ul a[100001];
		ul n;
		cin>>n;
		if(n==0)
		break;
		for(ul i=0;i<n;i++)
		cin>>a[i];
		cout<<largest_rec_in_histo(a,n)<<endl;
	}
}
