/*
Find the minimum number of flips to make an alternating binary string
Time complexity:O(n)
Space complexity:O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int minimumFlips(string &s)
{
    int flippattern1=0;
    int flippattern2=0;
    for(int i=0;i<s.length();i++)
    {
        char expectedPattern1=i%2==0?'0':'1';
        char expectedPattern2=i%2==0?'1':'0';
        if(s[i]!=expectedPattern1)
        {
            flippattern1++;
        }
         if(s[i]!=expectedPattern2)
        {
            flippattern2++;
        }
    }
    return min(flippattern1,flippattern2);
}
int main()
{
    string s = "0011";
    int ans=minimumFlips(s);
    cout<<"The minimum flips required are: "<<ans<<"\n";
    return 0;
}