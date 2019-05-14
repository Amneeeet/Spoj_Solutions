
//  greedy stategy

#include<bits/stdc++.h>
using namespace std;
#define ul unsigned int
/// no of chicks     google code jam problem
int main()
{
int vf;cin>>vf;
for(int s=1;s<=vf;s++)
{
	ul n,k,b,t;cin>>n>>k>>b>>t;
	ul speed[n],location[n];
	for(ul i=0;i<n;i++)
	cin>>location[i];
	for(ul i=0;i<n;i++)
	cin>>speed[i];
	int check[n+1]={0};
	/// the first check for the impossibke case
	ul swaps=0;
ul no_of_swaps=0;
	ul finishers=0;
	for(ul i=0;i<n;i++)
	{
		if(speed[i]*t+location[i]>=b){
		finishers++;
		check[i]=true;}
		else
		check[i]=false;

	}
	if(finishers<k){
	cout<<"Case #"<<s<<":"<<" IMPOSSIBLE"<<endl;continue;}
	else
	{
	int finish=0;
	for(ul i=n-1;i>=0;i--)
	{
		 if(check[i]==true)
		 {

		 	finish++;
		 	if(no_of_swaps>0)
		 	swaps+=no_of_swaps;
		 }
		 else
		 no_of_swaps++;


		 	if(k==finish){
		cout<<"Case #"<<s<<": "<<swaps<<endl;break;}

	}



	}
}
}
