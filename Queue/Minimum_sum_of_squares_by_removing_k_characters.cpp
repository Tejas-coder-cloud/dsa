/*
Minimum sum of squares of character counts in a given string after removing k characters
Time complexity:O(n)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int minValue(string &s, int k)
{

    if (k >= s.length())
    {
        return 0;
    }
    int freq[26] = {0};
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            pq.push(freq[i]);
        }
    }
    while (k > 0)
    {
        int max = pq.top();
        pq.pop();
        max--;
        if (max > 0)
        {
            pq.push(max);
        }
        k--;
    }
    int result = 0;
    while (!pq.empty())
    {
        int val = pq.top();
        pq.pop();
        result += val * val;
    }
    return result;
}
int main()
{
    string s="aaab"; int k=2;
    int minimum=minValue(s,k);
    cout<<"The Minimum sum of squares of character counts in a given string after removing "<<k<<" characters: "<<minimum<<endl;
    return 0;
}