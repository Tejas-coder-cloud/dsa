#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        
        // FIX 1: Handle numRows == 1 to avoid infinite loop (step size 0)
        if (numRows == 1 || n <= numRows) {
            return s;
        }

        string ans = "";
        
        // First Row
        int curr = 0;
        while (curr < n) {
            ans += s[curr];
            curr += (numRows - 1) * 2;
        }

        // Middle Rows
        // FIX 2: Change condition to i < numRows - 1 to include the second-to-last row
        for (int i = 1; i < numRows - 1; i++) {
            curr = i;
            bool down = true; // Flag to switch between down-step and up-step
            while (curr < n) {
                ans += s[curr];
                
                // Calculate step based on whether we are going down or up the zigzag
                int stepDown = (numRows - (i + 1)) * 2;
                int stepUp = i * 2;

                // In your original code, you unrolled this logic manually.
                // Here is your original logic fixed:
                curr += stepDown;
                if (curr < n) {
                    ans += s[curr];
                    curr += stepUp;
                } else {
                    break; // optimization
                }
            }
        }

        // Last Row
        curr = numRows - 1;
        while (curr < n) {
            ans += s[curr];
            curr += (numRows - 1) * 2;
        }

        return ans; // FIX 3: Return statement is now inside the function
    }
};
int main()
{
    Solution sol;
    cout<<sol.convert("TejasTHegreat",4);
    return 0;
}