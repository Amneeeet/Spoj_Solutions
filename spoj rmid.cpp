#include<bits/stdc++.h>
using namespace std;
//                     **** all about the stl implementation****
int main()
{
	int n;
	vector<int> vc;
	while(scanf("%d",&n)!=EOF)
	{
		if(n!=0 && n!=-1)
		vc.push_back(n);
		if(n==0){
		printf("\n");
		vc.clear();
		goto jump;}
		else if(n==-1)
		{
			if(vc.size()%2!=0)
			{
				printf("%d\n",vc[vc.size()/2]);
				vc.erase(vc.begin()+vc.size()/2);
			}
			else
			{
				
			if(vc[vc.size()/2]<=vc[vc.size()/2-1])
			{
				printf("%d\n",vc[vc.size()/2]);
				vc.erase(vc.begin()+vc.size()/2);
				
			}
			else
			{
			    printf("%d\n",vc[vc.size()/2-1]);
				vc.erase(vc.begin()+((vc.size()/2)-1));
			}
			}
			
		}
		
		
		jump:;
	}
}