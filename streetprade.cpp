#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(true)
	{
			stack<int> s;
			int n;
			cin>>n;
			if(n==0)
			break;
			int value;
			int moto=1;
			int a[1001];
			int flag=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
	    for(int i=1;i<=n;i++){
		     value=a[i];
		    // cout<<value<<endl;
			if(value!=moto)
			{
				if(s.empty())
				s.push(value);
				else
				{
					while(s.top()==moto)
					{
					moto++;
					s.pop();
					if(s.empty())
					break;
					}
					if(value==moto)
					moto++;
					else if(s.empty())
					s.push(value);
					else if(s.top()<value){
					flag=1;break;}
					else
					s.push(value);


				}
			}
			else
			moto++;
		}
		if(flag==1)
		cout<<"no\n";
		else
		cout<<"yes\n";
	}
}
