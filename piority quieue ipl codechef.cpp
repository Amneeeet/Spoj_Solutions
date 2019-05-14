#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct trainer
{
    int day;
    int lecture;
    int sadness;
};


bool comp(trainer a, trainer b)
{
    return a.sadness<b.sadness;
}
bool compday(trainer a, trainer b)
{
    return a.day<b.day;
}
int main() {
	// your code goes here
	#ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,d;
	    cin>>n>>d;
	    long long int total=0,sum=0;
	    int i,k;
	    priority_queue<trainer, vector<trainer>, function<bool(trainer,trainer)> > p(comp);
	    trainer arr[n];
	    
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i].day>>arr[i].lecture>>arr[i].sadness;
	        total+=arr[i].sadness * (long long int)arr[i].lecture;
	    }
	    
	    sort(arr,arr+n,compday);
	    k=0;i=0;
	    
	    for(k=1;k<=d;k++)
	    {
	    	 while(i<n && arr[i].day==k)
	        {
	            p.push(arr[i]);
	            i++;
	        }                                   // only 3 days
	        if(p.size()==0)continue;
	      //  cout<<"Before "<<p.top().sadness<<" "<<p.top().lecture<<endl;
	        sum+=p.top().sadness;
	        trainer a=p.top();
	        p.pop();
	        a.lecture-=1;
	        if(a.lecture>0)
	        p.push(a);
	        
	        //cout<<"After "<<p.top().sadness<<"   "<<endl;
	        // cout<<"Remaining and sum are "<<p.top().lecture<<" "<<sum<<endl;
	    }
	    
	   cout<<total-sum<<endl;
	   
	}
	
	return 0;
}