#include<bits/stdc++.h>
/// Boost library
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
typedef cpp_int Bignum;
Bignum binary_coeficient(Bignum n,Bignum k)
{
	Bignum res=1;
	if(k>n-k)
	k=n-k;
	for(Bignum i=0;i<k;i++)
	res*=(n-i),res/=(i+1);
	return res;
}
int main()
{
	while(true){
	  Bignum n;cin>>n;
	  if(n==-1)
	  break;
		Bignum c=binary_coeficient(2*n,n);
		Bignum value=c/(n+1);
		cout<<value<<endl;
	           }
}
