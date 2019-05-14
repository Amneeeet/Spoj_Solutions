#include <bits/stdc++.h>
using namespace std;
#define ll int

struct node
{
	int maxx, second_max;
};
node tree[3*100005];
int arr[100005];
/*This function is used to build the
segment tree*/
void build(int index,int start,int end)
{
    if(start == end){
   	tree[index].maxx=arr[start];
   	tree[index].second_max=INT_MIN;
   	}
   	else{
        int mid = (start+end)/2;
        build(2*index+1,start,mid);
        build(2*index+2,mid+1,end);
 
      tree[index].maxx=max(tree[2*index+1].maxx,tree[2*index+2].maxx);
      tree[index].second_max=min(max(tree[2*index+1].maxx,tree[2*index+2].second_max),max(tree[2*index+2].maxx,tree[2*index+1].second_max));
      // maximum of all
   	}
    }
 
/*this function is used to return the result
for each query*/
node query(int index,int start,int end,int l,int r)
{
	node result;
	result.maxx=result.second_max=-1;
     if(start>=l && end<=r)
      return tree[index];
        
        if(l > end || r < start)
            return result;
        
 
    int mid = (start+end)/2;
    // main logic
   if(l>mid)
     return query(2*index+2,mid+1,end,l,r);
   if(r<=mid)
      return query(2*index+1,start,mid,l,r);
      
    node left=query(2*index+2,mid+1,end,l,r);
    node right=query(2*index+1,start,mid,l,r);
    
    result.maxx=max(left.maxx,right.maxx);
    result.second_max=min(max(left.maxx,right.second_max),max(right.maxx,left.second_max));
    return result;
    
 
}

///***************************************************************************
void update(int index, int lo, int hi, int st, ll value) 
{
            
    if (lo == hi) 
    {
      tree[index].maxx=value;
      tree[index].second_max=INT_MIN;
    }
    else
{
       int mid = (lo + hi) / 2;
      if(st<=mid)
      update(2 * index+1, lo, mid , st, value);
      else
      update(2 * index+2 , mid+1, hi, st, value);
      
      tree[index].maxx=max(tree[2*index+1].maxx,tree[2*index+2].maxx);
      tree[index].second_max=min(max(tree[2*index+1].maxx,tree[2*index+2].second_max),max(tree[2*index+2].maxx,tree[2*index+1].second_max));
      // maximum of all
}
      
}
 
int main()
{
	ios::sync_with_stdio(false);
   int n,q,a,b;
   char ch;
   
   cin>>n;
   for(int i=0;i<n;++i)
      cin>>arr[i];
   build(0,0,n-1);
   cin>>q;
   
   for(int i=0;i<q;++i)
   {
      cin>>ch>>a>>b;
      if(ch=='Q')
      {
         node result = query(0,0,n-1,a-1,b-1);
         cout<<result.maxx+result.second_max<<"\n";
      }   
      else
         update(0,0,n-1,a-1,b);
   }
   return 0;
}

 