/*
Find the maximum binary odd number
Time complexity:O(N)
Space complexity:O(1)
 */
#include <bits/stdc++.h>
using namespace std;
string maximumBinaryOddNumber(string &s)
{
    int zeroCount=0,oneCount=0;
    for(char ch:s)
    {
        if(ch=='0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }
    string ans="";
    oneCount--;
    ans+=string(oneCount,'1');
    ans+=string(zeroCount,'0');
    ans+="1";
    return ans;
}
int main()
{
    string s="010";
    string ans=maximumBinaryOddNumber(s);
    cout<<"The maximum binary odd number formed is: ";
    for(char ch:ans)
    {
        cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}