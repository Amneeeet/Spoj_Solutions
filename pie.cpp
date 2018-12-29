// binary search approach
#include <bits/stdc++.h>
#include<map>
#define ll long long int
double pi=3.141592653589793238462643383279502884197;
using namespace std;
// divide the pie into n friends and me
int main() 
{
  int t;cin>>t;while(t--)
  {
      int n,f;
      cin>>n>>f;
      ++f;// including me bro
      int  b[n+1];
      for(int i=0;i<n;i++)
      cin>>b[i];
      sort(b,b+n);
      long double a[n+1];
       for(int i=0;i<n;i++){
       a[i]=b[i]*b[i]*pi;
       }
       //cout<<endl;
       
    long  double   low=0;
    long  double   high=a[n-1];
     while(high-low>=1e-8)      
  //   You can tell at a glance that “1e6" is one million (1000000)
  // and that "1e-6" is one millionth (0.000001) without having to count zeroes
     {
         long double mid=(low+high)/2;// volume va 
         int volume_divide=0;
         for(int i=0;i<n;i++)
         {
          volume_divide+=(a[i]/mid);
         }
        //cout<<mid<<endl;
         if(volume_divide>=f)// f is the peoples
         low=mid;/// increame it mid
         else
         high=mid;
     }
     printf("%.4Lf\n",low);





  }
}









