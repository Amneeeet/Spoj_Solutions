#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int listt( int a[], int n )  
{  
    int lis[11]={0}; 
    for (int i = 0; i < n; i++ )  
    {
    auto value=a[i];
    //if 7 aya then plus in 7 all the previous values
    for(int  v=value;v>=0;v--)
    lis[value]=(lis[v]+lis[value])%mod;
    lis[a[i]]++;/// apne aap nu  v ginnna va saleyo
    	
    }
    int sum=0;
    for(int i=0;i<=9;i++)
    sum=(sum+lis[i])%mod;
    return sum;
    
    
}
int main() 
{
	// added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int t;
    cin>>t;
    for(int b=1;b<=t;b++)
    {
    	string n;cin>>n;
    	int len=n.length();
    	if(n.length()==1){
    	cout<<"Case "<<b<<": "<<"1"<<endl;continue;}
    	int a[len];
    	for(int i=0;i<n.length();i++)
    	a[i]=n[i]-'0';
    	
    cout<<"Case "<<b<<": "<<listt(a,len)<<endl;
    }
	
}