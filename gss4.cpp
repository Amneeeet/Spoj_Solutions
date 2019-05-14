#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int MAXN=100005;
long long a[MAXN];
long long f[MAXN<<2];

long long read(long long &x)
{
    long long f=1;
    char ch=getchar();

    x=0;

    while(ch<'0' || ch>'9')
    {
        if(ch=='-')
        f=-1;
        ch=getchar();
    }

    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();

    }
    return x*f;
}

int readline(int &x)
{
    int f=1;char ch=getchar();

    x=0;

    while(ch<'0' || ch>'9')
    {
        if(ch=='-')
        f=-1;
        ch=getchar();
    }

    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }

    return x*f;
}



void build(int root,int left,int right)
{
    if(left==right)
    {
        f[root]=a[left];
        return;
    }

    int mid=(left+right)/2;

    build(2*root,left,mid);

    build(2*root+1,mid+1,right);

    f[root]=f[2*root]+f[2*root+1];
}



void update(int root,int left,int right,int qleft,int qright)
{
    int mid,ans,i;

    
    ///means  j mi iko range vch bar bar update kri jau   ans ta one hi auuu   so 
    // if  sqrt is one   then exit  reutrn krdo isda sqrt len di koi jrurat nahi  bcx we hve the sqrt
    //

                /*
                             1 2 3 4 5

m                           15
                          /    \
                        6        9
                       /  \     / \
                       3   3    4  5
                     /  \
                    1    2

                    // dekhoo  
                    if mi    1 - 3 di range vch update kru then   ans->        

                    ans  ->   1 1 1 4 5
                    now check   childs are  the one 

m                           12
                          /    \
                        3        9
                       /  \     / \
                       2   1    2  5
                     /  \
                    1    1      

                    now  if again i do                 1-3  then   check kro  phir sqrt kruga ans ta same hi ana


                    check  if(high-low+1==seg[index])3-1+1=3     3==3  then return 
                       








                */
    if(right-left+1==f[root])

        return;

    if(left==right)
    {
        f[root]=sqrt(f[root]);
        return;
    }

    mid=(left+right)/2;

    if(qleft<=mid)
    {
        update(2*root,left,mid,qleft,qright);
    }

    if(mid<qright)
    {
        update(2*root+1,mid+1,right,qleft,qright);
    }

    f[root]=f[root*2]+f[root*2+1];
}




long long query(int root,int left,int right,int qleft,int qright)
{
    long long ans=0;

    if(qleft<=left &&  right<=qright)
    {
        return f[root];
    }

    int mid=(left+right)/2;

    if(qleft<=mid)
    {
        ans=query(2*root,left,mid,qleft,qright);
    }

    if(mid<qright)
    {
        ans+=query(2*root+1,mid+1,right,qleft,qright);
    }

    return ans;
}




int main()
{
    int n,i,x,y,j,way,k=0,m;

    while(scanf("%d",&n)!=EOF)//各大OJ的常规操作 不多说
    {

        k++;

        printf("Case #%d:\n",k);

        for(i=1;i<=n;i++)
        {
            read(a[i]);//这里可以放在建树的时候读入
        }

        build(1,1,n);

        readline(m);

        for(i=1;i<=m;i++)
        {

            readline(way);readline(x);readline(y);

            if(y<x)
            {
                int b=x;
                x=y;
                y=b;
            }

            if(way==1)
            {
                printf("%lld\n",query(1,1,n,x,y));
            }
            else if(way==0)
            {
                update(1,1,n,x,y);
            }
        }

        printf("\n");
    }
}