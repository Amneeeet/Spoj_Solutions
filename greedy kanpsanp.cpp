      ///yo pandi one day u'll feel proud of your brother. this is not a  overconfident
	              // this is a (shapath)/...................................stop.
	              // output is                       Pandi_Aitech

#include<bits/stdc++.h>
using namespace std;
#define ul unsigned long long
ul ans[200050];

//// medium porblem knapsnap version in which weight is not greater than 2
int main()
{
ul n;
cin>>n;
vector<ul> one,two;
ul weight,cost,total_weight=0;
for(ul i=1;i<=n;i++)
{
	cin>>weight>>cost;
	if(weight==1)
	one.push_back(cost);
	else
	two.push_back(cost);
	total_weight+=weight;

}
sort(one.begin(),one.end());
sort(two.begin(),two.end());
// first of all check for all the even positions bro
vector<ul> ONE=one;vector<ul> TWO=two;
ul cur=0;
for(ul w=2;w<=total_weight;w+=2)
{
	ul cost_1=0,cost_2=0;
	if(two.size()>=1)
	cost_1=two.back();
	int flag=1;
	if(one.size()>=2)
	{
		cost_2=one.back();
		cost_2+=one[one.size()-2];
	}
	else if (one.size()>=1){
	cost_2=one.back();flag=2;}

	if(cost_1>cost_2)
	{
		cur+=cost_1;
		two.pop_back();
	}
	else
    {
		cur+=cost_2;
		if(flag==1)
		{
			one.pop_back();
			one.pop_back();
		}
		else
		one.pop_back();

	}
	ans[w]=cur;

}

//////////////////////////////////////////////////////////////odd
one=ONE;
two=TWO;
 cur=0;
if(one.size()>=1)
{
    cur=one.back();
    one.pop_back();
}
ans[1]=cur;

   for(ul w=3;w<=total_weight;w+=2)
{
	ul cost_1=0,cost_2=0;
	if(two.size()>=1)
	cost_1=two.back();
	int flag=1;
	if(one.size()>=2)
	{
		cost_2=one.back();
		cost_2+=one[one.size()-2];
	}
	else if (one.size()>=1){
	cost_2=one.back();flag=2;}

	if(cost_1>cost_2)
	{
		cur+=cost_1;
		two.pop_back();
	}
	else
    {
		cur+=cost_2;
		if(flag==1)
		{
			one.pop_back();
			one.pop_back();
		}
		else
		one.pop_back();

	}
	ans[w]=cur;

}

for(ul w=1;w<=total_weight;w++)
cout<<ans[w]<<" ";















    return 0;
}
