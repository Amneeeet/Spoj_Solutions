/// anarmica baby
// 0(n) stack based apporoach
#include<bits/stdc++.h>
#define  ul long long
using namespace std;
int main()
{
int freq[29]={0};
string s;
getline(cin,s);
string res="";
stack<char> t;
for(int i=0;i<s.length();i++){
freq[((s[i]-'0')%48)]++;
}
for(int i=0;i<s.length();i++)
{
char value=s[i];
int start=(value-'0')%48;
int flag=0;
int index=0;
for(int j=1;j<start;j++)
{
	if(freq[j]>0){
	index=j;
	flag=1;break;}
}
if(flag==0 && !t.empty())
{
char check=t.top();
int ch=(check-'0')%48;
while(!t.empty() &&  ch<=start)
{
res+=check;
t.pop();
check=t.top();
ch=(check-'0')%48;

}
}

if(!t.empty() && flag==1)
{
char check=t.top();
int ch=(check-'0')%48;
while(!t.empty() &&  ch<=index)
{
res+=check;
t.pop();
 check=t.top();
 ch=(check-'0')%48;

}}
//cout<<start<<"  "<<value<<"  "<<flag<<endl;
if(flag==0){
res+=value;freq[start]--;
}
else{
t.push(value);freq[start]--;}
}
while(t.empty()==false)
{
	char value=t.top();
	res+=value;
	t.pop();
}
cout<<res<<endl;
//..bnrdfnybkzepmluyrhofwnwvfmkdwolvyzrqhuhztvlwjldqmoyxzytpfmrgouymeupxrvpbesyxixnrfbxnqcwgmgjstknqtwrr
//bbbbcggjknqrrwttsmwqnxfrnxixysepvrxpuemyuogrmfptyzxyomqdljwlvtzhuhqrzyvlowdkmfvwnwfohryulmpezkynfdrn


}

