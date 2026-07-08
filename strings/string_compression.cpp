#include<bits/stdc++.h>
using namespace std;
int compress(vector<char> &chars)
{
    int idx = 0;
    int n = chars.size();
    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;
        while (i < n && chars[i] == ch)
        {
            i++;
            count++;
        }
        if (count == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++] = ch;
            string str = to_string(count);
            for (char dig : str)
            {
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}
int main()
{
    vector<char> s= {'T','T','T','j','a','a'};
    int ans=compress(s);
    cout<<"The resized version of the character vector is: "<<ans<<endl;
    return 0;
}