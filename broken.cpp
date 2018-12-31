// Author : Muhammad Rifayat Samee
// Problem : 2852
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")
 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7
 
#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif
 
using namespace std;
int fre[10005];
char str[1000005];
int m;
int main(){
 
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int i,j,k,len;
    while(scanf("%d",&m)&&m){
        getchar();
        gets(str);
        //printf("%s\n",str);
        len = strlen(str);
        int i,j,cur,res;
        i = 0;
        j = 1;
        cur = 1;
        res = 0;
        memset(fre,0,sizeof(fre));
        fre[str[i]]++;
 
        while(j<len){
            //printf("--%c %d\n",str[j],fre[str[j]]);
            if(cur==m){
                if(fre[str[j]]==0){
                    fre[str[i]]--;
                    if(fre[str[i]]==0){
                        fre[str[j]]++;
                        j++;
                    }
                    i++;
                }
                else{
                    fre[str[j]]++;
                    j++;
                }
            }
            else{
                if(fre[str[j]]==0){
                    fre[str[j]]++;
                    j++;
                    cur++;
 
                }
                else{
                    //printf("--\n");
                    fre[str[j]]++;
                    j++;
                }
            }
            //printf("%d %d\n",i,j);
            res = max(res,j-i);
        }
        printf("%d\n",res);
    }
 
 
	return 0;
}
 