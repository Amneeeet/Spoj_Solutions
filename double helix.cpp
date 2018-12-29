#include <bits/stdc++.h>
using namespace std;
int main()
 {
     while(true){
     
int n,n2;
cin>>n; 
if(n==0)
break;
vector<int> a(n+1);
int sum[n+2];
a[n]=20000;
for(int i=0;i<n;i++){
cin>>a[i];
if(i==0)
sum[i]=a[i];
else
sum[i]=sum[i-1]+a[i];}
sum[n]=sum[n-1]+a[n];


cin>>n2;
vector<int> b(n2+1);
b[n2]=20000;
int sum2[n2+2];
for(int i=0;i<n2;i++)
{
cin>>b[i];
if(i==0)
sum2[i]=b[i];
else
sum2[i]=sum2[i-1]+b[i];
}
sum2[n2]=sum2[n2-1]+b[n2];

int prev_1=0,prev_2=0;
int global=0;

for(int i=0;i<=n;i++)
{
    // binary search for the second array
    if(binary_search(b.begin(),b.end(),a[i]))
    {
    auto index=lower_bound(b.begin(),b.end(),a[i]);
    // now find the max element
    int fx=i;
    int sx=index-b.begin();
    //cout<<fx<<"   "<<sx<<endl;
    if(prev_1==0 && prev_2==0)
    {
        int first_sum=sum[fx];
        int second_sum=sum2[sx];
        global+=max(first_sum,second_sum);
         //  cout<<first_sum<<"   "<<second_sum<<"     "<<prev_1<<"   "<<prev_2<<endl;
        prev_1=first_sum;
        prev_2=second_sum;
    }
    else
    {
        int first_sum=sum[fx]-prev_1;
        int second_sum=sum2[sx]-prev_2;
   // cout<<first_sum<<"   "<<second_sum<<"     "<<prev_1<<"   "<<prev_2<<endl;
        global+=max(first_sum,second_sum);
        prev_1=sum[fx];
        prev_2=sum2[sx];

    }




    }

}
///cout<<prev_1<<"   "<<prev_2<<endl;
int solve1=sum[n]-prev_1;
int solve2=sum2[n2]-prev_2;
cout<<(global+max(solve1,solve2)-20000)<<endl;

    
}
 }