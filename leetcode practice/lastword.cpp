#include <bits/stdc++.h>
using namespace std;
int lastword(string s)
{
    int count = 0;
    if (s.length() == 0)
    {
        return 0;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            count++;
        }
        else if (count > 0)
        {
            break;
        }
    }
    return count;
}
int main()
{
    string name = " Tejas Dhatrak";
    int ans = lastword(name);
    cout << " The lenght of the last word is: " << ans;
    return 0;
}
/* Time complexity: O(n)
Space complexity: O(1)
*/