#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int MAXN=100005;
long long a[MAXN];
long long f[MAXN<<2];

long long read(long long &x)//因为第一次交超时了emm，特意加上快读最后发现bug好像出在维护上
{
    long long f=1;char ch=getchar();

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

int readline(int &x)//没有任何亮点的读入优化
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

void build(int root,int left,int right)//线段树常规操作
{
    if(left==right)
    {
        f[root]=a[left];//可以在这里读入！但是我懒得要死当然不会改了
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

    if(right-left+1==f[root])//！！！！！！！就是这里！这两行就是简短而又鸡汁的小优化
        return;

    if(left==right)
    {
        f[root]=sqrt(f[root]);//作为小萌新只会加减的区间维护，然鹅前面的优化已经够卡入时限啦！200ms解决
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
long long query(int root,int left,int right,int qleft,int qright)//第二wa在这里写的int
{
    long long ans=0;

    if(qleft<=left&&right<=qright)
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

            if(y<x)//多看几眼题目
            {
                int b=x;
                x=y;
                y=b;
            }

            if(way==1)
            {
                //cout<<"afs"<<endl;
                printf("%lld\n",query(1,1,n,x,y));
            }
            else if(way==0)
            {
                update(1,1,n,x,y);
            }
        }

        printf("\n");//这输出格式绝了
    }
}