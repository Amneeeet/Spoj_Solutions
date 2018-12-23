///                      ******** MATRIX CHAIN MULTIPICATION (DYNAMIC PROGRAMMING)*******
#include<bits/stdc++.h>

using namespace std;



int main()
{
	int n;
    while(scanf("%d",&n)==1)
    {
    int value;
    int color[n][n]={0};
    int smoke[n][n]={0};
 for(int i=0;i<n;i++){
 cin>>value;
 color[i][i]=value;  }
 if(n==2){
 cout<<color[0][0]*color[1][1]<<endl;continue;}
 int j,q;
    for (int d=2; d<=n; d++)/// 2 times
    {
        for (int i=0; i<=n-d; i++)//2 times
        {
            j = i+d-1;
            smoke[i][j] = INT_MAX;

            for (int k=i; k<j; k++)/// 1 time
            {
                /// alculating smoke   (a*b)

                q = smoke[i][k] + smoke[k+1][j] + (color[i][k]*color[k+1][j]);
                if (q < smoke[i][j])
                {
	         	    smoke[i][j] =q;
                }
                //// updaing the color by mixture     (a+b)%100
                color[i][j]=(color[i][k]+color[k+1][j])%100;
            }
        }
    }

    cout<<smoke[0][n-1]<<endl;
    }
    return 0;
}
