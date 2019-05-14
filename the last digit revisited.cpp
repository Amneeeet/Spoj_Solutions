
#include <bits/stdc++.h>
using namespace std;
int main()
{
int cycle[10]={0,1,4,4,2,1,1,4,4,2};/// by all calculation
 int t;cin>>t;while(t--)
 {
   string aa;long long b;
   cin>>aa>>b;
   int a=aa[aa.length()-1]-'0';
   if(b==0){
   cout<<"1\n";continue;}
   else  if(a<2 || a==5 || a==6){
    cout<<a<<endl;
    continue;}
    int mod=b%cycle[a]; //  b%4 or b%2    /// take the remainder

    if(mod)// positive
    cout<<(int)pow(a,b%cycle[a])%10<<endl;
    else
    cout<<(int)pow(a,cycle[a])%10<<endl;


 }


}
