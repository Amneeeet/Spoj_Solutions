#include <bits/stdc++.h>
/// Boost library
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

int main()
{
int t=10;
while(t--)
{
	cpp_int n,more;
	cin>>n>>more;
	if(n%2==0)
	{
	cpp_int half=n/2,even=more/2;
	cpp_int first=half-even,second=half+even;
	cout<<second<<endl;
	cout<<first<<endl;
	}
	else
	{
	cpp_int half1=n/2,half2=(n/2)+1,even=more/2;
	cpp_int first=half1-even,second=half2+even;
	cout<<second<<endl;
	cout<<first<<endl;
	}


}
}
