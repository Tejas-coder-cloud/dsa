/*
Edit distance
m=length of string s1
n=length of string s2
Time complexity:O(n*m)
Space complexity:O(n*m)
*/
#include <bits/stdc++.h>
using namespace std;
int editDistance(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i][j - 1],dp[i - 1][j],dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string s = "abce", t = "fghj";
    int ans=editDistance(s,t);
    cout<<"The minimum number of operatios to convert "<<s<<" into "<<t<<" is "<<ans<<endl;
    return 0;
}