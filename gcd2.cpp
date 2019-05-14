
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
     int a,g;
     string b;
     cin>>a;cin>>b;
     if(a==0){
     cout<<b<<endl;
     continue;}
      g=b[0]-'0';
      for(int i=1;i<b.length();i++)
      g=(g*10+(b[i]-'0'))%a;
     g= __gcd(a,g);
     cout<<g<<endl;



 }
}
