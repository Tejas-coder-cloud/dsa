/*
Find longest common prefix among an array of strings
Time complexity:O(NlogN * M)
Space complexity:O(logN+M)
 */
#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>&s)
{
    if(s.empty())
    {
        return "";
    }
    string result="";
    sort(s.begin(),s.end());
    string first=s[0],last=s.back();
    for(int i=0;i<first.length();i++)
    {
        if(i>=last.length() || first[i]!=last[i])
        {
            break;
        }
        result+=first[i];
    }
    return result;
}
int main()
{
    vector<string> test={
        {"club"},
        {"clown"},
        {"college"}
    };
    string ans=longestCommonPrefix(test);
    cout<<"The longest common prefix is given as: "<<ans<<endl;
    return 0;
}