#include<iostream>
#include<algorithm>
using namespace std;





string findsum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initialy take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +(str2[i+diff]-'0') +carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());
    return str;
}






// Function to find that number divisble by 9 or not
string check(string str)
{
    int len=str.length();
    string one="1";
    int temp;
    string quotient ="";
    int tempp;
    int res=str[0]-'0';
    for(int i=1;i<len;i++)
    {
    tempp=((res*10)+(str[i]-'0'))%9;
    res=((res*10)+(str[i]-'0'))/9;
    temp=tempp;
    quotient+=to_string(res);
    res=temp;
    }
    if(res==0)
    return quotient;
    else
    return findsum(quotient,one);



}

// Driver code
int main()
{
   while(true)
   {
   	string n;
   	cin>>n;
   	if(n=="-1")break;
   	if(n=="0"){
   	cout<<"0\n";continue;}
   	if(n.length()==1){
   	cout<<"1\n";continue;}
   	cout<<check(n)<<endl;
   }
}
