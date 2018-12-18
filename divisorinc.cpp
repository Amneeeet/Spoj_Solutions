#include<bits/stdc++.h>
using namespace std;

class  DivisorInc
    {
    public:
     int countOperations(int n, int m)
         {
         int a[100005];
         for(int i=0;i<=100000;i++)
             a[i]=INT_MAX;// is the max value
         a[n]=0;// if same value return zero
         for(int i=n;i<=m;i++)
             {
             if(a[i]!=INT_MAX){
                 for(int j=2; j*j<=i && i+j<=m;j++)
                 {
                     if(i%j==0)//if it is the divisor
                         {
                 a[i+j]=min(a[i+j],a[i]+1);
                 if(i+(i/j)<=m)
                     a[i+(i/j)]=min(a[i+(i/j)],a[i]+1);
                 }}
                 }

             }
                 if(a[m]==INT_MAX)
                 return -1;
                 return a[m];















         }




    };
