#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
//                      Mississippi
int main()
/*
F(N) = 34^N+ (30 x N) + (32 + M)
//so  34^N is always one

 - C(N) = F(N) mod (11)
*/
{
int t;cin>>t;
while(t--)

{
   ll n;
   cin>>n;
   int m=0;
   ll total=((30*n)%11);
   while((total%11)!=0){
   ++m;
   ++total;}
   cout<<m<<endl;
}
}
