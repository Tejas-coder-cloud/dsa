#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int lenoflongestsubstring(string s)
    {
        int maxlength=0;
        vector<int> last(256, -1);
        int left = 0;
         for (int right = 0; right < s.length(); right++) 
         {
            if (last[s[right]] >= left) 
            {
                left = last[s[right]] + 1;
            }
            last[s[right]] = right;
            maxlength = max(maxlength, right - left + 1);
         }
         return maxlength;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="a";
    Solution sol;
    int ans=sol.lenoflongestsubstring(s);
    cout<<"Maximum length is: "<<ans<<endl;
    return 0;
}