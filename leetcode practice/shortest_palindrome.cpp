#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    std::string shortestPalindrome(std::string s) {
        std::string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());
        
        // Create the combined string with a separator
        std::string temp = s + "#" + rev_s;
        
        int n = temp.length();
        std::vector<int> lps(n, 0);
        
        // Build the LPS array
        for (int i = 1; i < n; i++) {
            int j = lps[i-1];
            
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j-1];
            }
            
            if (temp[i] == temp[j]) {
                j++;
            }
            
            lps[i] = j;
        }
        
        // lps[n-1] is the length of the longest palindromic prefix
        int match_len = lps[n-1];
        
        // Taking the suffix that needs to be mirrored
        std::string suffix = s.substr(match_len);
        std::reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};
int main()
{
    Solution sol;
    std::cout<<sol.shortestPalindrome("There");
    return 0;
}