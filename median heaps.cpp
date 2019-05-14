/*
Solution for "Weird Function" (www.spoj.com/problems/WEIRDFN)
Algorithm: Priority Queue
*/


/*
1.left is in the descending order adn right is in the ascending order
2. median s always the left.top() if left size is > right size , then check (current value ) >left.top()   
// push into the right else if current value < left .top then push into left .top()


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned L;
L f;
 
 int main(){
     L mod = 1000000007;
      L a,b,c,n,i,tmp,sl,sr,sum;
      int t;
      scanf("%d",&t);
      while(t--){
         priority_queue < int, vector<int> > left;// means descending order defualt
         priority_queue < int, vector<int>, greater<int> > right;/// ascending order by the greater
         // ulta va
         scanf("%llu %llu %llu %llu",&a,&b,&c,&n);
         left.push(1);
         f = 1;
         sl = 1;
         sr = 0;
          sum = 1;
         for(i=2;i<=n;i++)
    {
        
             tmp = left.top();
            // cout<<left.top()<<endl;
             // median is always the left.top() left is in the descending order
            f = a*tmp + (b*i) + c;
            if(f>=mod) f%=mod;
            sum += f;
             if(sl>sr){        
                  if(f<tmp){
                     left.pop();
                     right.push(tmp);// tmp ->left.top()
                     left.push(f);// new small value
                            }
             else 
             right.push(f);
             sr++;
                }
            else{
             tmp = right.top();
             ///cout<<left.top()<<endl;
             if(f>tmp){
                right.pop();
                left.push(tmp);
              //  cout<<left.top()<<endl;
                right.push(f);
                      }
            else left.push(f);
             sl++;
            }
    }
        printf("%llu\n",sum);
    }
    return 0;
}