#include <iostream>
using namespace std;
//// counting soldiers


// top down apporoach
int min_moves(int miles)
{
	if(miles==0)
	return 0;
	if(miles==1)
	return 2;
	if(miles%2!=0)// odd miles
	return (1+miles+2*min_moves(miles/2));
	else if(miles%2==0)
	return (1+miles+min_moves(miles/2)+min_moves(miles/2-1));

}
int max_moves(int n)
{
	return ((((n+1)*(n+2))/2)-1);
}



/// bottom up dp
	int a[31];
void bottom_up()
{
a[0]=0;
a[1]=2;
for(int i=2;i<=30;i++)
{
	if(i%2==0)
	a[i]=1+i+a[i/2]+a[i/2-1];
	else
	a[i]=1+i+2*a[i/2];
}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,miles;
		cin>>n>>miles;
		int max=max_moves(n);
		 bottom_up();
		//int min=min_moves(n);
		//
		int min=a[n];
	///	cout<<min<<endl;
	///	cout<<max<<endl;
		if(miles<=max && miles>=min)// print the max length and unused wire
		cout<<"0\n";
		else if(miles>max)
		cout<<miles-max<<endl;
		else if(miles<min)
		cout<<"-1\n";
	}

}
