//MMASS - Mass of Molecule
// adhoc based
#include<bits/stdc++.h>
using namespace std;
int value(char c)
{
	switch(c)
	{
		case 'C' : return 12;
		case 'O' : return 16;
		case 'H' : return 1;

	}
}
int main()
{
	stack<int> s;
string str;
cin>>str;
int sum;
for(auto i:str)
{
   if(isdigit(i))
    {
	 sum=s.top();
	 s.pop();
	 s.push(sum*(i-'0'));
    }
    else if(i=='(')s.push(-1);
    else if(i==')')
    {
    	sum=0;
    	while(!s.empty() && s.top()!=-1)
    	{
    		sum+=s.top();
    		s.pop();
    	}
    	s.pop();
    	s.push(sum);

    }
    else if(isalpha(i))s.push( value(i));
}
sum= 0;
	while(!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	printf("%d\n", sum);
	return 0;

}
