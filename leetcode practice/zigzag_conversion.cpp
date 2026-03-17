#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) 
    {
        int n = s.length();
        if (numRows == 1 || n <= numRows) 
        {
            return s;
        }
        string ans = "";
        int curr = 0;
        while (curr < n) 
        {
            ans += s[curr];
            curr += (numRows - 1) * 2;
        }
        for (int i = 1; i < numRows - 1; i++) 
        {
            curr = i; 
            while (curr < n) 
            {
                ans += s[curr];
                int stepDown = (numRows - (i + 1)) * 2;
                int stepUp = i * 2;
                curr += stepDown;
                if (curr < n) 
                {
                    ans += s[curr];
                    curr += stepUp;
                } else 
                {
                    break; 
                }
            }
        }
        curr = numRows - 1;
        while (curr < n) 
        {
            ans += s[curr];
            curr += (numRows - 1) * 2;
        }
        return ans; 
    }
};
int main()
{
    Solution sol;
    cout<<sol.convert("TejasTHegreat",4);
    return 0;
}