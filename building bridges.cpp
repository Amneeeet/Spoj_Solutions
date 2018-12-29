#include <bits/stdc++.h>
using namespace std;///
///                      dp buliding bridges bro easy
 // test case  1 
/* 2 5 8 10
   6 4 1 2
   ans**->
 bridge1  1 2 3 4 5 6 7 8 9 10
             .    .     .    .
          . .   .   .
 bridge2  1 2 3 4 5 6 7 8 9 10
 /// over lap is    2 5
                    6 4
                    //// algo
                    1.sort according to any bridge suppose 1
                    2. find the LIS in the second bridge  2     
                    
                    /// done
 */
 bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
	if(a.second==b.second)
	return (a.first<=b.first);
	else return (a.second < b.second); 
} 
int lits(	vector< pair<int,int> > arr , int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i].first >= arr[j].first && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  
int main() {
   int t;cin>>t;
   while(t--)
   {
   	int n;cin>>n;
   	int a[n],b[n];
   	vector<pair<int,int> > vc;
   	for(int  i=0;i<n;i++)
   		cin>>a[i];
   		for(int  i=0;i<n;i++)
   		cin>>b[i];
   		for(int  i=0;i<n;i++)
   		vc.push_back(make_pair(a[i],b[i]));
   	sort(vc.begin(),vc.end(),sortbysec);
   	for(auto s:vc)
   	cout<<s.first<<"  "<<s.second<<endl;
   	cout<<endl;
   	// find the lis in the pair.first
   	cout<<lits( vc,n )<<endl;
   	
   	
   	
   	
   }
   	
   	
   	
   	
   	
   	
   	
          }