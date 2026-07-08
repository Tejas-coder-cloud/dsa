/*
Valid palindrome 
Time complexity:O(n)
Space complexity:O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool  isAlpnum(char ch)
    {
        if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z'))
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start=0, end=s.length()-1;
        while(start<end)
        {
            if(!isAlpnum(s[start]))
            {
                start++;
                continue;
            }
              if(!isAlpnum(s[end]))
            {
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
int  main()
{
    Solution sol;
    cout<<"String is palindrome: "<< sol.isPalindrome("Naman");
    return 0;
}