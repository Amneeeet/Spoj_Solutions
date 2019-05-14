#include <iostream>
#include <cstdio>
using namespace std;
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
 
/* .................................................................................................................................. */
 
const int N = 10001;
 
struct Seg{
    int ss, ls, rs, ms;
};
Seg T[4*N];
int A[N], n, a, b;
 
#define root 1, 1, n
#define lx (x * 2)
#define rx (lx + 1)
#define lc lx, l, m
#define rc rx, m+1, r
 
void Update(Seg &x, Seg l, Seg r){
    x.ss = l.ss + r.ss;
    x.ls = max(l.ls, l.ss + r.ls);
    x.rs = max(r.rs, r.ss + l.rs);
    x.ms = max(max(l.ms, r.ms), l.rs + r.ls);
}
 
void Build(int x, int l, int r){
 
    if (l == r){
        T[x].ss = T[x].ls = T[x].rs = T[x].ms = A[l];
    }
    else{
        int m = (l + r) >> 1;
        Build(lc), Build(rc);
        Update(T[x], T[x*2], T[x*2+1]);
    }
}
 
Seg _Query(int x, int l, int r){
    if (a <= l && r <= b)
        return T[x];
    else {
        int m = (l + r) >> 1;
        if (b <= m) return _Query(lc); if (m < a) return _Query(rc);
        Seg res; Update(res, _Query(lc), _Query(rc)); return res;
    }
}
 
Seg Query(int low, int right){
    if (low > right) return T[0];
    a = low, b = right;
    return _Query(root);
}
 
int main(){
 
 
    int t;cin>>t;while(t--){
    	cin>>n;
       for(int i=1;i<=n;i++)
        cin>>A[i];
        Build(root);
        
 
        int x1, y1, x2, y2,m; cin>>m;while(m--){
            cin>>x1>>y1>> x2>> y2;
            // two ocnditinos  over lap and the no overlap
            if (y1 < x2)
            printf("%d\n",( Query(x1, y1).rs + Query(y1 + 1, x2 - 1).ss + Query(x2, y2).ls ));
            else 
            printf("%d\n",( max( Query(x2, y1).ms, Query(x1, x2-1).rs + Query(x2, y2).ls, Query(x1, y1).rs + Query(y1+1, y2).ls) ));
        }
    }
 
}