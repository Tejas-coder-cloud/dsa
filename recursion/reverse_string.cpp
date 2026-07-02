// time complexity:O(n)
//space complexity:O(n)
#include<bits/stdc++.h>
using namespace std;
void reverse(string s,int index)
{
    if(index<0)
    {
        return;
    }

    cout<<s[index]<<" ";
    reverse(s,index-1);
}
int main()
{
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int n=s.length();
    reverse(s,n-1);
    return 0;
}
