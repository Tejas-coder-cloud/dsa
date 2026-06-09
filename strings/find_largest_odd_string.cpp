/*
Find the largest odd string
Time complexity:O(n)
Time complexity:O(n)
*/
#include<bits/stdc++.h>
using  namespace std;
string findLargestOddSubstring(string & s)
{
    int n=s.length();
    for(int i=n-1;i>=0;i--)
    {
        int digit=s[i]-'0';
        if(digit%2==1)
        {
            string result=s.substr(0,i+1);
            int start=0;
            while(start<result.length() && result[start]=='0')
            {
                start++;
            }
            return result.substr(start);
        }
    }
    return "";
}
int main()
{
    string s="247";
    string ans=findLargestOddSubstring(s);
    cout<<"The longest odd substring is: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}