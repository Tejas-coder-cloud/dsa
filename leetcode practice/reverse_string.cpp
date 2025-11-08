#include<bits/stdc++.h>
using namespace std;
void reverse_string(string &s )
{
    string ans="";
    reverse(s.begin(),s.end());
    for (int  i = 0; i < s.length(); i++)
    {
        string word="";
        while (s[i]!=' ' && i<s.length())
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
    s=ans;
}
int main()
{
    string name=" Tejas Dhatrak ";
    reverse_string(name);
    cout<<" The reversed string is as follows: "<<name.substr(1);
    return 0;
}