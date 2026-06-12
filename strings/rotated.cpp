/*
Check whether t is a rotated version of s
Time complexity:O(n)
Space complexity:O(n)
*/
#include<bits/stdc++.h>
using namespace std;
bool rotated_version(string s, string t)
{
    if(s.length()!=t.length() || s.empty())
    {
        return false; 
    }
    string temp=s+s;
    return temp.find(t)!=string::npos;
}
int main()
{
    string s="abcd",t="cdab";
    bool ans=rotated_version(s,t);
    if(ans)
    {
        cout<<t<<" is a rotated version of "<<s<<endl;
    }
    else
    {
        cout<<t<<" is not a rotated version of "<<s<<endl;
    }
    return 0;
}