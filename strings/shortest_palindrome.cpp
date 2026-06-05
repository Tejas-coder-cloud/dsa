#include<bits/stdc++.h>
using namespace std;
vector<int> computelps(string s)
{
    int len=s.length();
    vector<int> lps(len,0);
    for(int i=1;i<len;i++)
    {
        int j=lps[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j=lps[j-1];
        }
        if(s[i]==s[j])
        {
            j++;
        }
        lps[i]=j;
    }
    return lps;
}
string shortest_palindrome(string s)
{
    int n=s.length();
    string rev=s;
    reverse(rev.begin(),rev.end());
    string temp=s+'#'+rev;
    vector<int> lps = computelps(temp);
    int len=lps.back();
    string suffix=s.substr(len);
    reverse(suffix.begin(),suffix.end());
    return suffix+s;
}
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"Shortest palindromic string is as follows: "<<shortest_palindrome(s);
    return 0;
}