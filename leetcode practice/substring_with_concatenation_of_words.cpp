#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;

        // 1. Build the frequency map for the required words
        unordered_map<string, int> counts;
        for (const string& w : words) counts[w]++;

        // 2. Iterate through all possible starting offsets (0 to wordLen - 1)
        for (int i = 0; i < wordLen; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            // 3. Slide the window across the string
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                
                if (counts.count(word)) {
                    window[word]++;
                    count++;
                    
                    // If we have too many of 'word', slide 'left' to the right
                    while (window[word] > counts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // 4. If window matches total length, we found a concatenation
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Not a valid word, reset the window
                    window.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};
int main() 
{
    Solution sol;
    string s="";
    vector<string> word;
    vector<int> result=sol.findSubstring(s, word);
    for(int j:result)
    {
        cout<<j;
    }
    return 0;
}