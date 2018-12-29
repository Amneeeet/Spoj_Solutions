
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
const int N=100005;
ll  lazy[4*N];
ll  seg[4*N];
// this is the worst size of the segment tree
//***********************************************************************************************************************************



// WITH LAZY PROPAGATION  NOW ITS TIME TO IMPOROVE THE COMPLEXTIY
void update(int low,int high,int lq,int hq,int pos,long long int val)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(high!=low)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>hq || high<lq)
    return;
    if(lq<=low && high<=hq)
    {
        seg[pos]+=(high-low+1)*val;
        if(high!=low)
        {
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
        }
    int mid=(low+high)>>1;
    update(low,mid,lq,hq,2*pos+1,val);
    update(mid+1,high,lq,hq,2*pos+2,val);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
 








  


ll query(int low,int high,int lq,int hq,int pos)
{
    if(lazy[pos]!=0)
    {
        seg[pos]+=(high-low+1)*lazy[pos];
        if(high!=low)
        {
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>hq || high<lq)
    return 0;
    if(lq<=low && high<=hq)
    {
        return seg[pos];
    }
    int mid=low+high>>1;
   return query(low,mid,lq,hq,2*pos+1)+query(mid+1,high,lq,hq,2*pos+2);
}


//*************************
// Driver program to test above functions 
int main() 
{ 
int t;cin>>t;
while(t--)
{
int n,q;
cin>>n>>q;
memset(seg,0,sizeof(seg));
memset(lazy,0,sizeof(lazy));
            int  type,x,y;
            ll val;
            
while(q--)
        {
            scanf("%d",&type);
            //printf("%dhh\n",type);
            if(type)
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",query(0,n-1,x-1,y-1,0));
            }
            else
            {
                scanf("%d %d %lld",&x,&y,&val);
                update(0,n-1,x-1,y-1,0,val);
            }
        }

}} 