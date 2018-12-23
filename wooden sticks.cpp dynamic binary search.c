/////////Mdolls


#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
   return  (a.second >=b.second);
}

int main()
{
/// greedy and the binary search
int t;
cin>>t;
while(t--)
 {
int n;cin>>n;
pair<int,int> data[10001];
 for(int i=0;i<n;i++)
  {
       int w,h;
       cin>>w>>h;
       data[i]=make_pair(w,h);

  }

  sort(data,data+n,sortbysec);
  vector<pair<int,int>> lis;
   lis.clear();
  lis.push_back(data[0]);
  for(int i=1;i<n;i++)
  {
  int l=0,r=lis.size()-1, mid;
  while(l<=r)
  {
  	mid=(l+r)/2;
  	if(lis[mid].first<data[i].first)
  	l=mid+1;
  	else
  	r=mid-1;
  }
  if(l==lis.size())// means koi v ni milya
  lis.push_back(data[i]);
  else
  {
  	lis[l].first=data[i].first;
  	lis[l].second=data[i].second;

  }

  }
  cout<<lis.size()<<endl;


  }

 }

