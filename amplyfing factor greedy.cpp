#include <bits/stdc++.h>
#define ul int
using namespace std;

int main()
{
int t;
cin>>t;
while(t--){
ul n;
cin>>n;
 int a[n+1];
 ul count=0;
ul count_2=0;
for(ul i=0;i<n;i++){
cin>>a[i];
if(a[i]==1)
count++;
else if(a[i]>3)
count_2++;
}
sort(a,a+n);

// check for the cases of two
for(ul i=1;i<=count;i++)
cout<<"1 ";
if(count_2>0){
for(ul i=n-1;i>=0;i--){
if(a[i]==1)
break;
cout<<a[i]<<" ";
}
cout<<endl;
continue;}
else
{
for(ul i=n-1;i>=0;i--){
if(a[i]==1)
break;
if(a[i]==3 && a[i-1]==2){
swap(a[i],a[i-1]);}
cout<<a[i]<<" "; }
cout<<endl;
}










}
}
