#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> result;
        if (s.empty() || words.empty())
        {
        return result;
        }
        int n = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;
        unordered_map<string, int> counts;
        for (string & w : words)
        { 
            counts[w]++;
        }
        for (int i = 0; i < wordLen; ++i) 
        {
            int left = i, count = 0;
            unordered_map<string, int> window;
            for (int j = i; j <= n - wordLen; j += wordLen) 
            {
                string word = s.substr(j, wordLen);
                
                if (counts.count(word)) 
                {
                    window[word]++;
                    count++;
                    while (window[word] > counts[word]) 
                    {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords) 
                    {
                        result.push_back(left);
                    }
                } 
                else 
                {
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
    string s="Tejas";
    vector<string> word={"Te","ja"};
    vector<int> result=sol.findSubstring(s, word);
    for(int j:result)
    {
        cout<<j;
    }
    return 0;
}