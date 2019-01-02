/*
GREAT EXPLANATION 2 BUCKETS  LEFT AND RIGHT
LEFT  RIGHT
5      6
4      7
2      8
1      9


LIKE TSIS  LEFT HAS ALL THE ELEMENTS LESS THEN THE MEDIAN AND RIGHT HAS ALL THE ELEMENTS GREATER THAN THE MEDIAN
*/

/*
===================================================
RMID2
===================================================*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
#define pql priority_queue<int , vector<int> , less<int> > // descending order
#define pqg priority_queue<int , vector<int> , greater<int> >// ascending order
int cut_it(pql &left, pqg &right,int median)
{
	if(!left.empty() && !right.empty() &&  median == left.top() && median == right.top()){
            if(left.size() < right.size())
                right.pop();
            else 
                left.pop();
        }
        else if(!left.empty() && median == left.top())
            left.pop();
        else if(!right.empty() && median == right.top())
            right.pop();
            
        if((left.size() ==0) && (right.size() == 0)){
            return 0;
        } else if(left.size() == right.size()){
            return left.top();
        } else if(left.size() < right.size()){
            return right.top();
        } else if(left.size() > right.size()){
            return left.top();
        }
}

int get_median(int stream , int med , pql &left , pqg &right){
    int median = med;// last median
    
    if(stream == -1)
    return (cut_it(left,right,median));
    
    int balance = left.size() - right.size(); 
    
    ////////////////////////////////////////////////////////////////////////////////
    //	BALANCE THE PIORITY QUEUES
    
  /*  1. balance means  2 buckets have the same numbers   so, as we know left has all smaller and right has all larger
   than median
   so if smaller comes push into left else push into right
   */
    if(balance == 0){
        if(stream < median){
            left.push(stream);
            median = left.top();
        } else{
            right.push(stream);
            median = right.top();
        }
    }
    
   /*  2. (balance>0) means left has the more elements   so if the n is smaller than left then left's top push into right
    and n push into left so that' why it will be balanced
   */  
    
    else if(balance > 0){
        if(stream < median){
            right.push(left.top());
            left.pop();
            left.push(stream);
        } else{
            right.push(stream);
        }
        median = min(left.top() , right.top());
    } 
    
    /*
    3. if right has the lrger elements than the left so if the elemtn come less than the previus median so push into left
    else  ifbigger than push teh right's top into the left then push n into right
    	DONE
    */
    else if(balance <  0){
        if(stream < median){
            left.push(stream);
        } else{
            left.push(right.top());
            right.pop();
            right.push(stream);
        }
        median = min(left.top() ,  right.top());
    }
    return median;
}
int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        pql left;
        pqg right;
        int n;
        int median = 0;
        while(true){
            scanf("%d" , &n);
            if(n == 0){
                break;
            }
            if(n == -1)
                printf("%d\n", median);
            median = get_median(n , median , left , right);
            // last median 
            // os if minus -1 comes than just print the median bro
                    }
    }
    return 0;
}