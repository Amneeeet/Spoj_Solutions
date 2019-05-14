/// anarmica baby
// 0(n) stack based apporoach
#include<bits/stdc++.h>
#define  ul long long
using namespace std;
int main()
{
	int t=0;
	while(true)
{
	stack<char> s;
	string str;cin>>str;
	if(str[0]=='-')break;
	int wrong=0;
	for(auto value:str)
     	{
		if(value=='{')s.push('{');
		if(value=='}')
		{
			if(s.empty()){
			s.push('}');wrong++;}
			else
				s.pop();
		}
    	}
    	++t;
    	cout<<t<<". "<<((s.size()/2)+wrong)<<endl;
}

}
