#include <bits/stdc++.h>
#define ll int
using namespace std;
const int N=1000005;
int  seg[4*N];
// this is the worst size of the segment tree
//***********************************************************************************************************************************

void update(int low,int high,int fans_pos,int fans,int pos)
{
    // no overlap
    if(fans_pos<low || fans_pos>high)
    return;
    /// totaly overlap
    if(low == high){
            seg[pos] += fans;
            return;
        }
// add to teh posiiton adn then updare all the values
    // parital overlap
    // update all the positions
int mid=(low+high)/2;
    update(low,mid,fans_pos,fans,2*pos+1);
    update(mid+1,high,fans_pos,fans,2*pos+2);
    seg[pos]=seg[2*pos+1]+seg[2*pos+2];
}
 






ll sum(int low,int high,int lq,int hq,int pos)/// x t y addd krna
{
    // no overlap
    if(low>hq || high<lq)
    return 0;
    /// total overlap
    if(lq<=low && high<=hq)
    {
        return seg[pos];
    }
    /// patial overlap
    int mid=low+high>>1;
   return sum(low,mid,lq,hq,2*pos+1)+sum(mid+1,high,lq,hq,2*pos+2);
}


//*************************
// Driver program to test above functions 
int main() 
{ 
int n,q;
cin>>n>>q;
memset(seg,0,sizeof(seg));
            int  x,y,p,f;
            string type="";
            
while(q--)
        {
            cin>>type;
            if(type=="find")
            {
                scanf("%d %d",&x,&y);/// means x t y fans aai baby
                printf("%lld\n",sum(0,n-1,x-1,y-1,0));
            }
            else
            {
                scanf("%d %d %lld",&p,&f);
                update(0,n-1,p-1,f,0);
            }
        }

}