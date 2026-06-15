/*
Word Break 
L=maxlen
n=size of s 
Time complexity:O(n*L^2)
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
bool wordBreak(string &s,vector<string> & wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
    int n=s.length();
    int maxLen=0;
    for(string &word:wordDict)
    {
        maxLen=max(maxLen,(int)word.length());
    }
    vector<bool> dp(n+1,0);
    dp[0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=max(0,i-maxLen);j--)
        {
            if(dp[j] && wordSet.count(s.substr(j,i-j)))
            {
                dp[i]=true;
                break;
            }

        }

    }
    return dp[n];
}
int main()
{
    string s="Leetcode";
    vector<string> wordDict={"Leet","code"};
    bool ans=wordBreak(s,wordDict);
    if(ans)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}