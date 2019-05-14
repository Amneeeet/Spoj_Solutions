#include <bits/stdc++.h>
using namespace std;

int n,a,b,x,y,i=0,m[1000005];
m[-1]=0;
string s;
stack<int>st;
map<int,int>mp;

 int main()
 {
	ios::sync_with_stdio(false);
	cin>>s;
	n=s.size();
	while(i<n)
	{

		if(s[i]=='('){st.push(i);}
		else if(!st.empty())
		{
		       m[i]=i-st.top()+1;
		       m[i]+=m[st.top()-1];// jo index add kita usto pehla vaale index da jo v value hai add krna
		       st.pop();
		       x=max(x,m[i]);
		       mp[m[i]]++;


		}
		i++;
	}
	mp[0]=1;////////// mp[0]=1 for the exit condition baby
	cout<<x<<" "<<mp[x];
}
