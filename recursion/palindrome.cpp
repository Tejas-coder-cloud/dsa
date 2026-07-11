#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int left,int right)
{
    if(left>=right)
    {
        return true;
    }
    if(tolower(s[left])!=tolower(s[right]))
    {
        return false;
    }
    return(s,left+1,right-1);
}
int main()
{
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int n=s.length();
    if(isPalindrome(s,0,n-1))
    {
        cout<<"String is palindrome ";
    }
    else
    {
        cout<<"String is not palindrome";
    }
    return 0;

}