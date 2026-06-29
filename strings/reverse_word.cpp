/*
Reverse word
Time complexity:O(n)
Space complexity:O(n)
*/
#include <bits/stdc++.h>
using namespace std;
string reverse_word(string &s)
{
    string ans;
    reverse(s.begin(),s.end());
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        string word="";
        while(i<n && s[i]!=' ')
        {
            word+=s[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(word.length()>0)
        {
            ans+=" "+word;
        }
    }
    return ans.substr(1);
}
int main()
{
   string test="Om Gaikar";
   string ans =reverse_word(test);
   cout<<"The reversed word is: ";
   for(char ch:ans)
   {
      cout<<ch; 
   }
    return 0;
}