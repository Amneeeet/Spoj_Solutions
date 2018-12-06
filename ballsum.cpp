#include<bits/stdc++.h>
/// Boost library
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
typedef unsigned long long  BB;
int main()
{
while(true)
{
BB n,k;
cin>>n>>k;
if(n==-1 && k==-1)break;
BB total=(n*(n-1))/2;
BB de=floor(((k-1)*(k-1))/4);
if(de==0){
cout<<"0\n";continue;}
BB value=__gcd(total,de);
BB check=((total/value)/(de/value));
if(check==1){
cout<<check<<endl;continue;}
cout<<de/value<<"/"<<total/value<<endl;
}
    //floor(n^2/4)


}
