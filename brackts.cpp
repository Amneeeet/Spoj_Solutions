#include <bits/stdc++.h>
using namespace std;
 
/*Structure that is used to
store value*/
struct node
{
    int unmatched_open;
    int unmatched_closed;
};
 
node tree[4*50010];
char arr[50010];
 
/*This function is used to build the
segment tree*/
void build(int index,int start,int end)
{
    if(start == end)
    {
    	if(arr[start]=='(')
    	 tree[index].unmatched_open=1, tree[index].unmatched_closed=0;
    	 else
    	 tree[index].unmatched_open=0, tree[index].unmatched_closed=1;
    }
    else
    {
        int mid = (start+end)/2;
        build(2*index+1,start,mid);
        build(2*index+2,mid+1,end);
 
        /*Note how we use the array to access the left
        and right subtree*/
      int new_match=min(tree[2*index+1].unmatched_open,  tree[2*index+2].unmatched_closed);
     tree[index].unmatched_open=tree[2*index+1].unmatched_open+tree[2*index+2].unmatched_open-new_match;
     tree[index].unmatched_closed=tree[2*index+1].unmatched_closed+tree[2*index+2].unmatched_closed-new_match;
    }
}
 
/*this function is used to return the result
for each query*/
node query(int index,int start,int end,int l,int r)
{
 node result;
    if(l<=start && end<=r)
        return tree[index];
 
    int mid = (start+end)/2;
    node left = query(2*index+1,start,mid,l,r);
    node right = query(2*index+2,mid+1,end,l,r);
    // main logic
      int new_match=min(left.unmatched_open,right.unmatched_closed);
     result.unmatched_open=left.unmatched_open+right.unmatched_open-new_match;
     result.unmatched_closed=left.unmatched_closed+right.unmatched_closed-new_match;
     
     
     
     return result;
 
}

///***************************************************************************
void update(int index, int lo, int hi, int st, char value) 
{
	
    if (lo == hi) 
    {
       	if(value=='(')
    	 tree[index].unmatched_open=1, tree[index].unmatched_closed=0;
    	 else
    	 tree[index].unmatched_open=0, tree[index].unmatched_closed=1;
    }
    else
    {
       int mid = (lo + hi) / 2;
      if(st<=mid)
      update(2 * index+1, lo, mid , st, value);
      else
      update(2 * index+2 , mid+1, hi, st, value);
      
   int new_match=min(tree[2*index+1].unmatched_open,  tree[2*index+2].unmatched_closed);
   tree[index].unmatched_open=tree[2*index+1].unmatched_open+tree[2*index+2].unmatched_open-new_match;
   tree[index].unmatched_closed=tree[2*index+1].unmatched_closed+tree[2*index+2].unmatched_closed-new_match;
  
  
  
  }
}
 
int main()
{
	    int n,m,a,b,type;
	for (int t = 1; t <= 10; ++t) {
		scanf("%d", &n);
		scanf("%s", arr);
        build(0,0,n-1);// build the segment tree
 printf("Test %d:\n", t);
    scanf("%d",&m);
 
    for(int i=0; i<m; ++i)
    {
        scanf("%d",&type);
        if(type!=0)
        {
        --type;
	    arr[type] = (arr[type] == '(') ? ')' : '(';	
	    update(0,0,n-1,type,arr[type] ); 
        }
        else
        {
        	node result=query(0,0,n-1,0,n-1);
        	if(result.unmatched_open==0  && result.unmatched_closed==0)
        	printf("YES\n");
            else
            printf("NO\n");
        }

    }
	}
    return 0;
}
 