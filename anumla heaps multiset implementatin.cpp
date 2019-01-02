#include<bits/stdc++.h>
using namespace std;
#define N 16

int b[1<<N], c[1<<N];// for the input and the all combinations
int a[N];// for the final answers


int main()
{
	int t;cin >>t;
	while(t--)
	{
		int n;
	   cin>>n;
	   int po=pow(2,n);
	   //long a[po];
	   for(int i=0;i<po;i++)
	   cin>>b[i];
	   sort(b,b+po);
	   multiset<int> s;// for the expected value bro  all the sums bro
	   
//*****************************************************************************************//	   
	   // In multiset multiple elements have the same value  so thats why we used this
	   
	   
	   int p=0,f=0;
	   for(int i=1;i<po;i++)// frst value is zero ignore it bro
	   {
	   	auto expected_value=-1;
	   	if(!s.empty())
	   	expected_value=*s.begin();
	   	if(expected_value==b[i])
	   		s.erase(s.begin());
	   else
	   {
	   	a[f]=b[i];
	   	int till=p;
	   	for(int i=0;i<till;i++)
	   	{
	   	c[p]=c[i]+a[f];
	   	s.insert(c[p]);
	   	p++;
	   	}
	   	c[p]=a[f];
	   	f++;p++;
	   	
	   }
	   		
	   	
	   	
	   }
	   for(int i=0; i<f; i++) printf("%d ", a[i]);
       printf("\n");
	   
	   
	}
}