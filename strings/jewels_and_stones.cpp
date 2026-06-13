/*
Count the number of jewels in stones 
J= length of jewels
S= length of stones
Time complexity:O(J+S)
Space complexity:O(1)
 */
#include <bits/stdc++.h>
using namespace std;
int numJewelsInStones(string jewels, string stones)
{
    unordered_set<char> s;
    for (int i = 0; i < jewels.length(); i++)
    {
        s.insert(jewels[i]);
    }
    int count = 0;
    for (int i = 0; i < stones.length(); i++)
    {
        if (s.find(stones[i]) != s.end())
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string jewels = "aA", stones = "aaaaaBBBB";
    int ans = numJewelsInStones(jewels, stones);
    cout << "The number of jewels in stone are: " << ans << endl;
    return 0;
}