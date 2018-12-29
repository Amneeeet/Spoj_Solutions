#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,a,b,c,d,e,f;cin>>n;
 int ar[n+1];
 vector<int> one;
  vector<int> two;
 for(int i=0;i<n;i++)cin>>ar[i];
 // all 3loops
 for(int i=0;i<n;i++)
 {
     a=d=ar[i];
     for(int j=0;j<n;j++)
     {
         b=e=ar[j];
           for(int k=0;k<n;k++)
           {
            c=f=ar[k];
            if(d!=0)
            two.push_back(d*(e+f));
            one.push_back(a*b+c);

           }}}// end
    
           sort(one.begin(),one.end());
           int count=0;
           
           for(int i=0;i<two.size();i++)
           {
           // the main optimization
           std::pair<std::vector<int>::iterator, 
             std::vector<int>::iterator> ip;
             ip = equal_range(one.begin(), one.end(), two[i]);
             count+=((ip.second-one.begin())-(ip.first-one.begin()));
           }
           cout<<count<<endl;

           

}