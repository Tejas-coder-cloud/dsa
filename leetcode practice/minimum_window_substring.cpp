 /* Minimum window substring 
Time complexity:O(N)
Space complexity: O(K)
*/
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) 
{
    if (s.empty() || t.empty()) return "";
    unordered_map<char, int> targetCount;
    for (char c : t) targetCount[c]++;
    unordered_map<char, int> windowCount;
    int left = 0, right = 0, formed = 0;
    int required = targetCount.size();
    int minLen = INT_MAX, startIdx = 0;
    while (right < s.length()) 
    {
        char c = s[right];
        windowCount[c]++;
        // If the frequency of the current char matches the target frequency
        if (targetCount.count(c) && windowCount[c] == targetCount[c]) 
        {
            formed++;
        }
        // Try to shrink the window from the left
        while (left <= right && formed == required) 
        {
            if (right - left + 1 < minLen) 
            {
                minLen = right - left + 1;
                startIdx = left;
            }
            char leftChar = s[left];
            windowCount[leftChar]--;
            if (targetCount.count(leftChar) && windowCount[leftChar] < targetCount[leftChar]) 
            {
                formed--;
            }
            left++;
        }
        right++;
    }
    return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s="abba",t="ab";
    string ans=minWindow(s,t);
    cout<<"The minimum window substring is: "<<ans<<endl;
    return 0;
}  
