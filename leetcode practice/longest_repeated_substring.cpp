#include<bits/stdc++.h>
using namespace std;
int LengthOfLongestRepeatingSubstring(string s)
{
    unordered_map<char,int> mp;
    int left=0;
    int maxlength=0;
    for(int right=0;right<s.length();right++)
    {
        if(mp.count(s[right]) && mp[s[right]]>=left)
        {
            left=mp[s[right]]+1;
        }
        mp[s[right]]=right;
        maxlength=max(right-left+1,maxlength); 
    }
    return maxlength;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="aaaa";
    cout<<"Maximum length of substring with no repeating characters is: "<<LengthOfLongestRepeatingSubstring(s);
    return 0;
}
