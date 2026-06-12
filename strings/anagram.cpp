/*
Check whether t is an anagram of s
Time complexity:O(n+m)
Space complexity:O(1)
Here it is guaranteed that both s and t consist of lowercase english characters
*/
#include<bits/stdc++.h>
using namespace std;
bool anagram(string s, string t)
{
    if(s.length()!=t.length())
    {
        return false;
    }
    int count[26]={0};
    for(int i=0;i<s.length();i++)
    {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s="abcd",t="cdab";
    bool ans=anagram(s,t);
    if(ans)
    {
        cout<<t<<" is an anagram of "<<s<<endl;
    }
    else
    {
        cout<<t<<" is not an anagram of "<<s<<endl;
    }
    return 0;
}