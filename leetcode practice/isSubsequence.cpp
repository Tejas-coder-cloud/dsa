#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length()) 
        {
            if(s[i] == t[j]) 
            {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
};
int main()
{
    Solution sol;
    cout<<"S is a ssequence of T: "<<sol.isSubsequence("axhc","abcdef");
    return 0;
}