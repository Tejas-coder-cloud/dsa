/*
Isomorphic string 
Time complexity: O(n)
Space complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int m1[256] = {0};
    int m2[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}
int main()
{
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;
    if (isIsomorphic(s, t))
        cout << "Strings are Isomorphic" << endl;
    else
        cout << "Strings are Not Isomorphic" << endl;
    return 0;
}