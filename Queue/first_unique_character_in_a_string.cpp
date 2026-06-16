/*
First unique character in a string
Time complexity:O(n) 
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
int unique(string s)
{
    unordered_map<char,int> mp;
    queue<int> q;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(mp.find(s[i])==mp.end())
        {
            q.push(i);
        }
        mp[s[i]]++;
        while(!q.empty() && mp[s[q.front()]]>1)
        {
            q.pop();
        }
    }
    return q.empty()?-1:q.front();
}
int main()
{
    string s="aaa";
    int ans=unique(s);
    if(ans==-1)
    {
        cout<<"There is no unique character in the string\n";
    }
    else
    {
        cout<<"The first unique character is present at index: "<<ans<<endl;
    }
    return 0;
}