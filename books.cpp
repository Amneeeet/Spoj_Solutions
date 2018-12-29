#include <bits/stdc++.h>
#define ll int
using namespace std;
int main() 
{
    ll pages,people;
    int t;cin>>t;while(t--)
    {
        ll sum=0,low=0;
        cin>>pages>>people;
        ll a[pages+1];
        for(int i=0;i<pages;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>low)
        low=a[i];}
        ll high=sum;
        while(low<high)
        {
            ll mid=low+(high-low)/2;
            // check the how many peoples handle this baby
            ll current_load=0,required=0;
            for(int i=0;i<pages;i++)
            {
                if(current_load+a[i]<=mid)
                current_load+=a[i];
                else{
                required++;current_load=a[i];}

            }
           // cout<<mid<<endl;
            if(required<people)
            high=mid;
            else
            low=mid+1;

        }
       // cout<<high<<endl;  we get our answer


        // its time for the partition the array
        int check[pages+1];
        memset(check,0,sizeof(check));
     ll pos=pages-1;
     ll persons=0;
        while(pos>=0)
        {
            ll current_load=0;
        while(pos>=0 && current_load+a[pos]<=high)
        {
            current_load+=a[pos];
            pos--;

        }
        if(pos>=0) check[pos]=1;
        persons++;

        }
    /// now actually 3 peoples required
    int m=pages;
    
    for(int i=0;i<=pages-2 && persons<people;i++)/// slash hamesha jine persons va usto ghat hou if persons==peole aya then exit baby
    {
        if(check[i]!=1){
        check[i]=1;
        persons++;}
    }
    
    for(int i=0;i<pages;i++)
    {
        int flag=check[i];
        cout<<a[i]<<" ";
        if(check[i]==1)
        cout<<"/ ";
    }
    cout<<endl;
    
    

       
        }

    }









